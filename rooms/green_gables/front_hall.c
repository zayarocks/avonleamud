/* rooms/green_gables/front_hall.c
 *
 * The front hall, with the front door that is opened about twice a
 * year, and the parlour off it.
 */

#include "/domains/avonlea/path.h"

inherit INDOOR_ROOM;

void setup()
{
	set_brief("Front hall at Green Gables");
	set_long("The front hall is narrow and dim and smells faintly of "
		"floor wax.  The front door is at the end of it, shut, with a "
		"long strip of carpet laid down the middle of the floor and "
		"not a mark on it.  There is a hall stand with a mirror and "
		"an umbrella rack, and above the door a fanlight of plain "
		"glass throws a little light on the ceiling and none anywhere "
		"useful.  The parlour is west and the sitting room east.\n");
	set_light(1);

	add_item("door", "front door", "Painted, shut, and bolted top and "
		"bottom.  It is opened for funerals, for weddings, and for "
		"the minister, and the bolts are stiff from disuse.\n");
	add_item("carpet", "strip", "A strip of carpet down the middle of "
		"the floor, brushed, with the boards either side of it "
		"waxed.\n");
	add_item("stand", "hall stand", "A hall stand of dark wood with a "
		"mirror, two hooks and a drip tray, holding one umbrella and "
		"a good deal of nothing.\n");
	add_item("umbrella", "rack", "A black umbrella in the rack, dry, "
		"and a space where a second one used to be.\n");
	add_item("mirror", "A long mirror in the hall stand, angled to "
		"catch anyone straightening their hat.\n");
	add_item("fanlight", "A half-moon of plain glass over the door, "
		"lighting the ceiling to no purpose whatever.\n");

	set_listen("The clock in the sitting room, faintly, and the front "
		"door not being used.\n");
	set_smell("Floor wax, and cold air coming under the door.\n");

	set_exits(([
		"east" : "sitting_room",
		"west" : "parlour",
	]));
}

