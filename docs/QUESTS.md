# Quests in LIMA

How `/daemons/quest_d` works, and what it expects from your code. Everything here applies to any domain; examples use `mydomain` and a quest called `lantern`.

---

## The model

A quest is a **domain**, a **quest name**, and a set of **steps**. Each step is registered separately, under the key `questname:stepname`.

A player's progress is a single string: the name of the step they are currently on. Advancing means replacing that string. The daemon stores the step definitions; the player's body stores which step they're on, in `/std/body/quests.c`.

Two step names are special:

- **`begin`** — `begin_quest()` looks for `questname:begin` by that exact name.
- **`end`** — the `quests` command in `/cmds/player/quests.c` prints "Finished" only when the player's stored step is the literal string `"end"`. Any other value prints "On your way", however many steps have been awarded.

So the shortest working quest is two steps, `begin` and `end`. Intermediate steps can be named anything.

---

## Registering steps

Registration happens in the game, not in code, and persists in the daemon's save file. It requires privileges, so run it as a wizard:

```
eval return QUEST_D->add_quest("mydomain", "lantern:begin", 1, "/domains/mydomain/items/lantern", 0);
eval return QUEST_D->add_quest("mydomain", "lantern:end", 5, "/domains/mydomain/chars/smith", "Returned the smith's lantern");
eval return QUEST_D->set_quest_name("mydomain", "lantern", "The Smith's Lantern");
```

`add_quest(domain, quest, value, base, major_milestone)`:

| Argument | Meaning |
|---|---|
| `domain` | Top-level folder name under `/domains`, which is why a domain is also a quest namespace |
| `quest` | `"questname:stepname"` |
| `value` | Quest points; XP awarded is `QP_TO_XP_RATIO` times this |
| `base` | **The only object file permitted to award this step.** Full path; a trailing `.c` is stripped |
| `major_milestone` | Text for the goals listing, or `0` |

It returns `1` on success and `0` if that key already exists — it won't overwrite. To change a step, delete it first:

```
eval return QUEST_D->delete_quest("mydomain", "lantern:begin");
```

Useful lookups:

```
eval return QUEST_D->query_domain_quests("mydomain");
eval return QUEST_D->query_quests();
eval return QUEST_D->query_quest_names();
```

`set_quest_name(domain, quest, name)` sets the display title. Without it the `quests` command shows the raw quest key.

---

## The base-file rule

Both `begin_quest` and `grant_points` compare `base_name(previous_object())` against the step's registered `base`. If they differ, the call is refused.

This is the single most common reason a quest silently does nothing. Practical consequences:

- The call must sit in the base file itself, or in something that file inherits, such that `previous_object()` still resolves to it.
- `eval` calls made by a wizard come from a temporary object, so they fail this check too — except `grant_points`, which allows privileged callers (`check_privilege(1)`).
- Moving code between files means re-registering the step with the new path.

---

## Starting a quest

```c
#include <daemons.h>

QUEST_D->begin_quest(player, "mydomain", "lantern");
```

`begin_quest(solver, domain, main)` builds the key `main + ":begin"` itself, so you pass the quest name, not the step. Return values:

| Value | Meaning |
|---|---|
| `1` | Started |
| `-1` | No `questname:begin` step registered |
| `0` | Caller isn't the registered base |
| `-2` | The body refused, usually because the quest is already begun |

Calling it repeatedly is safe; `/std/body/quests.c` returns early if the quest key already exists.

### Where to call it from

Parser hooks on objects are the usual trigger, because they fire reliably and sit in the object file:

| Player action | Hook on the object |
|---|---|
| Takes it from a container | `direct_get_obj_from_obj(object ob1, object ob2)` |
| Takes it from the ground | `direct_get_obj(object ob)` |
| Gives it to an NPC | `indirect_give_obj_to_liv(object ob, object liv)` on the NPC |

These hooks belong to **the object being acted on**. A `direct_get_obj_from_obj` defined on the container never fires; it has to be on the thing being taken out. The full set is documented in `/std/object.c`.

Two things to know about them:

- They run **twice** per action, once as a permission check and once for the action itself, so any side effect happens twice. Guard anything that must run once.
- They must `return 1` (or another permitting value) or the action is refused. Returning nothing, or a string, blocks it.

Room-entry triggers are less straightforward: this lib has no `enter_room` or `event_enter` in `/std/base_room.c`, so an object hook is usually the easier hanging point.

---

## Advancing and finishing

```c
QUEST_D->grant_points(player, "mydomain", "lantern", "end", "begin");
```

`grant_points(solver, domain, main, task, prev_task)` awards `main:task`, but only if the player's stored step equals `prev_task`. On success it sets their step to `task`, adds the XP, and prints the "Quest step completed!" banner.

| Value | Meaning |
|---|---|
| `1` | Awarded |
| `-1` | No step registered under `main:task` |
| `0` | Caller isn't the registered base and isn't privileged |
| `-2` | Player's stored step isn't `prev_task` |

A three-step quest chains through the middle names:

```c
QUEST_D->grant_points(who, "mydomain", "lantern", "found", "begin");
QUEST_D->grant_points(who, "mydomain", "lantern", "end", "found");
```

Since progress is one string, a quest can't be on two branches at once. Branching means choosing which step name to write next, and every path that should read as complete must end on `"end"`.

---

## The player's side

`/std/body/quests.c` holds the mapping and offers:

| Function | Use |
|---|---|
| `query_quests()` | The whole mapping: `([ domain : ([ quest : step ]) ])` |
| `quest_task(domain, quest)` | The player's current step |
| `begin_quest(domain, quest, pts)` | Called by the daemon, not directly |
| `update_quest(domain, quest, task, prev_task, pts)` | Called by the daemon |
| `forced_set_quest_task(domain, quest, task)` | Jump a player to a step, for testing |

`forced_set_quest_task` indexes into `quests[domain]` without creating it, so it errors with "Illegal type of index" for a player who has never started anything in that domain. That error is itself a useful signal that `begin_quest` never fired.

There's no function to remove a quest from a player. For repeat testing, either force the step backwards or use a second character.

---

## Testing

```
update /domains/mydomain/items/*.c
update /domains/mydomain/chars/*.c
dest lantern
```

Objects placed by a room's `set_objects` are cloned when a player enters, so leave and re-enter for fresh copies after `dest`.

```
eval return this_body()->query_quests();
quests
```

### When nothing happens

Work outward from the trigger:

1. Put `write("DEBUG: hook fired.\n");` as the first line of the hook. Nothing printed means the hook name or its placement is wrong.
2. If it prints, check `query_quests()`. No entry means `begin_quest` was refused, nearly always the base-file rule.
3. If the quest is listed but won't finish, print the return of `grant_points` and read it off the table above. `-1` is a step-name typo; `0` is the base file; `-2` is a `prev_task` mismatch.
4. If everything returns `1` but `quests` still says "On your way", the final step isn't named `end`.

---

## Checklist for a new quest

1. Decide the domain, quest name and step names, ending on `end`.
2. Decide which file drives each step, since that file is its base and the only thing that can award it.
3. Register the steps with `add_quest`, plus `set_quest_name`.
4. Call `begin_quest` from the first base file, usually in a parser hook.
5. Call `grant_points` from each later base file, naming the step and its predecessor.
6. Test, check `quests`, strip the debug lines.
