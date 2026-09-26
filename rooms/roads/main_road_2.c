/* rooms/roads/main_road_2.c
 *
 * The Avonlea main road, second stretch: the bridge over the brook
 * and the beginning of the birches.
 */

#include "/domains/avonlea/path.h"

inherit AVONLEA_OUTDOOR;

void setup()
{
	set_brief("Avonlea main road at the bridge");
	set_long("The road crosses the brook here on a plank bridge with "
		"a rail down one side only, the other having gone into the "
		"water some years ago and never been replaced.  The brook is "
		"the same one that runs through the Hollow, narrower here and "
		"faster, going under the road and away south between banks of "
		"fern.  White birches stand along the water on both sides.  "
		"The road runs west and east.\n");
	set_light(1);

	add_item("bridge", "planks", "Plank on stringers, with a rail "
		"down the upstream side and nothing at all down the other.  "
		"The planks knock under a wheel, one after another, so you "
		"can hear a buggy cross from a field away.\n");
	add_item("rail", "A single peeled rail, worn pale on top.\n");
	add_item("brook", "water", "Narrow and quick here, running clear "
		"over red stones, with the light off it moving on the "
		"underside of the bridge.\n");
	add_item("birches", "birch", "trees", "White birches, leaning out "
		"over the water from both banks and not quite meeting.\n");
	add_item("fern", "ferns", "Waist-high along the banks, and cool "
		"even at noon.\n");

	set_listen("The brook under the bridge, and the birch leaves, "
		"which never entirely stop.\n");
	set_smell("Water, wet stone, and fern.\n");

	set_exits(([
		"west" : "main_road_1",
		"east" : "church_road",
	]));
}
