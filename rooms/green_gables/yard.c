/* Back yard of Green Gables. */
#include "/d/avonlea/path.h"
inherit "/std/room/outside";

object matthew;

void setup() {
    set_short("back yard of Green Gables");
    add_property("determinate", "the ");
    set_light(100);
    set_zone("green gables");
    set_day_long("The back yard of Green Gables is very green and neat, "
        "bordered on one side by great patriarchal willows and on the "
        "other by prim Lombardy poplars.  Not a stray stick nor stone is "
        "to be seen.  The kitchen door is to the east, the barns stand "
        "to the north, and the lane runs south toward the road.  Beyond "
        "the orchard a path leads down through the woods to the "
        "brook.\n");
    set_night_long("The back yard of Green Gables lies quiet in the dark.  "
        "The willows and poplars are black against the sky, and lamplight "
        "shows in the kitchen window to the east.  The lane runs south.\n");

    add_item(({ "willows", "willow" }), "Great patriarchal willows.\n");
    add_item(({ "poplars", "lombardy poplars", "lombardies" }), "A row of "
        "prim Lombardy poplars.\n");
    add_item(({ "barns", "barn" }), "The big barns of the Cuthbert "
        "farm.\n");
    add_item(({ "orchard", "cherry trees" }), "The orchard is in full "
        "blossom.\n");
    add_item(({ "path", "woods" }), "A path runs down from behind the "
        "orchard into the woods toward the brook.\n");

    add_exit("east",  GG "kitchen",    "door");
    add_exit("south", ROADS "gg_lane", "path");
    /* Future rooms:
     * add_exit("north", GG "barn",           "path");
     * add_exit("west",  ROADS "lovers_lane", "path");
     */
}

void reset() {
    if (!matthew) {
        matthew = clone_object(CHARS "matthew");
        matthew->move(this_object(), "$N come$s up from the barns.");
    }
}
