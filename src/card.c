#include <math.h>
#include <stdbool.h>
#include "card.h"

struct Card createCard(enum Color color, enum Suit suit, enum Value value) {
   struct Card newCard = {color, suit, value};
   return newCard;
}

bool hasSameSuit(struct Card c1, struct Card c2) {
   return c1.suit == c2.suit;
}

bool hasSameValue(struct Card c1, struct Card c2) {
   return valueDifference(c1, c2) == 0;
}

int valueDifference(struct Card c1, struct Card c2) {
   return abs(c1.value - c2.value);
}