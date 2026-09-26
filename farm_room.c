/* farm_room.c
 *
 * One room of a player's farmhouse, created by farms.c with
 * "<owner>/<room>" as a single string argument.
 *
 * Decor comes from farm_d, keyed to owner and room.  Contents are
 * persisted with M_SAVE: the room's inventory is written to
 * /data/avonlea/farms when the last body leaves and restored when
 * the first arrives.  Players are excluded from the save.  Reads
 * and writes are unguarded, as /data is outside the domain.
 */

inherit INDOOR_ROOM;
inherit M_SAVE;
inherit M_ACCESS;

#define SAVE_DIR "/data/avonlea/farms/"

string owner_name;
string room_name;

nosave int restored;
nosave int dirty;

private string decor(string slot)
{
	return (string)(__DIR__ + "farm_d")->query_decor(owner_name, room_name, slot);
}

private string save_file()
{
	if (!owner_name || !room_name)
		return 0;
	return SAVE_DIR + owner_name + "_" + room_name + ".o";
}

private void restore_contents()
{
	string data;

	if (restored || !save_file())
		return;
	restored = 1;

	if (file_size(save_file()) <= 0)
		return;
	data = unguarded(1, (: read_file, save_file() :));
	if (data && strlen(data))
		load_from_string(data, 1);
}

private void save_contents()
{
	if (!save_file() || !dirty)
		return;
	unguarded(1, (: write_file, save_file(), save_things_to_string(1), 1 :));
	dirty = 0;
}

void object_arrived(object ob)
{
	if (!restored)
		restore_contents();
	if (ob && ob->is_body())
		dirty = 1;
}

void object_left(object ob)
{
	if (!sizeof(filter(all_inventory(), (: $1->is_body() :))))
		save_contents();
}

void create(string arg)
{
	if (!arg)
	{
		::create();
		return;
	}
	sscanf(arg, "%s/%s", owner_name, room_name);
	add_save(({ "owner_name", "room_name" }));
	::create();
}

void setup()
{
	string base;
	string paper, carpet, curtains, ornament, trees, view;

	set_light(1);

	if (!owner_name || !room_name)
		return;

	add_hook("object_arrived", (: object_arrived :));
	add_hook("object_left", (: object_left :));

	base = __DIR__ + "farms/" + owner_name + "/";
	paper = decor("paper");
	carpet = decor("carpet");
	curtains = decor("curtains");
	ornament = decor("ornament");
	trees = decor("trees");
	view = decor("view");

	switch (room_name)
	{
	case "kitchen":
		set_brief(capitalize(owner_name) + "'s kitchen");
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
		set_brief(capitalize(owner_name) + "'s hall");
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
		set_brief(capitalize(owner_name) + "'s parlour");
		set_long("The walls are papered in three bands, divided by a "
			"chair rail and a picture rail.  A horsehair sofa stands "
			"against the west wall with two chairs facing, and a round "
			"table between them under a chenille cloth.  A hooked rug "
			"covers the floor.  A photograph hangs over the mantel, "
			"and the mantelshelf is crowded with ornaments.  A sampler "
			"and a motto hang on either side of the door, and an "
			"aspidistra stands by the window.  The hall is west.\n");
		add_item("paper", "The field between the rails is " + paper + ".\n");
		add_item("rug", "The floor is covered with " + carpet + ".\n");
		add_item("curtains", "The curtains are " + curtains + ".\n");
		add_item("mantel", "Among the ornaments is " + ornament + ".\n");
		set_exits((["west" : base + "hall"]));
		break;

	case "bedroom":
		set_brief(capitalize(owner_name) + "'s room");
		set_long("A bedroom under the roof, papered in " + paper + ", "
			"with a high bed, a washstand, and a wardrobe of dark "
			"wood.  The window looks out on " + view + ".  The stair "
			"goes down.\n");
		add_item("paper", "The paper is " + paper + ".\n");
		add_item("window", "The window looks out on " + view + ".\n");
		set_exits((["down" : base + "hall"]));
		break;

	case "yard":
		set_brief("Yard of " + capitalize(owner_name) + "'s farm");
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
		set_brief("Barn at " + capitalize(owner_name) + "'s farm");
		set_long("The barn smells of hay and harness.  The loft is "
			"stacked to the rafters and the stalls stand below.  The "
			"yard is south.\n");
		set_exits((["south" : base + "yard"]));
		break;
	}
}
