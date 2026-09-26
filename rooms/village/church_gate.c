/* rooms/village/church_gate.c
 *
 * The foot of the knoll, where the track from the road comes up and
 * the horse sheds stand.  Buggies are left here on Sundays.  The
 * church is above, the hall across the yard.
 */

#include "/domains/avonlea/path.h"

inherit AVONLEA_OUTDOOR;

void setup()
{
	set_brief("The church gate");
	set_long("The track comes up off the road and ends here, at a gate "
		"in the spruce hedge, where the ground flattens before it "
		"climbs again.  This is where the buggies stand on a Sunday, "
		"wheel to wheel along the fence, and where the horses are "
		"backed into the open sheds out of the weather.  The ground "
		"is beaten bare and hard.  Above, the church stands white "
		"against the sky; the hall is off to the east, lower and in "
		"want of paint.  The road is back down the track to the "
		"south.\n");
	set_light(1);

	add_item("gate", "A wooden gate in the hedge, standing open, its "
		"top rail worn smooth and grey by hands and by people sitting "
		"on it who ought not to have been.\n");
	add_item("sheds", "horse sheds", "A row of open sheds backing onto "
		"the fence, roofed, floored with trodden earth, and smelling "
		"of hay and horse.  Names have been cut into the posts over "
		"the years, some of them by people now in the graveyard.\n");
	add_item("hedge", "spruces", "A double row of spruces, thin on the "
		"weather side and thick on the other, so the whole hedge "
		"leans a little inland.\n");
	add_item("ground", "Beaten bare and hard by wheels and hooves and "
		"a hundred years of Sunday boots.\n");
	add_item("church", "White above you, up the slope.\n");
	add_item("hall", "Low and grey and shut, off to the east.\n");

	set_listen("The spruces moving, and a loose board somewhere in the "
		"sheds.\n");
	set_smell("Hay, horse, and spruce.\n");

	set_exits(([
		"south" : ROADS "church_road",
		"up" : VILLAGE "church_door",
		"north" : VILLAGE "church_door",
		"east" : VILLAGE "avonlea_hall",
	]));
}
