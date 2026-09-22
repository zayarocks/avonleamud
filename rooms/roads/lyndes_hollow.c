/* The main road at Lynde's Hollow. */
#include "/d/avonlea/path.h"
inherit "/std/room/outside";

object rachel;

void setup() {
    set_short("main road at Lynde's Hollow");
    add_property("determinate", "the ");
    set_light(100);
    set_zone("avonlea roads");
    set_day_long("The Avonlea main road dips down here into a little "
        "hollow, fringed with alders and ladies' eardrops and crossed by "
        "a brook.  The brook has its source away back in the woods of "
        "the old Cuthbert place, where it is an intricate, headlong "
        "stream with dark secrets of pool and cascade.  By the time it "
        "reaches Lynde's Hollow it is a quiet, well-conducted little "
        "stream, for not even a brook can run past Mrs. Rachel Lynde's "
        "door without due regard for decency and decorum.  Mrs. Lynde's "
        "house stands by the road, and from her kitchen window she can "
        "see everything that passes.  The lane to Green Gables goes "
        "north.\n");
    set_night_long("The road runs down into Lynde's Hollow in the dark, "
        "and the brook sounds under the alders.  A lamp burns in Mrs. "
        "Lynde's kitchen window.  The Green Gables lane leads north.\n");

    add_item(({ "alders", "ladies' eardrops", "eardrops" }),
        "Alders and ladies' eardrops fringe the hollow.\n");
    add_item(({ "brook", "stream" }), "A quiet, well-conducted little "
        "brook.\n");
    add_item(({ "house", "lynde house", "window", "kitchen window" }),
        "Mrs. Lynde's kitchen window looks straight out on the road.\n");

    room_chat(({ 120, 240, ({
        "The brook runs quietly under the alders.",
        "A buggy passes along the road toward Carmody.",
        "A bee drones among the ladies' eardrops.",
    }) }));

    add_exit("north", ROADS "gg_lane", "road");
    /* Future rooms:
     * add_exit("east", ROADS "village_road",      "road");
     * add_exit("west", ROADS "bright_river_road", "road");
     */
}

void reset() {
    if (!rachel) {
        rachel = clone_object(CHARS "rachel");
        rachel->move(this_object(),
            "$N sit$s down at $p kitchen window with $p knitting.");
    }
}
