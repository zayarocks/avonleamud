/* rooms/roads/main_road_1.c
 *
 * The Avonlea main road, first stretch east of Lynde's Hollow.
 */

#include "/domains/avonlea/path.h"

inherit AVONLEA_OUTDOOR;

void setup()
{
	set_brief("Avonlea main road");
	set_long("The road climbs out of the Hollow and runs on east "
		"between fields, red and deeply rutted, with a strip of grass "
		"down the middle where the horses' feet miss.  The ditches on "
		"both sides are full of clover and hardhack, and a line fence "
		"of split rails follows the road on the north.  A field of "
		"oats runs down south of it toward the brook.  Back west the "
		"road drops into Lynde's Hollow; east it goes on out of "
		"sight.\n");
	set_light(1);

	add_item("road", "Red and rutted, with grass down the middle.\n");
	add_item("ditch", "ditches", "Full of clover, hardhack, and the "
		"kind of small flowers that only get names from children.\n");
	add_item("fence", "Split rails, silvered with age, following the "
		"road along the north side.\n");
	add_item("oats", "field", "Oats, not yet turned, moving all one "
		"way when the wind comes over.\n");

	set_listen("Wind in the oats, and a crow somewhere behind.\n");
	set_smell("Dust and clover.\n");

	set_exits(([
		"west" : "lyndes_hollow",
		"east" : "main_road_2",
	]));
}
