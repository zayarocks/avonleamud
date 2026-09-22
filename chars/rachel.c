/* Mrs. Rachel Lynde. */
#include "/d/avonlea/path.h"
inherit CHARS "villager";

void remark(object who);
void anne_talk(object player, string mess);

void setup() {
    set_name("rachel");
    set_short("Mrs. Rachel Lynde");
    add_property("determinate", "");
    add_property("unique", 1);
    add_alias(({ "lynde", "woman" }));
    add_adjective(({ "mrs", "mrs." }));
    set_gender(2);
    set_long("Mrs. Rachel Lynde is one of those capable creatures who can "
        "manage their own concerns and those of other folks into the "
        "bargain.  She runs the Sewing Circle, helps with the Sunday "
        "school, and is the strongest prop of the Church Aid Society and "
        "the Foreign Missions Auxiliary.  She sits for hours at her "
        "kitchen window, knitting cotton-warp quilts and keeping a sharp "
        "eye on the main road.\n");

    villager_setup(20);

    load_chat(8, ({
        2, ":knits at her cotton-warp quilt.",
        1, "'I've knitted sixteen of these quilts, and every one of them "
           "done right.",
        1, "'Adopting a child from an asylum!  You don't know what you're "
           "getting.",
        1, "'There was a boy taken from an asylum up west of the Island "
           "who set fire to the house at night.  Set it on purpose.",
        1, ":peers up the lane toward Green Gables.",
    }));

    add_respond_to_with(({ "@say", "anne" }), "#anne_talk");
}

void event_enter(object ob, string mess, object from) {
    ::event_enter(ob, mess, from);
    if (!ob || ob == this_object() || !userp(ob)) return;
    if (find_call_out("remark") == -1)
        call_out("remark", 2, ob);
}

void remark(object who) {
    string *lines;
    string name;

    if (!who || environment(who) != environment()) return;
    name = who->query_cap_name();

    lines = ({
        "Good day, " + name + ".  Where are you bound?",
        "Have you come from Green Gables, " + name + "?  How is Marilla "
            "getting on?",
        "You're out and about early, " + name + ".",
    });
    do_command("say " + lines[random(sizeof(lines))]);
}

void anne_talk(object player, string mess) {
    if (!player) return;
    do_command("say Well, they didn't pick her for her looks, that's sure "
        "and certain.  Red hair as red as carrots.  I told Marilla "
        "plump and plain she was doing a risky thing.");
}
