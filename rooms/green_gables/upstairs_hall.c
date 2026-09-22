/* Upstairs hall between the gables. */
#include "/d/avonlea/path.h"
inherit "/std/room/basic_room";

void setup() {
    set_short("upstairs hall at Green Gables");
    add_property("determinate", "the ");
    set_light(60);
    set_zone("green gables");
    set_long("A narrow, spotless upstairs hall.  The east gable room opens "
        "to the east, Marilla's room is to the west, and the steep "
        "stairs lead down to the kitchen.\n");

    add_item(({ "stairs", "staircase" }), "The stairs lead steeply down "
        "to the kitchen.\n");

    add_exit("east", GG "east_gable",   "door");
    add_exit("west", GG "marilla_room", "door");
    add_exit("down", GG "kitchen",      "stair");
}
