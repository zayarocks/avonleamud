/* The sitting room.  The closet is a hook for the raspberry cordial. */
#include "/d/avonlea/path.h"
inherit "/std/room/basic_room";

void setup() {
    set_short("sitting room at Green Gables");
    add_property("determinate", "the ");
    set_light(70);
    set_zone("green gables");
    set_long("The sitting room at Green Gables is plainly furnished and "
        "very neat.  Straight-backed chairs stand against the walls, a "
        "braided rug lies on the floor, and there is a closet in one "
        "corner.  The blinds are half drawn against the afternoon sun.  "
        "The kitchen is to the south.\n");

    add_item(({ "chairs", "chair" }), "Plain, straight-backed wooden "
        "chairs.\n");
    add_item(({ "rug", "braided rug" }), "A round braided rug, made at "
        "home.\n");
    add_item(({ "closet", "shelf", "second shelf" }), "The sitting-room "
        "closet.  On the second shelf stands a bottle of something deep "
        "red.\n");
    add_item(({ "blinds", "blind" }), "The blinds are half drawn.\n");

    add_exit("south", GG "kitchen", "door");
}
