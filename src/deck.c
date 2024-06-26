/**
 * deck.c by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the implemented functionality for handling Deck instances.
 *
 * All documentation for the functions is in the matching .h file.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "card.h"
#include "deck.h"
#include "suit.h"
#include "value.h"

bool canDraw(struct Deck* deck) {
   return hasMoreCardsMinimum(deck, 0);
}

int countCards(struct Deck* deck) {
   if(deck == NULL) {
      return 0;
   }
   if (deck->cards == NULL) {
      return 0;
   }
   return deck->count;
}

struct Card* drawCard(struct Deck* deck) {
   if(!canDraw(deck)) {
      return NULL;
   }
   return deck->cards[deck->pointer++];
}

void freeDeck(struct Deck* deck) {
   // free the cards and clear their memory first
   int numCards = countCards(deck);
   for(int i = 0; i < numCards; i++) {
      freeCard(deck->cards[i]);
   }
   if(deck != NULL) {
      free(deck->cards);
   }

   // now free the rest of the memory in the deck
   free(deck);
   deck = NULL;
}

bool hasMoreCards(struct Deck* deck) {
   return hasMoreCardsMinimum(deck, 1);
}

bool hasMoreCardsMinimum(struct Deck* deck, int minimum) {
   if(deck == NULL || minimum < 0) {
      return false;
   }
   return deck->pointer >= 0 && deck->pointer < countCards(deck) - minimum;
}

struct Deck* makeDeck(int numDecks) {
   int numSuits = sizeof(ALL_SUITS) / sizeof(ALL_SUITS[0]);
   int numValues = sizeof(ALL_VALUES) / sizeof(ALL_VALUES[0]);
   int numTotalCards = numDecks * numSuits * numValues;

   // we have to do some fancy size calculations for malloc() due to the variable-length array that is the
   // "cards" property on the Deck struct
   size_t totalCardsSize = sizeof(struct Card) * numTotalCards;
   size_t fullDeckSize = sizeof(struct Deck) + totalCardsSize;
   struct Deck* newDeck = (struct Deck *)malloc(fullDeckSize);
   if(newDeck == NULL) {
      return NULL;
   }
   newDeck->cards = (struct Card **)malloc(totalCardsSize);
   if(newDeck->cards == NULL) {
      // weird case but we want to ensure the calling code realizes there was an error without also
      // causing undocumented behavior in it unintentionally too
      freeDeck(newDeck);
      return NULL;
   }

   // initialize the cards in the deck(s)
   int cardIndex = 0;
   for(int deckIndex = 0; deckIndex < numDecks; deckIndex++) {
      for(int suitIndex = 0; suitIndex < numSuits; suitIndex++) {
         for(int valueIndex = 0; valueIndex < numValues; valueIndex++) {
            newDeck->cards[cardIndex] = makeCard(ALL_VALUES[valueIndex], ALL_SUITS[suitIndex]);
            if (newDeck->cards[cardIndex] == NULL) {
               // free the rest of the deck immediately and bounce out so we don't get into a weird half-in/half-out
               // state where some card pointers are valid and other card pointers are NULL down the line
               freeDeck(newDeck);
               return NULL;
            }
            cardIndex++; // we could do a calculation using the loop indices but this is just more readable
         }
      }
   }

   newDeck->numDecks = numDecks;
   newDeck->count = cardIndex;
   newDeck->pointer = 0;
   return newDeck;
}

struct Deck* makeDefaultDeck() {
   return makeDeck(1);
}

void printCardsInDeck(struct Deck* deck) {
   printCardsInDeckByLine(deck, false);
}

void printCardsInDeckByLine(struct Deck* deck, bool addNewLine) {
   if(deck == NULL) {
      return;
   }
   int numCards = countCards(deck);
   for(int i = 0; i < numCards; i++) {
      printCard(deck->cards[i]);
      if(addNewLine) {
         printf("\n");
      }
   }
}

void printCardsInDeckFormatted(struct Deck* deck) {
   printCardsInDeckByLine(deck, true);
}