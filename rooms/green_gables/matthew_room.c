/* rooms/green_gables/matthew_room.c
 *
 * Matthew's room, off the kitchen on the ground floor.  Montgomery
 * never says where he sleeps; a downstairs room behind the kitchen
 * is what a farm of this kind would have, and it suits him.
 */

#include "/domains/avonlea/path.h"

inherit INDOOR_ROOM;

void setup()
{
	set_brief("Matthew's room");
	set_long("A small room off the kitchen, warm from the chimney "
		"that runs up through one wall.  There is a single bed made "
		"up with a grey blanket, a chair with a coat over the back of "
		"it, and a chest of drawers with a looking glass propped on "
		"top that has never once been moved to a better light.  A "
		"pair of Sunday boots stands side by side under the bed, and "
		"a shelf holds an almanac, a seed catalogue and a book about "
		"horses.  The kitchen is west.\n");
	set_light(1);

	add_item("bed", "A single bed, made up tight, with a grey blanket "
		"and one pillow.\n");
	add_item("chair", "coat", "A kitchen chair with a coat over the "
		"back of it, the coat shaped to a stoop.\n");
	add_item("drawers", "chest", "A chest of four drawers, the bottom "
		"one stiff, containing rather less than it might.\n");
	add_item("glass", "looking glass", "mirror", "A small looking "
		"glass propped against the wall in the worst light in the "
		"room, where it has stood for forty years.\n");
	add_item("boots", "Sunday boots, blacked, side by side, toes "
		"out.\n");
	add_item("shelf", "books", "book", "An almanac, a seed catalogue "
		"with the corners turned down, and a book about the care of "
		"horses, read.\n");
	add_item("chimney", "wall", "The kitchen chimney goes up through "
		"the wall here, which is why this is the warmest small room "
		"in the house and why he has it.\n");

	set_listen("The kitchen through the wall, and the chimney "
		"drawing.\n");
	set_smell("Wool, boot blacking, and woodsmoke.\n");

	set_exits(([
		"west" : "kitchen",
	]));
}

