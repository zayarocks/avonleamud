/* Marilla's amethyst brooch.  Quest item. */
#include "/d/avonlea/path.h"
inherit "/std/object";

void setup() {
    set_name("brooch");
    set_short("amethyst brooch");
    add_adjective("amethyst");
    set_long("An old-fashioned oval brooch containing a braid of fine "
        "hair under glass, framed by a border of very fine amethysts.  "
        "The stones glow a deep violet when the light touches them.  "
        "This is certainly Marilla Cuthbert's most treasured possession, "
        "and she would very much like to have it back.\n");
    set_weight(1);
    set_value(0);
    add_property("avonlea brooch", 1);
}
