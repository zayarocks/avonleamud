/* rooms/roads/orchard_slope.c
 *
 * The Barry place, home of Diana, her mother, and small Minnie May.
 */

inherit OUTDOOR_ROOM;

void setup()
{
	set_brief("Orchard Slope");
	set_long("The Barry house stands on the slope above its orchards, a "
		"grey-gabled place with a trim garden in front of it and "
		"bee-hives along the fence.  From here you can look back "
		"north over the hollow and see, through a gap in the trees, "
		"the white gable end of Green Gables on its hill.  The path "
		"into the wood goes north.\n");
	set_light(1);
	set_weather(1);
  set_weather(1);
	add_item("house", "A grey-gabled farmhouse, kept as neatly as "
		"Marilla keeps hers, and rather more comfortably.\n");
	add_item("garden", "A trim garden of pinks and sweet-william, with "
		"bee-hives along the fence.\n");
	add_item("green gables", "Far off north, a white gable end showing "
		"through a gap in the trees.\n");

	set_exits((["north":"idlewild"]));
}
