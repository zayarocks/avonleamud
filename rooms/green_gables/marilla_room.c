/*
 * Marilla's room.  The amethyst brooch is caught in the black
 * lace shawl in the chest.  "lift shawl" or "shake shawl" finds it.
 */
#include "/d/avonlea/path.h"
inherit "/std/room/basic_room";

int brooch_found;

int do_lift();

void setup() {
    set_short("Marilla's room");
    add_property("determinate", "");
    set_light(65);
    set_zone("green gables");
    set_long("Marilla's bedroom is plain and scrupulously orderly.  A "
        "bureau stands against the wall with a pincushion on it, the bed "
        "is neatly made, and a wooden chest sits at its foot.  A door "
        "leads east to the hall.\n");

    add_item("bureau", "A dark wooden bureau with a pincushion on "
        "top.\n");
    add_item("pincushion", "A pincushion on the bureau.  Something has "
        "been pinned in the middle of it before, but it is empty now.\n");
    add_item("bed", "A neatly made bed.\n");
    add_item(({ "chest", "wooden chest" }), "A wooden chest.  The lid "
        "is not quite shut, and a fold of black lace hangs over the "
        "edge.\n");
    add_item(({ "shawl", "black shawl", "lace shawl", "black lace shawl",
        "lace" }), "Marilla's black lace shawl, folded into the chest.  "
        "The lace is fine and open.\n");

    add_command("lift",  "shawl", (: do_lift() :));
    add_command("shake", "shawl", (: do_lift() :));

    add_exit("east", GG "upstairs_hall", "door");
}

void reset() {
    brooch_found = 0;
}

int do_lift() {
    object brooch;

    if (brooch_found) {
        add_failed_mess("You shake out the black lace shawl, but there "
            "is nothing caught in it.\n");
        return 0;
    }

    brooch_found = 1;
    brooch = clone_object(ITEMS "amethyst_brooch");
    if (brooch->move(this_player()))
        brooch->move(this_object());

    add_succeeded_mess("$N lift$s the black lace shawl out of the chest, "
        "and find$s an amethyst brooch caught by its pin in the lace.\n");
    return 1;
}
