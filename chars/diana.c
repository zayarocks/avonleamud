#include "/domains/avonlea/path.h"
/* chars/diana.c
 *
 * Diana Barry, Anne's bosom friend, come to tea at Green Gables.
 * She will drink whatever red bottle she is given.  The raspberry
 * cordial ends the afternoon happily; the currant wine does not.
 */

#include <daemons.h>

inherit CHARS "villager";

void on_receive(object ob)
{
	object giver = this_body();

	if (ob->id("cordial"))
	{
		do_game_command("say Oh, Anne, it's awfully nice.  Is it your own making?");
		do_game_command("emote drinks a tumblerful, and smiles.");
	}
	else
	{
		do_game_command("emote drinks a tumblerful, and holds out her glass for another.");
		call_out((: do_game_command, "say My, Anne, isn't this splendid stuff?" :), 8);
		call_out((: do_game_command, "emote drinks a third tumblerful, very slowly." :), 16);
		call_out((: do_game_command, "say I feel awful queer.  Everything's going round." :), 26);
		call_out((: do_game_command, "emote sways in her chair and puts a hand to her head." :), 34);
		call_out((: do_game_command, "say I must go right home." :), 44);
		call_out((: do_game_command, "emote walks unsteadily out, holding the wall." :), 50);
		call_out((: destruct(this_object()) :), 54);
	}
	destruct(ob);
}

void setup()
{
	set_name("Diana");
	set_gender(2);
	set_proper_name("Diana Barry");
	set_in_room_desc("Diana Barry sits waiting to be given her tea.");
	set_long("Diana Barry is a very pretty little girl, with her mother's "
		"black eyes and hair, and rosy cheeks.  She has a merry "
		"expression, and she is Anne's bosom friend and kindred "
		"spirit, sworn so by the brook in the hollow.\n");

	set_chat_lines(({
		"say What shall we play at after tea?",
		"say Mother lets me come as often as Marilla will have me.",
	}));
	set_accepts(({ "cordial", "wine" }));
}
