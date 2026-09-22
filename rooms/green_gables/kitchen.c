/* The kitchen at Green Gables. */
#include "/d/avonlea/path.h"
inherit "/std/room/basic_room";

object marilla;

void setup() {
    set_short("kitchen at Green Gables");
    add_property("determinate", "the ");
    set_light(80);
    set_zone("green gables");
    set_long("The kitchen at Green Gables would be a cheerful room if it "
        "were not so painfully clean that it has something of the look "
        "of an unused parlour.  Its windows look east and west.  Through "
        "the west one, which faces the back yard, comes a flood of "
        "mellow June sunlight.  The east window is greened over by a "
        "tangle of vines, and through it you can glimpse the white "
        "cherry trees in the orchard and the slender birches nodding "
        "down in the hollow by the brook.  The table is laid for supper.  "
        "A door leads north to the sitting room, and a steep staircase "
        "goes up to the gables.\n");

    add_item(({ "east window", "vines" }), "Vines cover the east window.  "
        "Beyond them the orchard is white with cherry blossom, and the "
        "birches stand in the hollow by the brook.\n");
    add_item("west window", "The west window looks out on the back yard.  "
        "Sunlight pours through it across the floor.\n");
    add_item(({ "table", "plates", "preserves" }), "The table is laid "
        "with three plates, a dish of crab-apple preserves, and one kind "
        "of cake.  Company is expected, but not company of any great "
        "importance.\n");
    add_item("stove", "A black iron cook-stove, well blacked and "
        "polished.\n");
    add_item(({ "staircase", "stairs" }), "A steep, narrow staircase "
        "leading up to the gable rooms.\n");

    room_chat(({ 120, 240, ({
        "The kettle on the stove begins to sing.",
        "A breeze stirs the vines at the east window.",
        "A bird calls from the orchard.",
        "The clock on the shelf ticks.",
    }) }));

    add_exit("west",  GG "yard",          "door");
    add_exit("north", GG "sitting_room",  "door");
    add_exit("up",    GG "upstairs_hall", "stair");
}

void reset() {
    if (!marilla) {
        marilla = clone_object(CHARS "marilla");
        marilla->move(this_object(),
            "$N come$s in from the pantry.");
    }
}
