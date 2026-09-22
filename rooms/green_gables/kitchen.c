#include "/domains/avonlea/path.h"
inherit INDOOR_ROOM;

void setup()
{
	set_brief("Kitchen at Green Gables");
	set_long("The kitchen at Green Gables would be a cheerful room if it "
				"were not so painfully clean that it has something of the look "
				"of an unused parlour.  Its windows look east and west.  Through "
				"the west one, which faces the back yard, comes a flood of "
				"mellow June sunlight.  The east window is greened over by a "
				"tangle of vines, and through it you can glimpse the white "
				"cherry trees in the orchard and the slender birches nodding "
				"down in the hollow by the brook.  The table is laid for "
				"supper.  A door leads north to the sitting room, the back "
				"door opens west onto the yard, and a steep staircase goes up "
				"to the gables.\n");
	set_light(1);

	add_item("table", "The table is laid with three plates, a dish of "
				"crab-apple preserves, and one kind of cake.  Company is "
				"expected, but not company of any great importance.\n");
	add_item("vines", "Vines cover the east window so thickly that the "
				"light comes through it green.  Beyond them the orchard is "
		 "white with cherry blossom.\n");

	set_objects(([CHARS "marilla":1]));

	set_exits((["west":"yard", "north":"sitting_room", "up":"upstairs_hall", "down":"cellar"]));
}
