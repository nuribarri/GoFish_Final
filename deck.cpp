// FILE: deck.cpp
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#include "card.h"
#include <ctime>
#include <cstdlib>


class Deck
{
  static const int SIZE = 52;
  
  public:
    
    
    Deck();           // pristine, sorted deck

    void shuffle();   // shuffle the deck, all 52 cards present
    Card dealCard();   // get a card, after 52 are dealt, fail to deal if empty

    int  size() const; // # cards left in the deck

  private:

    Card myCards[SIZE];             // The deck of cards as an array
    int myIndex;  // current card to deal
};

Deck::Deck() {

    myIndex = 0;
    int i = 0;      //Creating a tempory index
    int suit;
    int rank;

    for(suit = 0; suit < 4; suit++){
        for(rank = 1; rank < 14; rank++){

            myCards[i] = Card(rank, Card::Suit(suit));      // adding one card at a time by suit and rank
            i++;
        }
    }

}

void Deck::shuffle() {

    Card swap;
    int i = 0;
    int rand1;
    int rand2;

    unsigned int currentTime = (unsigned) time(0);

    srand(currentTime);

    for(i = 0; i < SIZE * 2; i++){

        rand1 = rand() % SIZE;
        rand2 = rand() % SIZE;

        swap = myCards[rand1];              // store first random card temporarily
        myCards[rand1] = myCards[rand2];    // swap card 1 with card 2
        myCards[rand2] = swap;              // store card 2 with card 1
    }

}

Card Deck::dealCard() {

    Card dealt(0,Card::Suit(Card::spades)); // returns Ace of Spades if something goes wrong

    if(size() > 0) {

        dealt = myCards[myIndex];
        myIndex = myIndex + 1;
        return dealt;

    }
    return dealt;
}


int Deck::size() const {

    int sizeofDeck;

    sizeofDeck = SIZE - myIndex;

    return sizeofDeck;

}
