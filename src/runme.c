/**
 * runme.c by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the implemented functionality for spot-checking our overall logic.
 */

#include <stdbool.h>
#include <stdio.h>
#include "card.h"

int main() {
   struct Card* myCard = createCard(ACE, SPADE);
   printf("My card suit: %c\n", myCard->suit);

   printf("Card to string: ");
   printCard(myCard);
   printf("\n");

   freeCard(myCard);

   return 0;
}