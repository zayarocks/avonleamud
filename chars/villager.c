/*
 * Base object for all Avonlea NPCs.
 *
 * Replaces basic_setup(race, guild, level), so no NPC in
 * Avonlea belongs to a guild.  To change how every NPC's
 * race and level are set, edit villager_setup() below.
 */
inherit "/obj/monster";

void villager_setup(int level) {
    set_race("human");
    set_level(level);
}
