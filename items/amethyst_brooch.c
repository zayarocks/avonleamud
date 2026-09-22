inherit OBJ;
inherit M_GETTABLE;

void setup()
{
   set_id("brooch");
   set_adj("amethyst");
   set_long("An old-fashioned oval brooch containing a braid of fine "
            "hair, surrounded by a border of very fine amethysts.  The "
            "stones glow a deep violet in the light.  A few threads of "
            "black lace are still caught on its pin.\n");
   set_getmsg("$N $vfree $o from the black lace of Marilla's shawl.\n");
}
