/* farms.c
 *
 * Virtual room factory for player farmhouses
 * /domains/avonlea/farms/<owner>/<room>
 */

#define ROOMS ({ "kitchen", "parlour", "hall", "bedroom", "yard", "barn" })

object virtual_create(string arg)
{
	string owner, room;

	if (sscanf(arg, "%s/%s", owner, room) != 2)
		return 0;
	if (member_array(room, ROOMS) == -1)
		return 0;

	return new (__DIR__ "farm_room", arg);
}
