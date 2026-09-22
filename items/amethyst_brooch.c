/* items/amethyst_brooch.c
 *
 * Marilla's amethyst brooch, her mother's, lost in the lace of her
 * black shawl in the chest.  Taking it begins the brooch quest;
 * giving it back to Marilla completes it.
 */

#include <daemons.h>

inherit OBJ;
inherit M_GETTABLE;

mixed direct_get_obj_from_obj(object ob1, object ob2)
{
  write("DEBUG: brooch hook fired.\n");
  if (this_body())
    QUEST_D->begin_quest(this_body(), "avonlea", "brooch");
  return 1;
}

void setup()
{
  set_id("brooch");
  set_adj("amethyst");
  set_long("An old-fashioned oval brooch containing a braid of fine "
           "hair, surrounded by a border of very fine amethysts.  The "
           "stones glow a deep violet in the light.  A few threads of "
           "black lace are still caught on its pin.\n");
}
