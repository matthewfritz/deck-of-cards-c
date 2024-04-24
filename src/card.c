/**
 * card.c by Matthew Fritz <https://github.com/matthewfritz>
 * Contains the implemented functionality for handling Card instances.
 *
 * All documentation for the functions is in the matching .h file.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "card.h"

struct Card* createCard(enum Value value, enum Suit suit) {
   struct Card* newCard = (struct Card *)malloc(sizeof(struct Card));
   newCard->value = value;
   newCard->suit = suit;
   return newCard;
}

void freeCard(struct Card* card) {
   free(card);
   card = NULL;
}

bool hasSameSuit(struct Card* c1, struct Card* c2) {
   return c1->suit == c2->suit;
}

bool hasSameValue(struct Card* c1, struct Card* c2) {
   return valueDifference(c1, c2) == 0;
}

void printCard(struct Card* card) {
   printf("%d%c", card->value, card->suit);
}

int valueDifference(struct Card* c1, struct Card* c2) {
   return abs(c1->value - c2->value);
}