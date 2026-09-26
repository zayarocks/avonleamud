/* rooms/green_gables/spare_room.c
 *
 * The spare room, kept made up for company that seldom comes.
 */

#include "/domains/avonlea/path.h"

inherit INDOOR_ROOM;

void setup()
{
	set_brief("Spare room at Green Gables");
	set_long("The spare room is cold, and smells of camphor and "
		"lavender.  The bed is high and made up to the pillow with a "
		"white counterpane worked in a pattern of grapes, and it is "
		"turned down for nobody.  There is a washstand with a jug and "
		"basin that match, a wardrobe smelling of cedar, and a "
		"braided mat on either side of the bed so that company need "
		"not put a bare foot on a bare board.  The hall is south.\n");
	set_light(1);

	add_item("bed", "High, and made up so smooth that turning it down "
		"would be a decision.\n");
	add_item("counterpane", "White, worked all over in a pattern of "
		"grapes and leaves, and washed until the pattern stands up "
		"stiff.\n");
	add_item("washstand", "jug", "basin", "A washstand with a jug and "
		"basin that match each other, which is more than can be said "
		"for the ones in daily use.\n");
	add_item("wardrobe", "A cedar wardrobe holding four empty hangers "
		"and a summer coat in a bag.\n");
	add_item("mat", "mats", "A braided mat on either side of the bed, "
		"placed so that company need never touch a bare board.\n");
	add_item("window", "The window looks out over the lane and the "
		"road beyond, and the blind is kept halfway down.\n");

	set_listen("Nothing, and rather a lot of it.\n");
	set_smell("Camphor, lavender, and cedar.\n");

	set_exits(([
		"south" : "upstairs_hall",
	]));
}

