/* rooms/roads/dryads_bubble.c
 *
 * The spring in the hollow, with the log bridge over the brook.
 * Anne named the spring the Dryad's Bubble.
 */

inherit OUTDOOR_ROOM;

void setup()
{
	set_brief("The Dryad's Bubble");
	set_long("Here in the hollow is a spring of deep, clear, icy water, "
		"set about with smooth red sandstone and rimmed in by great "
		"palm-like clumps of water fern.  Beyond it a log bridge "
		"crosses the brook, and on the far side the ground rises into "
		"a thick grove of spruce.  The lane climbs back north toward "
		"the orchard.\n");
	set_light(1);
	set_weather(1);
	set_weather(1);
	add_item("spring", "The water is so clear you can count the stones "
		"at the bottom, and so cold it aches to drink.\n");
	add_item("bridge", "A single log laid across the brook, worn smooth "
		"in the middle by many crossings.\n");
	add_item("brook", "The brook runs out of the spring and away down "
		"the hollow toward Lynde's Hollow and the road.\n");

	set_exits((["north":"lovers_lane", "south":"haunted_wood"]));
}
