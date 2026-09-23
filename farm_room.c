/* farm_room.c
 *
 * One room of a player's farmhouse.  farms.c creates it and then
 * calls set_farm() with the owner's name and the room name.  Every
 * changeable detail comes from farm_d, so decorating a room means
 * storing a new value there, not editing this file.
 */

inherit INDOOR_ROOM;

string owner_name;

private string decor(string room, string slot)
{
	return (string)(__DIR__ + "farm_d")->query_decor(owner_name, room, slot);
}

void setup()
{
	set_light(1);
}

void set_farm(string owner, string which)
{
	string base = __DIR__ + "farms/" + owner + "/";
	string paper, carpet, curtains, ornament, trees, view;

	owner_name = owner;

	paper = decor(which, "paper");
	carpet = decor(which, "carpet");
	curtains = decor(which, "curtains");
	ornament = decor(which, "ornament");
	trees = decor(which, "trees");
	view = decor(which, "view");

	switch (which)
	{
	case "kitchen":
		set_brief(capitalize(owner) + "'s kitchen");
		set_long("The kitchen is the warm heart of the house, with a "
			"black range and a scrubbed deal table.  The window over "
			"the sink looks out on the " + trees + " trees.  The hall "
			"is north, and the yard door is out.\n");
		set_exits(([
			"north" : base + "hall",
			"out" : base + "yard",
		]));
		break;

	case "hall":
		set_brief(capitalize(owner) + "'s hall");
		set_long("A narrow hall papered in " + paper + ", with a "
			"hat-stand and a steep stair going up.  The kitchen is "
			"south and the parlour east.\n");
		add_item("paper", "The paper is " + paper + ".\n");
		set_exits(([
			"south" : base + "kitchen",
			"east" : base + "parlour",
			"up" : base + "bedroom",
		]));
		break;

	case "parlour":
		set_brief(capitalize(owner) + "'s parlour");
		set_long("The parlour is the best room, kept for company and "
			"consequently rather cold.  The walls are papered in " +
			paper + ", the floor is covered with " + carpet + ", and "
			"the curtains are " + curtains + ".  On the mantel is " +
			ornament + ".  The hall is west.\n");
		add_item("paper", "The paper is " + paper + ".\n");
		add_item("carpet", "The floor is covered with " + carpet + ".\n");
		add_item("curtains", "The curtains are " + curtains + ".\n");
		add_item("mantel", "On the mantel is " + ornament + ".\n");
		set_exits((["west" : base + "hall"]));
		break;

	case "bedroom":
		set_brief(capitalize(owner) + "'s room");
		set_long("A bedroom under the roof, papered in " + paper + ", "
			"with a high bed, a washstand, and a wardrobe of dark "
			"wood.  The window looks out on " + view + ".  The stair "
			"goes down.\n");
		add_item("paper", "The paper is " + paper + ".\n");
		add_item("window", "The window looks out on " + view + ".\n");
		set_exits((["down" : base + "hall"]));
		break;

	case "yard":
		set_brief("Yard of " + capitalize(owner) + "'s farm");
		set_long("The farmyard lies between the house and the barn, "
			"swept and tidy.  An orchard of " + trees + " trees runs "
			"down the slope, and beyond it you can see " + view + ".  "
			"The kitchen door is in, and the barn is north.\n");
		add_item("orchard", "An orchard of " + trees + " trees.\n");
		set_exits(([
			"in" : base + "kitchen",
			"north" : base + "barn",
		]));
		break;

	case "barn":
		set_brief("Barn at " + capitalize(owner) + "'s farm");
		set_long("The barn smells of hay and harness.  The loft is "
			"stacked to the rafters and the stalls stand below.  The "
			"yard is south.\n");
		set_exits((["south" : base + "yard"]));
		break;
	}
}
