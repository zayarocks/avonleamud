/* weather_d.c
 *
 * Seasonal weather for Avonlea.  Replaces LIMA's /daemons/weather_d,
 * which picks one of four words at random and will cheerfully snow in
 * June.
 *
 * The season comes from the real calendar.  Each season has its own
 * weather, changing every WEATHER_PERIOD seconds, the same everywhere
 * outdoors.  Rooms reach it through avonlea_outdoor.c.
 */

#define WEATHER_PERIOD 300
#include <localtime.h>

nosave private int current;
nosave private string season_now;

mapping WEATHER = ([
	"spring" : ({
		"The sun is out, and the air smells of wet earth and growing things.",
		"A soft rain is falling, the kind that brings the grass on.",
		"The wind comes off the sea in gusts, and the clouds go over fast.",
		"It is grey and still, and the light is the colour of milk.",
		"The sun is out, and every ditch and hollow is loud with running water.",
		"A fine mist hangs in the hollows and takes the tops off the trees.",
	}),
	"summer" : ({
		"The sun is high and hot, and the air shimmers over the red road.",
		"It is a still, blue day, with the heat lying heavy on the fields.",
		"Rain is falling warm and straight down, and the leaves are loud with it.",
		"The sun is out, and a breeze comes up from the shore smelling of salt.",
		"Thunder mutters somewhere off beyond the woods.",
		"The sun is out, and the air is thick and sweet with clover.",
		"A white fog has come in off the water and swallowed the far fields.",
	}),
	"autumn" : ({
		"The sun is out, thin and gold, and the air has an edge to it.",
		"Rain is coming down steadily, and the road is running red.",
		"The wind is up, and the leaves are going past sideways.",
		"It is grey and close, and everything smells of wet leaves.",
		"The sun is out, and there is frost still lying in the shadows.",
		"Fog lies over the fields, so thick the barns have gone.",
	}),
	"winter" : ({
		"Snow is falling, thick and soft, and the world has gone quiet.",
		"The sun is out, hard and bright, and the snow glares back at it.",
		"The wind is driving the snow along the ground in long white snakes.",
		"It is grey and bitter, and the air hurts to breathe.",
		"Snow is falling, fine as flour, and the sky is the colour of lead.",
		"The sun is out and there is no wind, and the cold is almost pleasant.",
	}),
]);

//: FUNCTION query_season
// The current season, from the real calendar.  The island runs late,
// so spring holds off until April and winter lasts through March.
string query_season()
{
	int month = (int)localtime(time())[LT_MON] + 1;

	switch (month)
	{
	case 4:
	case 5:
		return "spring";
	case 6:
	case 7:
	case 8:
		return "summer";
	case 9:
	case 10:
	case 11:
		return "autumn";
	default:
		return "winter";
	}
}

private void change_weather()
{
	string season = query_season();
	string *choices = WEATHER[season];
	int last = current;

	remove_call_out();

	if (season != season_now)
	{
		season_now = season;
		last = -1;
	}

	if (sizeof(choices) > 1)
	{
		do
		{
			current = random(sizeof(choices));
		}
		while (current == last);
	}

	call_out((: change_weather :), WEATHER_PERIOD);
}

//: FUNCTION query_current_weather
// The line appended to outdoor room descriptions.
string query_current_weather()
{
	string *choices;

	if (!season_now)
		season_now = query_season();

	choices = WEATHER[season_now];
	if (!choices || !sizeof(choices))
		return "";
	if (current >= sizeof(choices))
		current = 0;

	return choices[current];
}

void create()
{
	change_weather();
}
