inherit INDOOR_ROOM;

void setup()
{
   set_brief("Upstairs hall at Green Gables");
   set_long("A narrow, spotless upstairs hall.  The east gable room opens "
            "to the east, Marilla's room is to the west, and the steep "
            "stairs lead down to the kitchen.\n");
   set_light(1);

   set_exits((["east":"east_gable", "west":"marilla_room", "down":"kitchen"]));
}
