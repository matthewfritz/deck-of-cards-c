/**
 * runme.c by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the implemented functionality for spot-checking our overall logic.
 */

#include <stdbool.h>
#include <stdio.h>
#include "card.h"
#include "deck.h"

int main() {
   struct Card* myCard = createCard(ACE, SPADE);
   printf("My card suit: %c\n", myCard->suit);

   printf("Card to string: ");
   printCard(myCard);
   printf("\n");

   freeCard(myCard);

   struct Deck* myDeck = createDefaultDeck();
   printf("Cards in deck:\n");
   printCardsInDeckFormatted(myDeck);
   printf("Num cards: %d\n", countCards(myDeck));

   freeDeck(myDeck);

   return 0;
}