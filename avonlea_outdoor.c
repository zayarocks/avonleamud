/* avonlea_outdoor.c
 *
 * Base for every outdoor room in Avonlea.  Turns on weather and
 * points it at the domain's own seasonal weather daemon rather than
 * LIMA's, which snows in June.
 *
 * Outdoor rooms inherit this instead of OUTDOOR_ROOM.
 */

#include "/domains/avonlea/path.h"

inherit OUTDOOR_ROOM;

void mudlib_setup()
{
	::mudlib_setup();
	set_weather(1);
}

string get_weather()
{
	if (!query_weather())
		return "";
	return (string)AVONLEA "weather_d"->query_current_weather();
}
