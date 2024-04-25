/**
 * value.c by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the implemented functionality for handling Value instances.
 */

#include "value.h"

/**
 * ALL_VALUES constant
 * Array containing all valid values for cards.
 */
const enum Value ALL_VALUES[13] = {
   ACE,
   TWO,
   THREE,
   FOUR,
   FIVE,
   SIX,
   SEVEN,
   EIGHT,
   NINE,
   TEN,
   JACK,
   QUEEN,
   KING
};