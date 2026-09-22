/* rooms/green_gables/sitting_room.c
 *
 * The Green Gables sitting room.  The closet in the corner holds
 * Marilla's currant wine, which looks a great deal like raspberry
 * cordial to anyone in a hurry.
 */

inherit INDOOR_ROOM;

void setup()
{
  set_brief("Sitting room at Green Gables");
  set_long("The sitting room at Green Gables is plainly furnished and "
  "very neat.  Straight-backed chairs stand against the walls, a "
  "braided rug lies on the floor, and there is a closet in one "
  "corner.  The blinds are half drawn against the afternoon sun.  "
  "The kitchen is to the south.\n");
  set_light(1);

  add_item("chairs", "Plain, straight-backed wooden chairs.\n");
  add_item("rug", "A round braided rug, made at home.\n");
  add_item("blinds", "The blinds are half drawn.\n");

  set_objects((["/domains/avonlea/items/closet":1, "/domains/avonlea/chars/diana":1]));

  set_exits((["south":"kitchen"]));
}
