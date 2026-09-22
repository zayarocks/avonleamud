/* rooms/green_gables/barn.c
 *
 * The Green Gables barn, north of the yard.  Matthew's proper
 * territory, and the one place at Green Gables that is allowed to
 * be untidy.
 */

inherit INDOOR_ROOM;

void setup()
{
	set_brief("Barn at Green Gables");
	set_long("The barn is dim and warm and smells of hay, harness and "
		"cattle.  Dust turns slowly in the bars of light that come "
		"through the chinks in the boards.  A ladder goes up to the "
		"loft, where the hay is stacked to the rafters; below are the "
		"stalls, the sorrel mare's among them, and Matthew's buggy "
		"stands by the wide door with its shafts down.  The yard is "
		"south.\n");
	set_light(1);

	add_item("loft", "The hay is stacked to the rafters, and the ladder "
		"to it is worn pale where hands and boots have gone up and "
		"down.\n");
	add_item("hay", "Last summer's hay, still green in the middle of "
		"the stack and sweet-smelling.\n");
	add_item("buggy", "Matthew's buggy, the one that fetched a girl "
		"home from Bright River when a boy was expected.\n");
	add_item("mare", "The sorrel mare looks around at you, decides you "
		"are nobody, and goes back to her hay.\n");
	add_item("harness", "Harness hangs on pegs along the wall, oiled "
		"and mended and hung up in its proper order.\n");

	set_exits((["south":"yard"]));
}
