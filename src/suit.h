/**
 * suit.h by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the data types and function definitions for handling Suit instances.
 */

#ifndef DECK_OF_CARDS_SUIT_H
#define DECK_OF_CARDS_SUIT_H

/**
 * Suit enum
 * Contains the set of all valid suits that a card may possess.
 */
enum Suit {
   CLUB = 'c',
   DIAMOND = 'd',
   HEART = 'h',
   SPADE = 's'
};

/**
 * ALL_SUITS constant
 * Array containing all valid suits for cards.
 */
extern const enum Suit ALL_SUITS[4];

#endif // DECK_OF_CARDS_SUIT_H