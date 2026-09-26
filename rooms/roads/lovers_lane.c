#include "/domains/avonlea/path.h"
/* rooms/roads/lovers_lane.c
 *
 * Lover's Lane, the path down from behind the Green Gables orchard
 * into the woods.  Named by Anne, who thought the old name had no
 * scope for imagination in it at all.
 */

inherit AVONLEA + "avonlea_outdoor";

void setup()
{
	set_brief("Lover's Lane");
	set_long("A narrow path winds down from behind the orchard between "
		"wild cherry trees and slim young birches.  Ferns crowd it on "
		"both sides, and overhead the boughs almost meet, so the light "
		"comes green and shifting.  The orchard and the Green Gables "
		"yard lie back to the north; the path runs on downhill to the "
		"south, toward the sound of running water.\n");
	set_light(1);
	
  add_item("ferns", "Ferns grow thick and waist-high on both sides of "
		"the path.\n");
	add_item("birches", "Slim white birches, young enough to bend in "
		"any wind.\n");

	set_exits(([
		"north":GG "yard",
		"south":"dryads_bubble",
	]));
}
