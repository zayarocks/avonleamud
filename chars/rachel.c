/* Mrs. Rachel Lynde. */

inherit "/domains/avonlea/chars/villager";

void setup()
{
   set_name("Rachel");
   set_gender(2);
   set_proper_name("Mrs. Rachel Lynde");
   set_in_room_desc("Mrs. Rachel Lynde sits at her kitchen window with her knitting.");
   set_long("Mrs. Rachel Lynde is one of those capable creatures who can "
            "manage their own concerns and those of other folks into the "
            "bargain.  She runs the Sewing Circle, helps with the Sunday "
            "school, and is the strongest prop of the Church Aid Society and "
            "the Foreign Missions Auxiliary.  She sits for hours at her "
            "kitchen window, knitting cotton-warp quilts and keeping a sharp "
            "eye on the main road.\n");

   set_chat_lines(({
      "say I've knitted sixteen of these quilts, and every one of them done right.",
      "say Adopting a child from an asylum!  You don't know what you're getting.",
      "say There was a boy taken from an asylum up west of the Island who set fire to the house at night.  Set it on purpose.",
      "say Well, they didn't pick her for her looks, that's sure and certain.  Red hair as red as carrots.",
      "emote knits steadily, never once looking down at her needles.",
   }));
}
