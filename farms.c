/* farms.c
 *
 * Virtual room factory for player farmhouses.  Loading
 * /domains/avonlea/farms/<owner>/<room> comes here, because the
 * driver walks up the path looking for a real file.  There is no
 * farms/ directory on disk, and there must not be one.
 */

#define ROOMS ({ "kitchen", "parlour", "hall", "bedroom", "yard", "barn" })

object virtual_create(string arg)
{
	string owner, room;
	object ob;

	if (sscanf(arg, "%s/%s", owner, room) != 2)
		return 0;
	if (member_array(room, ROOMS) == -1)
		return 0;

	ob = new (__DIR__ "farm_room");
	ob->set_farm(owner, room);
	return ob;
}
