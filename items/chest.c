inherit CONTAINER;
inherit M_OPENABLE;

void setup()
{
   set_relations("in");
   set_default_relation("in");
   set_adj("wooden");
   set_id("chest");
   set_long("A plain wooden chest at the foot of the bed.  The lid is "
            "shut, but a fold of black lace pokes out from under it.\n");
   set_closed(1);
   set_objects((["amethyst_brooch":1]));
}
