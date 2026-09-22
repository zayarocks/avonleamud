/* items/currant_wine.c
 *
 * Marilla's three-year-old currant wine, on the second shelf of the
 * sitting-room closet.  The same colour as the cordial, and famous
 * all over Avonlea, whatever the minister's wife may think of it.
 */

inherit OBJ;
inherit M_GETTABLE;

void setup()
{
  set_id("bottle", "wine");
  set_adj("currant", "red");
  set_long("A bottle of a deep cheerful red, the very colour of "
           "raspberry cordial.  Only the label tells them apart, and it "
           "is faded nearly to nothing.  Something in the smell of it is "
           "not quite fruit.\n");
}
