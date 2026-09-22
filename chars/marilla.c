inherit "/domains/avonlea/chars/villager";

void on_receive(object ob)
{
   do_game_command("say Caught in my black lace shawl!  I'd never have thought to look there.");
   do_game_command("say Thank you.  It was my mother's, and I'd sooner lose anything else I own.");
   destruct(ob);
}

void setup()
{
   set_name("Marilla");
   set_gender(2);
   set_proper_name("Marilla Cuthbert");
   set_in_room_desc("Marilla Cuthbert stands by the stove, as straight as a poker.");
   set_long("Marilla Cuthbert is a tall, thin woman, with angles and "
            "without curves.  Her dark hair shows some grey streaks and is "
            "always twisted up in a hard little knot behind, with two wire "
            "hairpins stuck through it.  She looks like a woman of narrow "
            "experience and rigid conscience, but there is a saving "
            "something about her mouth which, if it had been ever so "
            "slightly developed, might have been considered indicative of "
            "a sense of humour.\n");

   set_chat_lines(({
      "say We asked Mrs. Spencer to bring us a boy.  A boy would be some use on the farm.",
      "say To despair is to turn your back on God.",
      "say There's the dinner to get and the cows to see to.",
      "say I've no patience with all this romantic nonsense.",
   }));
   set_accepts(({ "brooch" }));
}
