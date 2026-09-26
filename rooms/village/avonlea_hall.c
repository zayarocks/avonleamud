/* rooms/village/avonlea_hall.c
 *
 * Outside the Avonlea hall, across the yard from the church.  Home
 * of the Debating Club, the Sewing Circle, and anything else that
 * wants a roof and chairs.
 */

#include "/domains/avonlea/path.h"

inherit AVONLEA_OUTDOOR;

void setup()
{
	set_brief("Outside the Avonlea hall");
	set_long("The hall stands at the east end of the church ground, "
		"lower than the church and a good deal plainer, its clapboards "
		"gone grey on the weather side where the paint has given up.  "
		"A single door faces the yard, with a bootscraper beside it "
		"and a notice nailed to it.  The windows are shuttered through "
		"the week.  A stack of firewood is piled against the gable "
		"under a sheet of tin.  The gate and the sheds are west.\n");
	set_light(1);

	add_item("hall", "Clapboard, one storey, with a stovepipe through "
		"the roof and no steeple, no porch and no pretensions.\n");
	add_item("notice", "A sheet of paper nailed to the door, cockled "
		"by rain, announcing the next meeting of the Avonlea Debating "
		"Club and the question to be debated.  Somebody has written a "
		"remark underneath it in pencil.\n");
	add_item("remark", "pencil", "Small pencil capitals, quite "
		"legible: NOT IF MRS. LYNDE HAS ANYTHING TO SAY.\n");
	add_item("door", "Plain boards, shut, with a hasp for a padlock "
		"and no padlock in it.\n");
	add_item("bootscraper", "scraper", "An iron blade set in a block "
		"by the door, the edge bright from use.\n");
	add_item("windows", "window", "Shuttered, and the shutters "
		"fastened with a turn button each.\n");
	add_item("firewood", "wood", "Split stove lengths stacked against "
		"the gable under a sheet of tin, for the hall stove in "
		"winter.\n");

	set_listen("The tin over the firewood ticking as it warms.\n");
	set_smell("Cut wood, and dust.\n");

	set_exits(([
		"west" : VILLAGE "church_gate",
	]));
	/* Future: "in" to the hall itself. */
}
