/* items/cordial.c
 *
 * Marilla's raspberry cordial, kept in the cellar.  The right thing
 * to serve Diana Barry at tea.  Taking it begins the cordial quest.
 */

#include <daemons.h>

inherit OBJ;
inherit M_GETTABLE;

mixed direct_get_obj(object ob)
{
	if (this_body())
		QUEST_D->begin_quest(this_body(), "avonlea", "cordial");
	return 1;
}

void setup()
{
	set_id("bottle", "cordial");
	set_adj("raspberry", "red");
	set_long("A bottle of raspberry cordial, a deep cheerful red.  The "
		"label is in Marilla's small hard hand, and reads exactly "
		"what it ought to.\n");
}
