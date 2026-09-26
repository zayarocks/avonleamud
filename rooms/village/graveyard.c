/* rooms/village/graveyard.c
 *
 * The Avonlea graveyard, downhill behind the church.
 */

#include "/domains/avonlea/path.h"

inherit AVONLEA_OUTDOOR;

void setup()
{
	set_brief("The Avonlea graveyard");
	set_long("The graveyard lies behind the church and runs away "
		"downhill in rows, fenced against the cattle.  The old stones "
		"at the top are thin slate, leaning at every angle and furred "
		"over with grey lichen; further down they are newer, upright, "
		"and very white.  The grass between them is kept short, and "
		"somebody has been at the nearer plots with a trowel.  There "
		"is a spade leaning against the fence.  The church is back up "
		"the slope to the south.\n");
	set_light(1);

	add_item("stones", "stone", "graves", "grave", "Slate at the top of "
		"the slope, thin and leaning, the lettering gone soft.  "
		"Granite and marble further down, upright and white.  The "
		"same dozen families over and over, and a good many children "
		"among them.\n");
	add_item("lichen", "Grey-green, growing in rings, and slowly "
		"taking the older names away altogether.\n");
	add_item("grass", "Kept short, and cut with a scythe rather than "
		"grazed.\n");
	add_item("plots", "plot", "The nearer plots have been weeded and "
		"edged, and one has a jam jar of sweet peas on it, not yet "
		"wilted.\n");
	add_item("spade", "A spade with a worn handle, left leaning "
		"against the fence by whoever was last at work here.\n");
	add_item("fence", "Split rails, to keep the cattle out.\n");

	set_listen("Nothing much.  The wind, and crickets in the long "
		"grass by the fence.\n");
	set_smell("Cut grass, and turned earth.\n");

	set_exits(([
		"south" : VILLAGE "church_door",
		"up" : VILLAGE "church_door",
	]));
}
