/* Marilla Cuthbert.  Quest-giver for the amethyst brooch. */
#include <library.h>
#include "/d/avonlea/path.h"
inherit CHARS "villager";

void greet(object player, string mess);
void brooch_talk(object player, string mess);
void anne_talk(object player, string mess);

void setup() {
    set_name("marilla");
    set_short("Marilla Cuthbert");
    add_property("determinate", "");
    add_property("unique", 1);
    add_alias(({ "cuthbert", "woman" }));
    set_gender(2);
    set_long("Marilla Cuthbert is a tall, thin woman, with angles and "
        "without curves.  Her dark hair shows some grey streaks and is "
        "always twisted up in a hard little knot behind, with two wire "
        "hairpins stuck through it.  She looks like a woman of narrow "
        "experience and rigid conscience, but there is a saving "
        "something about her mouth which, if it had been ever so "
        "slightly developed, might have been considered indicative of "
        "a sense of humour.\n");

    villager_setup(20);

    load_chat(8, ({
        2, ":straightens the chairs.",
        1, "'We asked Mrs. Spencer to bring us a boy.  A boy would be "
           "some use on the farm.",
        1, "'To despair is to turn your back on God.",
        1, ":looks into the oven.",
        1, "'There's the dinner to get and the cows to see to.",
    }));

    add_respond_to_with(({ "@say", ({ "hello", "hi", "good morning",
        "good afternoon", "good evening" }) }), "#greet");
    add_respond_to_with(({ "@say", ({ "brooch", "amethyst" }) }),
        "#brooch_talk");
    add_respond_to_with(({ "@say", "anne" }), "#anne_talk");
}

void greet(object player, string mess) {
    if (!player) return;
    do_command("say Good afternoon, " + player->query_cap_name() + ".");
}

void anne_talk(object player, string mess) {
    if (!player) return;
    do_command("say She has a tongue in her head, I'll say that for her.  "
        "Matthew's taken a fancy to her, and there's no reasoning with "
        "him.");
}

void brooch_talk(object player, string mess) {
    object *found;

    if (!player || environment(player) != environment()) return;

    found = filter(deep_inventory(player),
        (: $1->query_property("avonlea brooch") :));

    if (!sizeof(found)) {
        do_command("say My amethyst brooch is missing.  It was my "
            "mother's; her seafaring uncle gave it to her.  I left it "
            "on the pincushion on my bureau, and now I can't find it "
            "anywhere.");
        return;
    }

    do_command("emote takes the brooch from " + player->query_cap_name() +
        ".");
    found[0]->dest_me();
    do_command("say Caught in my black lace shawl.  I'd never have "
        "thought to look there.  And I was so sure it had been "
        "taken.");
    do_command("say Thank you, " + player->query_cap_name() + ".");

    if (!LIBRARY->query_quest_done(player->query_name(), BROOCH_QUEST)) {
        LIBRARY->set_quest(player->query_name(), BROOCH_QUEST);
    }
}
