/* The east gable room. */
#include "/d/avonlea/path.h"
inherit "/std/room/basic_room";

void setup() {
    set_short("east gable room");
    add_property("determinate", "the ");
    set_light(70);
    set_zone("green gables");
    set_long("The whitewashed walls of the east gable are so painfully and "
        "staringly bare that they seem to ache over their own bareness.  "
        "The floor is bare too, except for a round braided mat.  In one "
        "corner is a high, old-fashioned bed with four dark, low-turned "
        "posts.  In the other is a three-cornered table adorned with a "
        "fat red velvet pincushion, and above it hangs a little "
        "six-by-eight mirror.  Midway between the table and the bed is "
        "the window, with an icy white muslin frill over it, and "
        "opposite it stands the washstand.\n");

    add_item("window", "Outside, a huge cherry tree grows so close to the "
        "house that its boughs tap against it, and it is so thick with "
        "blossom that hardly a leaf can be seen.  On both sides of the "
        "house is a big orchard, and below is a garden full of lilac "
        "trees.  Beyond, a green field lush with clover slopes down to "
        "the hollow where the brook runs among white birches.  Past it "
        "is a hill, green and feathery with spruce and fir, and through "
        "a gap you can see the grey gable end of the little house on "
        "the other side of the Lake of Shining Waters.  Off to the left "
        "are the big barns, and beyond them, away down over green, "
        "low-sloping fields, is a sparkling blue glimpse of sea.\n");
    add_item(({ "cherry tree", "tree", "snow queen" }), "An enormous "
        "cherry tree in full blossom, its boughs brushing the house.\n");
    add_item(({ "gable", "grey gable", "house" }), "The grey gable of "
        "Orchard Slope, where the Barrys live.\n");
    add_item(({ "bed", "posts" }), "A high, old-fashioned bed with four "
        "dark, low-turned posts.\n");
    add_item(({ "table", "three-cornered table" }), "A small "
        "three-cornered table.\n");
    add_item(({ "pincushion", "velvet pincushion" }), "A fat red velvet "
        "pincushion, hard enough to turn the point of the most "
        "adventurous pin.\n");
    add_item("mirror", "A little six-by-eight mirror.\n");
    add_item(({ "mat", "braided mat" }), "A round braided mat, of a kind "
        "you have seen before.\n");
    add_item(({ "frill", "muslin frill" }), "An icy white muslin frill "
        "over the window.\n");
    add_item("washstand", "A plain washstand.\n");
    add_item(({ "walls", "wall" }), "Bare whitewashed walls.\n");

    room_chat(({ 150, 300, ({
        "A cherry bough brushes against the window.",
        "The scent of blossom drifts in from the orchard.",
    }) }));

    add_exit("west", GG "upstairs_hall", "door");
}
