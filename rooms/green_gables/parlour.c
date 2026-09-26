/* rooms/green_gables/parlour.c
 *
 * The Green Gables parlour: the best room, shuttered, kept for
 * company and consequently almost never used.
 */

#include "/domains/avonlea/path.h"

inherit INDOOR_ROOM;

void setup()
{
	set_brief("Parlour at Green Gables");
	set_long("The parlour is shuttered and cold and has the particular "
		"stillness of a room that is dusted oftener than it is sat "
		"in.  A horsehair sofa stands against the wall with two "
		"chairs facing it and a round table between, and on the table "
		"lies the family Bible with a photograph album beside it.  "
		"There is a hooked rug on the floor, a shell on the mantel, "
		"and over the mantel a picture of a ship.  The blinds are "
		"drawn all the way down, so the light comes in yellow round "
		"the edges of them.  The hall is east.\n");
	set_light(1);

	add_item("sofa", "Black horsehair, buttoned, slippery, and cold "
		"to sit on at any time of year.\n");
	add_item("chairs", "chair", "Two chairs facing the sofa, set "
		"exactly the same distance from it.\n");
	add_item("table", "A round table with a cloth, holding the Bible "
		"and the album and nothing else.\n");
	add_item("bible", "The family Bible, clasped, with a page in the "
		"front for births, marriages and deaths.  The hand changes "
		"twice down the page.\n");
	add_item("album", "A photograph album in tooled leather with a "
		"brass clasp, the pages thick card with oval windows cut in "
		"them.  A good many of the faces have the same chin.\n");
	add_item("rug", "A hooked rug, the colours still good, because "
		"nobody walks on it.\n");
	add_item("shell", "A large pink shell on the mantel, brought from "
		"somewhere warm by somebody who never came back.\n");
	add_item("picture", "ship", "A steel engraving of a ship under "
		"full sail, in a black frame, hanging a little crooked.\n");
	add_item("blinds", "blind", "Drawn to the sill, to keep the sun "
		"off the carpet and the room fit for company.\n");

	set_listen("Nothing.  The stillness is the point of the room.\n");
	set_smell("Cold soot, wax, and a faint sweetness from the "
		"horsehair.\n");

	set_exits(([
		"east" : "front_hall",
	]));
}

