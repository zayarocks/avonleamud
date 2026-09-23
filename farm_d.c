/* farm_d.c
 *
 * Stores each player's farmhouse: which decor fills each slot in
 * each room.  A player who has never decorated gets defaults seeded
 * from their name, so every farm looks finished from the first
 * visit, and no two look alike.
 */

#define SAVE_FILE "/data/avonlea_farms"

/* owner : ([ room : ([ slot : value ]) ]) */
private mapping farms = ([]);

mapping DEFAULTS = ([
	"paper" : ({
		"a small rosebud pattern on cream",
		"dark green with a gold fleur-de-lis",
		"cabbage roses on a trellis of ivy",
		"a sober stripe of claret and buff",
		"trailing honeysuckle on pale blue",
	}),
	"carpet" : ({
		"a Brussels carpet patterned in wreaths",
		"a drugget of faded Turkey red",
		"a rag rug braided in greys and blues",
		"a hooked rug worked with a stag on it",
	}),
	"curtains" : ({
		"heavy crimson rep, looped back with cords",
		"white muslin, starched into stiff frills",
		"figured chintz, washed pale at the folds",
		"dark plush with a deep bullion fringe",
	}),
	"ornament" : ({
		"a pair of Staffordshire dogs",
		"a case of wax fruit under a glass dome",
		"a framed sampler worked by some patient child",
		"a lustre jug of dried honesty and sea-grass",
		"a tinted photograph of somebody very stiff",
	}),
	"trees" : ({ "apple", "cherry", "plum", "pear" }),
	"view" : ({
		"a blue glimpse of sea beyond the fields",
		"the dark line of the spruce woods",
		"the long slope of a clover meadow",
		"the red road winding away toward Carmody",
	}),
]);

private int seed_of(string owner, string room, string slot)
{
	int seed = 0;

	foreach (int c in owner + ":" + room + ":" + slot)
		seed = seed * 31 + c;
	return seed < 0 ? -seed : seed;
}

void create()
{
	restore_object(SAVE_FILE, 1);
}

/* What fills this slot?  The player's choice, or their default. */
string query_decor(string owner, string room, string slot)
{
	string *options;

	if (farms[owner] && farms[owner][room] && farms[owner][room][slot])
		return farms[owner][room][slot];

	options = DEFAULTS[slot];
	if (!options)
		return 0;
	return options[seed_of(owner, room, slot) % sizeof(options)];
}

void set_decor(string owner, string room, string slot, string value)
{
	if (!farms[owner])
		farms[owner] = ([]);
	if (!farms[owner][room])
		farms[owner][room] = ([]);
	farms[owner][room][slot] = value;
	save_object(SAVE_FILE, 1);
}

void clear_decor(string owner, string room, string slot)
{
	if (farms[owner] && farms[owner][room])
	{
		map_delete(farms[owner][room], slot);
		save_object(SAVE_FILE, 1);
	}
}

mapping query_farm(string owner)
{
	return farms[owner] ? copy(farms[owner]) : ([]);
}
