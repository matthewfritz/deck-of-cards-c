/**
 * deck.h by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the data types and function definitions for handling Deck instances.
 */

#include <stdbool.h>

#ifndef DECK_OF_CARDS_DECK_H
#define DECK_OF_CARDS_DECK_H

/**
 * Deck struct
 * Provides the overall structure of a deck and its requisite properties.
 */
struct Deck {
   struct Card** cards; // array of card pointers inside the deck
   int pointer; // pointer to the current index in the cards array
   int numDecks; // number of "decks" that make up this deck (technically it's a "shoe")
};

/**
 * Counts the number of cards in the provided Deck and returns the count.
 *
 * @param deck The deck where the cards will be counted
 * @return int
 */
int countCards(struct Deck* deck);

/**
 * Creates and returns a Deck instance containing the given number of decks inside. This uses malloc() so be sure to
 * free the memory with freeDeck() when you are finished with the resource. This can also return NULL if something
 * goes wrong during memory allocation.
 *
 * @param numDecks The number of decks to create; this will be multiplied together with the total suits and values
 *
 * @return Deck*
 * @see freeDeck()
 */
struct Deck* createDeck(int numDecks);

/**
 * Creates and returns a Deck instance containing just a single deck inside (the default). This uses malloc() so be
 * sure to free the memory with freeDeck() when you are finished with the resource. This can also return NULL if
 * something goes wrong during memory allocation.
 *
 * @return Deck*
 * @see freeDeck()
 */
struct Deck* createDefaultDeck();

/**
 * Draws and returns the next card from the deck. This also updates the internal pointer of the Deck instance by one.
 * This can also return NULL if the deck itself is invalid or if there are no more cards to draw.
 *
 * @param deck The deck from which a card will be drawn
 * @return Card*
 */
struct Card* drawCard(struct Deck* deck);

/**
 * Frees the memory allocated from the createDeck() function and sets the provided pointer to NULL. This also frees
 * the entirety of the internal Card pointers too.
 *
 * @param deck Pointer to a Deck instance
 * @see createDeck()
 * @see createDefaultDeck()
 */
void freeDeck(struct Deck* deck);

/**
 * Returns a boolean describing whether the provided deck contains more cards that can be drawn.
 *
 * @param deck The deck to check
 * @return bool
 */
bool hasMoreCards(struct Deck* deck);

/**
 * Prints the cards in the deck to a single line in stdout.
 *
 * @param deck The deck containing the cards to print
 */
void printCardsInDeck(struct Deck* deck);

/**
 * Prints the cards in the deck, one per line depending on the boolean, to stdout.
 *
 * @param deck The deck containing the cards to print
 * @param addNewLine True to add a newline character after each card, false to omit the newline
 */
void printCardsInDeckByLine(struct Deck* deck, bool addNewLine);

/**
 * Prints the cards in the deck, one per line, to stdout.
 *
 * @param deck The deck containing the cards to print
 */
void printCardsInDeckFormatted(struct Deck* deck);

#endif // DECK_OF_CARDS_DECK_H