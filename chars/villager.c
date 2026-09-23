inherit LIVING;
inherit M_ACTIONS;

string *chat_lines = ({});
string *accepted_ids = ({});
int chatting, checking;

// Override in each character to react when given something they accept.
void on_receive(object ob) {}

void chatter()
{
	if (sizeof(chat_lines) && environment() &&
		 sizeof(users() & all_inventory(environment())))
		do_game_command(chat_lines[random(sizeof(chat_lines))]);
	call_out((: chatter :), 45 + random(60));
}

void check_pockets()
{
	foreach (string id in accepted_ids)
	{
		object ob = present(id, this_object());
		if (ob)
			on_receive(ob);
	}
	call_out((: check_pockets :), 2);
}

void set_chat_lines(string *lines)
{
	chat_lines = lines;
	if (!chatting)
	{
		chatting = 1;
		call_out((: chatter :), 20);
	}
}

void set_accepts(string *ids)
{
	accepted_ids = ids;
	if (!checking)
	{
		checking = 1;
		call_out((: check_pockets :), 2);
	}
}

mixed indirect_give_obj_to_liv(object ob, object liv)
{
	foreach (string id in accepted_ids)
		if (ob->id(id))
			return 1;
  return "#That is not wanted here.\n";
}
