/* rooms/green_gables/cellar.c
 *
 * The cellar under Green Gables, where Marilla keeps her preserves
 * and the raspberry cordial.  Reached by the stairs from the kitchen.
 */

inherit INDOOR_ROOM;

void setup()
{
  set_brief("Cellar at Green Gables");
  set_long("The cellar is cool and dim and smells of earth and apples.  "
			  "Shelves run along one wall, crowded with preserves in glass "
			  "jars, each labelled in Marilla's small hard hand.  A bin of "
			  "last autumn's apples stands in the corner.  The kitchen "
			  "stairs go up.\n");
  set_light(1);

  add_item("shelves", "Rows of preserves: plum, crab-apple, and a dozen "
			  "kinds of jelly, all in their proper order.\n");
  add_item("apples", "A bin of winter apples, a little wrinkled now that "
			  "June has come.\n");

  set_objects((["/domains/avonlea/items/cordial":1]));
  set_exits((["up":"kitchen"]));
}
