/**
 * card.h by Matthew Fritz
 * Contains the data types and function definitions for handling Card instances.
 */

#ifndef DECK_OF_CARDS_CARD_H
// intentionally *not* using "#pragma once" because of a small portability issue with certain compilers
#define DECK_OF_CARDS_CARD_H

/**
 * Color enum
 * Contains the set of all valid colors that a card may possess. 
 */
enum Color {
   BLACK = 'b',
   RED = 'r',
};

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

/**
 * Card struct
 * Provides the overall structure of a card and its requisite properties.
 */
struct Card {
   enum Color color;
   enum Suit suit;
   enum Value value;
};

/**
 * Creates and returns a Card instance with the given color, suit, and value.
 * 
 * @param color The color of the card
 * @param suit The suit of the card
 * @param value The value of the card
 * 
 * @return Card
 */
struct Card createCard(enum Color color, enum Suit suit, enum Value value);

/**
 * Returns a boolean describing whether two cards possess the same suit.
 * 
 * @param c1 The first card to check
 * @param c2 The second card to check
 * 
 * @return bool
 */
bool hasSameSuit(struct Card c1, struct Card c2);

/**
 * Returns a boolean describing whether two cards possess the same value.
 * 
 * @param c1 The first card to check
 * @param c2 The second card to check
 * 
 * @return bool
 */
bool hasSameValue(struct Card c1, struct Card c2);

/**
 * Returns an integer representing the absval of the distance between the values of two cards.
 * 
 * @param c1 The first card to check
 * @param c2 The second card to check
 * 
 * @return int
 */
int valueDifference(struct Card c1, struct Card c2);

#endif // DECK_OF_CARDS_CARD_H