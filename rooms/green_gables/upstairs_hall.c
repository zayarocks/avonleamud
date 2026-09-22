inherit INDOOR_ROOM;

void setup()
{
   set_brief("Upstairs hall at Green Gables");
   
   set_long("A narrow, spotless upstairs hall.  Anne's room is east, in the "
            "gable.  Marilla's room is to the west, and the steep stairs "
            "lead down to the kitchen.\n");
   
   set_light(1);

   set_exits((["east":"east_gable", "west":"marilla_room", "down":"kitchen"]));
}
