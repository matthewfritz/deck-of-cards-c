/**
 * card.h by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the data types and function definitions for handling Card instances.
 */

#ifndef DECK_OF_CARDS_CARD_H
// intentionally *not* using "#pragma once" because of a small portability issue with certain compilers
#define DECK_OF_CARDS_CARD_H

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
   enum Suit suit;
   enum Value value;
};

/**
 * Creates and returns a Card instance with the given value and suit. This uses malloc() so be sure to free the
 * memory with freeCard() when you are finished with the resource.
 *
 * @param value The value of the card
 * @param suit The suit of the card
 *
 * @return Card
 * @see freeCard()
 */
struct Card* createCard(enum Value value, enum Suit suit);

/**
 * Frees the memory allocated from the createCard() function and sets the provided pointer to NULL.
 * 
 * @param card Pointer to a Card instance
 * @see createCard()
 */
void freeCard(struct Card* card);

/**
 * Returns a boolean describing whether two cards possess the same suit.
 *
 * @param c1 The first card to check
 * @param c2 The second card to check
 *
 * @return bool
 */
bool hasSameSuit(struct Card* c1, struct Card* c2);

/**
 * Returns a boolean describing whether two cards possess the same value.
 *
 * @param c1 The first card to check
 * @param c2 The second card to check
 *
 * @return bool
 */
bool hasSameValue(struct Card* c1, struct Card* c2);

/**
 * Prints a string representation of the Card instance to stdout.
 *
 * @param card Pointer to a Card instance
 */
void printCard(struct Card* card);

/**
 * Returns an integer representing the absval of the distance between the values of two cards.
 *
 * @param c1 The first card to check
 * @param c2 The second card to check
 * 
 * @return int
 */
int valueDifference(struct Card* c1, struct Card* c2);

#endif // DECK_OF_CARDS_CARD_H