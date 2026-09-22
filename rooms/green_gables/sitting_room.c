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

   add_item("closet", "The sitting-room closet.  On the second shelf "
            "stands a bottle of something deep red.\n");
   add_item("rug", "A round braided rug, made at home.\n");

   set_exits((["south":"kitchen"]));
}
