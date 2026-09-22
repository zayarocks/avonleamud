/* Matthew Cuthbert. */
#include "/d/avonlea/path.h"
inherit CHARS "villager";

void greet(object player, string mess);
void anne_talk(object player, string mess);

void setup() {
    set_name("matthew");
    set_short("Matthew Cuthbert");
    add_property("determinate", "");
    add_property("unique", 1);
    add_alias(({ "cuthbert", "man" }));
    set_gender(1);
    set_long("Matthew Cuthbert is an odd-looking personage, with an "
        "ungainly figure and long iron-grey hair that touches his "
        "stooping shoulders.  He has a full, soft brown beard which he "
        "has worn ever since he was twenty.  In fact, he looks at sixty "
        "very much as he looked at twenty, lacking a little of the "
        "greyness.  He is painfully shy, and seems happiest when left "
        "alone.\n");

    villager_setup(20);

    load_chat(6, ({
        2, "'Well now, I dunno.",
        2, ":looks down at the ground.",
        1, "'I'll be sowing the late turnip seed on the hill field.",
        1, ":glances toward the kitchen door.",
    }));

    add_respond_to_with(({ "@say", ({ "hello", "hi", "good morning",
        "good afternoon", "good evening" }) }), "#greet");
    add_respond_to_with(({ "@say", "anne" }), "#anne_talk");
}

void greet(object player, string mess) {
    if (!player) return;
    if ((int)player->query_gender() == 2) {
        do_command("emote colours and looks away shyly.");
        do_command("say Good day.");
    } else {
        do_command("say Well now.  Good day.");
    }
}

void anne_talk(object player, string mess) {
    if (!player) return;
    do_command("say She's a real interesting little thing.");
}
