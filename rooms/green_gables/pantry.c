/* rooms/green_gables/pantry.c
 *
 * Marilla's pantry off the kitchen.  Everything in its place and a
 * place for everything.
 */

#include "/domains/avonlea/path.h"

inherit INDOOR_ROOM;

void setup()
{
	set_brief("Pantry at Green Gables");
	set_long("The pantry is a narrow room with one small window high "
		"up, cool at all hours.  Shelves run from floor to ceiling on "
		"both sides, holding the everyday dishes on one and the "
		"stores on the other: flour, meal, sugar, tea, and a row of "
		"jars ranked by size.  A marble slab under the window keeps "
		"the butter, and a tin breadbox stands at the end of it.  A "
		"cloth is laid over something on the top shelf.  The kitchen "
		"is north.\n");
	set_light(1);

	add_item("shelves", "shelf", "Scrubbed white pine, lined with "
		"paper cut in points along the edge, and everything on them "
		"in rows with the labels turned out.\n");
	add_item("jars", "jar", "Glass jars sealed with wax, each labelled "
		"in a small hard hand: plum, crab-apple, damson, and a dozen "
		"kinds of jelly.\n");
	add_item("stores", "flour", "meal", "sugar", "Flour and meal in "
		"covered bins, sugar in a crock, and tea in a japanned "
		"caddy.\n");
	add_item("slab", "marble", "A slab of marble under the window, "
		"cold to the hand, with the butter under a cover on it.\n");
	add_item("butter", "Butter in a covered dish, printed on top with "
		"a thistle from the mould.\n");
	add_item("breadbox", "A tin breadbox, dented at one corner, with "
		"two loaves and the heel of a third in it.\n");
	add_item("cloth", "A clean cloth laid over something on the top "
		"shelf.  Whatever is under it is round, and it is not to be "
		"touched before Sunday.\n");
	add_item("window", "One small window, high up, with a screen of "
		"cheesecloth tacked over it against the flies.\n");

	set_listen("Nothing at all.  It is the quietest room in the "
		"house.\n");
	set_smell("Flour, cold butter, and the sweetness off the "
		"preserves.\n");

	set_exits(([
		"north" : "kitchen",
	]));
}

