/* rooms/roads/idlewild.c
 *
 * Anne and Diana's playhouse in a circle of white birches, on the
 * edge of the wood below Orchard Slope.
 */

inherit "/domains/avonlea/avonlea_outdoor";

void setup()
{
	set_brief("Idlewild");
	set_long("A ring of young white birches stands in a little clearing, "
		"and inside the ring somebody has made a playhouse.  Boards "
		"laid from branch to branch serve for shelves, and on them is "
		"a collection of broken china, each piece the more precious "
		"for being broken: bits of a plate with ivy on it, a "
		"cup-handle, a saucer with gilt round the rim.  The wood lies "
		"north, and Orchard Slope is south.\n");
	set_light(1);
	
  add_item("birches", "White birches, planted by nobody, grown in a "
		"ring by pure good fortune.\n");
	add_item("shelves", "Boards laid across the low branches, holding "
		"the china.\n");
	add_item("china", "Broken pieces, arranged with great ceremony.  A "
		"plate with ivy on it, a cup-handle, and a saucer gilt round "
		"the rim.\n");

	set_exits((["north":"haunted_wood", "south":"orchard_slope"]));
}
