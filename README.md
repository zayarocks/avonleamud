# Avonlea MUD

## Installation
From the lima README: 
```bash
git clone --recurse-submodules https://github.com/limalib/lima -b stable
```

## Running the MUD server
Change the MUD name in in ``adm/dist/config.`` 
```
cd lima/adm/dist
./rebuild
./run
```

Find and kill running instances of FluffOS.
```
pgrep -af 'fluffos|driver'
kill [PID]
```

## Quests

The quest must be registered first from the MUD itself. Here is an example of a simple quest:
```bash
eval return QUEST_D->add_quest("avonlea", "brooch:begin", 1, "/domains/avonlea/items/amethyst_brooch", 0);
eval return QUEST_D->add_quest("avonlea", "brooch:returned", 5, "/domains/avonlea/chars/marilla", "Returned Marilla's amethyst brooch");
eval return QUEST_D->set_quest_name("avonlea", "brooch", "Marilla's Amethyst Brooch");
```

The following code needs to be added to the item itself. Following the same example:
```c
#include <daemons.h>

void mudlib_setup()
{
  ::mudlib_setup();
}

void init()
{
  if (this_body())
    QUEST_D->begin_quest(this_body(), "avonlea", "brooch");
}
```

Mariella can now award quest points. 
```c
void on_receive(object ob)
{
  object giver = this_body();

  do_game_command("say Caught in my black lace shawl!  I'd never have thought to look there.");
  do_game_command("say Thank you.  It was my mother's, and I'd sooner lose anything else I own.");
  if (giver)
    QUEST_D->grant_points(giver, "avonlea", "brooch", "returned", "begin");
  destruct(ob);
}
```

