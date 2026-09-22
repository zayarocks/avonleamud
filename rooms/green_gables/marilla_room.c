#include "/domains/avonlea/path.h"
/* Marilla's Room  */
/* marilla_room.c */

inherit INDOOR_ROOM;

void enter_room(object who)
{
  if (userp(who))
	 QUEST_D->begin_quest(who, "avonlea", "brooch");
}

void setup()
{
	set_brief("Marilla's room");
	set_long("Marilla's bedroom is plain and scrupulously orderly.  A "
				"bureau stands against the wall with a pincushion on it, the bed "
				"is neatly made, and a wooden chest sits at its foot.  A door "
				"leads east to the hall.\n");
	set_light(1);

	add_item("pincushion", "A pincushion on the bureau.  Something has "
				"been pinned in the middle of it before, but it is empty now.\n");
	add_item("shawl", "Marilla's black lace shawl, folded into the chest.  "
				"The lace is fine and open, the sort that catches on things.\n");

	set_objects(([ITEMS "chest":1]));
	set_exits((["east":"upstairs_hall"]));
}
