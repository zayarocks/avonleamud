inherit "/domains/avonlea/chars/villager";

void setup()
{
   set_name("Anne");
   set_gender(2);
   set_proper_name("Anne Shirley");
   set_in_room_desc("Anne Shirley kneels at the window, gazing out at the cherry tree.");
   set_long("Anne Shirley is a child of about eleven, in a very short, very "
            "tight, very ugly dress of yellowish-grey wincey.  Two braids of "
            "very thick, decidedly red hair hang down her back.  Her face is "
            "small, white and thin, and much freckled; her mouth is large, "
            "and so are her eyes, which look green in some lights and moods "
            "and grey in others.  There is a great deal of spirit in her "
            "pointed chin, and a great deal of imagination in her eyes.\n");

   set_chat_lines(({
      "say Isn't it nice to think that tomorrow is a new day with no mistakes in it yet?",
      "say I'm so glad I live in a world where there are Octobers.",
      "say Kindred spirits are not so scarce as I used to think.  It's splendid to find out there are so many of them in the world.",
      "say There's such a lot of different Annes in me.  I sometimes think that is why I'm such a troublesome person.",
      "say My life is a perfect graveyard of buried hopes.",
      "say If you call me Anne, please call me Anne spelled with an E.",
      "say Isn't it splendid to think of all the things there are to find out about?  It just makes me feel glad to be alive.",
      "say Marilla says I may have Diana to tea, and give her the raspberry cordial.  It's down in the cellar.",
   }));
}
