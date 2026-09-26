/* rooms/green_gables/back_porch.c
 *
 * The back porch between the yard and the kitchen door.  Where the
 * boots come off and the milk pails stand.
 */

#include "/domains/avonlea/path.h"

inherit INDOOR_ROOM;

void setup()
{
	set_brief("Back porch at Green Gables");
	set_long("A narrow roofed porch across the back of the house, "
		"boarded on two sides and open to the yard.  A bench runs "
		"along one wall with boots under it, and there are pegs above "
		"for coats and a battered straw hat that nobody has worn in "
		"years.  Two milk pails stand scoured and upside down on a "
		"shelf, and a tin basin hangs by the door with a towel on a "
		"roller beside it.  The kitchen is east and the yard is "
		"west.\n");
	set_light(1);

	add_item("bench", "A plank bench, worn pale, with boots ranged "
		"under it in pairs.\n");
	add_item("boots", "Work boots, one pair much larger than the "
		"other, both scraped clean of the yard.\n");
	add_item("pegs", "peg", "A row of wooden pegs with coats on them, "
		"and at the end a straw hat gone brittle at the brim.\n");
	add_item("hat", "A straw hat, sun-bleached and cracked, kept on "
		"its peg out of habit rather than use.\n");
	add_item("pails", "pail", "Two tin milk pails, scoured to a shine "
		"and set upside down so nothing can get into them.\n");
	add_item("basin", "A tin wash basin on a nail, and a roller towel "
		"beside it worn thin in the middle.\n");
	add_item("towel", "A roller towel, clean, and damp at one end.\n");

	set_listen("The house on one side and the yard on the other, and "
		"a board creaking underfoot.\n");
	set_smell("Wet tin, boot leather, and whatever is cooking "
		"inside.\n");

	set_exits(([
		"east" : "kitchen",
		"west" : "yard",
	]));
}

