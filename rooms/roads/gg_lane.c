#include "/domains/avonlea/path.h"
/* The lane from Green Gables to the main road. */

inherit OUTDOOR_ROOM;

void setup()
{
	set_brief("Lane to Green Gables");
	set_long("A long, deeply rutted lane, bordered with wild-rose bushes, "
				"runs up from the Avonlea road to Green Gables.  Matthew "
				"Cuthbert's father built his homestead as far as he possibly "
				"could from his fellow men without actually retreating into the "
				"woods.  The house lies north, at the very edge of the cleared "
				"land, barely visible from the main road where all the other "
				"Avonlea houses are so sociably situated.  South, the lane meets "
				"the road where it dips into Lynde's Hollow.\n");
	set_light(1);
	set_weather(1);
  set_weather(1);
	add_item("roses", "Wild-rose bushes line both sides of the lane.\n");

	set_exits(([
		"north":GG "yard",
		"south":"lyndes_hollow",
	]));
}
