#include "/domains/avonlea/path.h"
inherit INDOOR_ROOM;

void setup()
{
	set_brief("Anne's room");
	set_long("The whitewashed walls of the east gable are so painfully and "
				"staringly bare that they seem to ache over their own bareness.  "
				"The floor is bare too, except for a round braided mat.  In one "
				"corner is a high, old-fashioned bed with four dark, low-turned "
				"posts.  In the other is a three-cornered table adorned with a "
				"fat red velvet pincushion, and above it hangs a little "
				"six-by-eight mirror.  Midway between the table and the bed is "
				"the window, with an icy white muslin frill over it, and "
				"opposite it stands the washstand.  The hall is to the west.\n");
	set_light(1);

	add_item("window", "Outside, a huge cherry tree grows so close to the "
				"house that its boughs tap against it, and it is so thick with "
				"blossom that hardly a leaf can be seen.  Below is a garden "
				"full of lilac trees, and beyond, a clover field slopes down to "
				"the hollow where the brook runs among white birches.  Past it "
				"is a hill green with spruce and fir, and through a gap you can "
				"see the grey gable end of Orchard Slope.  Off to the left are "
				"the barns, and beyond them a sparkling blue glimpse of sea.\n");
	add_item("pincushion", "A fat red velvet pincushion, hard enough to "
				"turn the point of the most adventurous pin.\n");
	add_item("mirror", "A little six-by-eight mirror.\n");

	set_objects(([CHARS "anne":1]));

	set_exits((["west":"upstairs_hall"]));
}
