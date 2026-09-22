/* The lane from Green Gables to the main road. */
#include "/d/avonlea/path.h"
inherit "/std/room/outside";

void setup() {
    set_short("lane to Green Gables");
    add_property("determinate", "the ");
    set_light(100);
    set_zone("avonlea roads");
    set_day_long("A long, deeply rutted lane, bordered with wild-rose "
        "bushes, runs up from the Avonlea road to Green Gables.  Matthew "
        "Cuthbert's father, as shy and silent as his son, built his "
        "homestead as far as he possibly could from his fellow men "
        "without actually retreating into the woods.  Green Gables sits "
        "at the very edge of the cleared land, barely visible from the "
        "main road, where all the other Avonlea houses are so sociably "
        "situated.  The house lies north; the road at Lynde's Hollow "
        "is south.\n");
    set_night_long("The lane is dark between its wild-rose bushes.  A "
        "lamp shows at Green Gables to the north, and the lane runs "
        "south to the road.\n");

    add_item(({ "rose bushes", "wild roses", "roses", "bushes" }),
        "Wild-rose bushes line the lane.\n");
    add_item(({ "ruts", "lane" }), "The lane is long and deeply "
        "rutted.\n");
    add_item(({ "green gables", "house" }), "The farmhouse stands back "
        "among its orchards at the edge of the cleared land.\n");

    add_exit("north", GG "yard",             "path");
    add_exit("south", ROADS "lyndes_hollow", "road");
}
