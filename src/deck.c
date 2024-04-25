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

int countCards(struct Deck* deck) {
   if(deck == NULL) {
      return 0;
   }
   if (deck->cards == NULL) {
      return 0;
   }
   return sizeof(deck->cards) / sizeof(struct Card);
}

struct Deck* createDeck(int numDecks) {
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

   // initialize the cards in the deck
   int cardIndex = 0;
   for(int suitIndex = 0; suitIndex < numSuits; suitIndex++) {
      for(int valueIndex = 0; valueIndex < numValues; valueIndex++) {
         newDeck->cards[cardIndex] = createCard(ALL_VALUES[valueIndex], ALL_SUITS[suitIndex]);
         cardIndex++; // we could do a calculation using the loop indices but this is just more readable
      }
   }

   newDeck->numDecks = numDecks;
   newDeck->pointer = 0;
   return newDeck;
}

struct Deck* createDefaultDeck() {
   return createDeck(1);
}

struct Card* drawCard(struct Deck* deck) {
   if(!hasMoreCards(deck)) {
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

   // now free the rest of the memory in the deck
   free(deck);
   deck = NULL;
}

bool hasMoreCards(struct Deck* deck) {
   if(deck == NULL) {
      return false;
   }
   if(deck->pointer < 0 || deck->pointer >= countCards(deck)) {
      return false;
   }
   return true;
}

void printCardsInDeckLines(struct Deck* deck, bool addNewLine) {
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

void printCardsInDeck(struct Deck* deck) {
   printCardsInDeckLines(deck, false);
}