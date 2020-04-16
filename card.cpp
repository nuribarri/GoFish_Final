//File Name: card.cpp
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Cards constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13



#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class Card
{
  public:


    enum Suit {spades, hearts, diamonds, clubs};
    
    Card();          // default, ace of spades

    Card(int rank, Suit s);

    string toString()              const;  // return string version e.g. Ac 4h Js
    bool sameSuitAs(const Card& c) const;  // true if suit same as c
    int  getRank()                 const;  // return rank, 1..13
    string suitString(Suit s)      const;  // return "s", "h",...
    
    string rankString(int r)       const;  // return "A", "2", ..."Q"  
    
    
    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;
    

    
  private:

    int myRank;
    Suit mySuit;

    
};

Card::Card() {

    myRank = 1; // Ace = 1
    mySuit = spades; // enum would be 0
}

Card::Card(int rank, Card::Suit s) {

    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    return (rankString(myRank) + suitString(mySuit));
}

bool Card::sameSuitAs(const Card &c) const {

    if(mySuit == c.mySuit){
        return true;
    }
    return false;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Card::Suit s) const {

    if(s == spades ){
        return "s";
    }
    if(s == hearts){
        return "h";
    }
    if(s == diamonds ){
        return "d";
    }
    if(s == clubs){
        return "c";
    }

    return "0" ;
}

string Card::rankString(int r) const {

    string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    return ranks[r - 1];
}

bool Card::operator==(const Card &rhs) const {

    if(mySuit == rhs.mySuit && myRank == rhs.myRank){
        return true;
    }
    return false;
}

bool Card::operator!=(const Card &rhs) const {

    if(mySuit != rhs.mySuit || myRank != rhs.myRank){
        return true;
    }
    return false;
}

ostream& operator << (ostream& out, const Card& c);


