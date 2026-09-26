#include "/domains/avonlea/path.h"
/* The main road at Lynde's Hollow. */

inherit AVONLEA + "avonlea_outdoor";

void setup()
{
	set_brief("Main road at Lynde's Hollow");
	set_long("The Avonlea main road dips down here into a little hollow, "
				"fringed with alders and ladies' eardrops and crossed by a "
				"brook.  The brook has its source away back in the woods of the "
				"old Cuthbert place, where it is an intricate, headlong stream "
				"with dark secrets of pool and cascade.  By the time it reaches "
				"Lynde's Hollow it is a quiet, well-conducted little stream, for "
				"not even a brook can run past Mrs. Rachel Lynde's door without "
				"due regard for decency and decorum.  Her house stands by the "
				"road, and from her kitchen window she can see everything that "
				"passes.  The lane to Green Gables goes north.\n");
	set_light(1);
	
  add_item("brook", "A quiet, well-conducted little brook.\n");
	add_item("window", "Mrs. Lynde's kitchen window looks straight out on "
				"the road.  Nothing passes it unnoticed.\n");

	set_objects(([CHARS "rachel":1]));
  set_exits((["north" : "gg_lane", "east" : "main_road_1"]));
}
