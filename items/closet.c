/* items/closet.c
 *
 * The sitting-room closet.  The currant wine stands on the second
 * shelf, where someone in a hurry might easily mistake it for the
 * raspberry cordial.
 */

inherit CONTAINER;

void setup()
{
	set_id("closet");
	set_adj("sitting-room");
	set_relations("in", "on");
	set_default_relation("in");
	set_attached();
	set_long("The sitting-room closet.  The second shelf holds a bottle "
		"of something a deep cheerful red.\n");
	set_objects((["/domains/avonlea/items/currant_wine":1]));
}
