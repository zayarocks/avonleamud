/* rooms/roads/church_road.c
 *
 * The Avonlea main road below the church knoll.  A grassy track
 * turns off north and goes up to the church gate.  The road runs on
 * east toward the store and Carmody.
 */

#include "/domains/avonlea/path.h"

inherit AVONLEA_OUTDOOR;

void setup()
{
	set_brief("Avonlea main road below the church");
	set_long("North of the road the ground rises to a knoll, and the "
		"white spire of the church stands up out of it above a double "
		"row of spruces.  A grassy track leaves the road here and "
		"climbs that way, two wheel ruts with a ridge of turf between "
		"them.  A horse block stands at the corner where the track "
		"turns off, and the grass around it is worn away.  The road "
		"goes west toward the bridge and east toward the store.\n");
	set_light(1);

	add_item("track", "Two wheel ruts with grass between them, going "
		"up the knoll to the church gate.  Wide enough for a buggy, "
		"and it gets a good many twice on Sunday.\n");
	add_item("spire", "White above the spruces, and straight.\n");
	add_item("knoll", "rise", "A low rise north of the road, with the "
		"church and the hall standing on it behind their hedge.\n");
	add_item("spruces", "hedge", "A double row of them along the crest, "
		"leaning inland.\n");
	add_item("block", "horse block", "A squared granite block, two "
		"steps high, for getting onto a horse or out of a buggy "
		"without a scramble.  The top is dished with use.\n");
	add_item("road", "Red and rutted, running west and east.\n");

	set_listen("The spruces up on the knoll, and the wind coming "
		"across the fields.\n");
	set_smell("Dust, spruce, and clover from the ditch.\n");

	set_exits(([
		"west" : "main_road_2",
		"north" : VILLAGE "church_gate",
	]));
	/* Future: "east" to the store and the road to Carmody. */
}
