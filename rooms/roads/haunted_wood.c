/* rooms/roads/haunted_wood.c
 *
 * The spruce grove between Green Gables and Orchard Slope.  Anne and
 * Diana filled it with imagined ghosts, and then found they could not
 * empty it again.
 */

inherit OUTDOOR_ROOM;

void setup()
{
	set_brief("The Haunted Wood");
	set_long("The spruces grow close here, and their branches shut out "
		"most of the light, so that even at noon the wood is full of "
		"a green gloom.  The ground is soft with fallen needles and "
		"nothing moves but the tops of the trees.  It is a perfectly "
		"ordinary wood, and it would take a determined imagination to "
		"put a white lady in it, or a headless man, or the ghost of a "
		"murdered child that creeps up behind you and lays cold "
		"fingers on your hand.  The log bridge is north; the path "
		"goes on south.\n");
	set_light(1);

	add_item("spruces", "Old spruces, close-grown and dark, their lower "
		"branches long dead.\n");
	add_item("needles", "The fallen needles lie deep enough to swallow "
		"the sound of your own footsteps.\n");

	set_exits((["north":"dryads_bubble", "south":"idlewild"]));
}
