/* rooms/village/church_door.c
 *
 * The top of the knoll at the church door, with the graveyard
 * running downhill behind.
 */

#include "/domains/avonlea/path.h"

inherit AVONLEA_OUTDOOR;

void setup()
{
	set_brief("The church door");
	set_long("The ground levels off at the top of the knoll in front "
		"of the church, which is white clapboard with a row of plain "
		"windows down each side and a spire that can be seen from "
		"most of Avonlea.  Three steps go up to a double door, the "
		"middle of the lowest one worn hollow.  A board beside the "
		"door gives the hours of service and the text for Sunday.  "
		"Behind the church the graveyard runs away downhill in rows.  "
		"The gate and the sheds are below to the south.\n");
	set_light(1);

	add_item("church", "White clapboard, kept painted, with a plain "
		"window between every pair of studs and no ornament anywhere "
		"except the spire.\n");
	add_item("steps", "step", "Three wooden steps.  The lowest is worn "
		"hollow in the middle and nowhere else.\n");
	add_item("door", "doors", "A double door of planed boards, shut "
		"through the week, with an iron ring handle polished by "
		"use.\n");
	add_item("board", "notice", "The hours of service, and under them "
		"in smaller letters the text for Sunday and the name of the "
		"minister.\n");
	add_item("spire", "Straight, whitewashed, and visible from the "
		"shore road, the school, and most kitchen windows in "
		"Avonlea.\n");
	add_item("windows", "window", "Plain glass in plain frames.  There "
		"is no coloured glass in Avonlea, and opinions differ on "
		"whether there ought to be.\n");
	add_item("graveyard", "graves", "It runs downhill behind the "
		"church, north of here.\n");

	set_listen("Wind round the corner of the church, and the spruces "
		"below.\n");
	set_smell("Paint, and cut grass.\n");

	set_exits(([
		"south" : VILLAGE "church_gate",
		"down" : VILLAGE "church_gate",
		"north" : VILLAGE "graveyard",
	]));
	/* Future: "in" to the church itself. */
}
