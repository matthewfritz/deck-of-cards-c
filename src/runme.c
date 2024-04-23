#include <stdbool.h>
#include <stdio.h>
#include "card.h"

int main() {
   enum Suit mySuit = SPADE;
   printf("Suit: %c\n", mySuit);
   return 0;
}