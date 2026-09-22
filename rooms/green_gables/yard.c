inherit OUTDOOR_ROOM;

void setup()
{
   set_brief("Back yard of Green Gables");
   set_long("The back yard of Green Gables is very green and neat, "
            "bordered on one side by great patriarchal willows and on the "
            "other by prim Lombardy poplars.  Not a stray stick nor stone is "
            "to be seen.  The kitchen door is to the east, and the barns "
            "stand to the north.\n");
   set_light(1);

   add_item("willows", "Great patriarchal willows.\n");
   add_item("poplars", "A row of prim Lombardy poplars.\n");

   set_exits((["east":"kitchen"]));
}
