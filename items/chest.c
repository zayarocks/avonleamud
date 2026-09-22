/* items/chest.c
 *
 * The wooden chest at the foot of Marilla's bed.  Starts closed, with
 * her amethyst brooch inside, caught in the lace of her black shawl.
 */

inherit "/std/chest";

void setup()
{
  set_adj("wooden");
  set_long("A plain wooden chest at the foot of the bed.  The lid is "
           "shut, but a fold of black lace pokes out from under it.\n");
  set_closed(1);
  set_objects((["amethyst_brooch":1]));
}
