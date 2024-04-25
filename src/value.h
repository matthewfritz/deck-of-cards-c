/**
 * value.h by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the data types and function definitions for handling Value instances.
 */

#ifndef DECK_OF_CARDS_VALUE_H
#define DECK_OF_CARDS_VALUE_H

/**
 * Value enum
 * Contains the set of all valid values that a card may possess.
 */
enum Value {
   ACE = 1,
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

#endif // DECK_OF_CARDS_VALUE_H