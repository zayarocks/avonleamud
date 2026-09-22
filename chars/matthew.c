/* Matthew Cuthbert. */

inherit "/domains/avonlea/chars/villager";

void setup()
{
	set_name("Matthew");
	set_gender(1);
	set_proper_name("Matthew Cuthbert");
	set_in_room_desc("Matthew Cuthbert stands near the barns, looking at the ground.");
	set_long("Matthew Cuthbert is an odd-looking personage, with an ungainly "
				"figure and long iron-grey hair that touches his stooping "
				"shoulders.  He has a full, soft brown beard which he has worn "
				"ever since he was twenty.  In fact, he looks at sixty very much "
				"as he looked at twenty, lacking a little of the greyness.  He "
				"is painfully shy, and seems happiest when left alone.\n");

	set_chat_lines(({
		"say Well now, I dunno.",
		"say I'll be sowing the late turnip seed on the hill field.",
		"emote looks down at the ground.",
		"say She's a real interesting little thing.",
	}));
}
