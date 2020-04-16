// FILE:  player.cpp
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks



#include <iostream>
#include <string>
#include <vector>


#include "card.h"
#include "deck.h"
using namespace std;


class Player
{
  public:
    Player();

    Player(string name) {
       myName = name;
    }

    string getName() const {
       return myName;
    }
    
    void addCard(Card c);  //adds a card to the hand
    void bookCards(Card c1, Card c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    bool rankInHand(Card c) const; 
    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const; 
    
    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const; 
    
    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c); 
    
    string showHand() const; 
    string showBooks() const; 
    
    int getHandSize() const; 
    int getBookSize() const; 
       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    
    bool sameRankInHand(Card c) const; 
    
    
  private:
          
    vector <Card> myHand;
    vector <Card> myBook;
    
    string myName;     
   
};

Player::Player() {

    myName = "   ";
}

void Player::addCard(Card c) {

    myHand.push_back(c); // add card to deck , vector

}

void Player::bookCards(Card c1, Card c2) {

    //if(c1.getRank() == c2.getRank()){

        myBook.push_back(c1);           //add cards to book
        removeCardFromHand(c1);         //remove the cards from player's hand

        myBook.push_back(c2);
        removeCardFromHand(c2);


    //}

}

//bool Player::checkHandForBook(Card &c1, Card &c2) {
//    return false;
//}

bool Player::rankInHand(Card c) const {

    bool InHand;

    for(int i = 0; i < myHand.size(); i++){

        if(c.getRank() == myHand[i].getRank()){
            InHand =  true;
            return InHand;
        }
    }

    InHand = false;
    return InHand;

}

Card Player::chooseCardFromHand() const {

    int rand1;

    rand1 = rand() % myHand.size();     // selects random card from hand

    return myHand[rand1];

}

bool Player::cardInHand(Card c) const {

    bool InHand;
    int i;

    for(i = 0; i < myHand.size(); i++){

        if(c == myHand[i]){
            InHand =  true;
        }
    }

    InHand = false;
    return InHand;

}

Card Player::removeCardFromHand(Card c) {

    Card removed(0, Card::Suit(Card::spades));                    // returns "removed" if found in deck
    int i = 0;                           //counter

    //while(cardInHand(c)){

        for(i = 0; i < myHand.size(); i++){

            if(c.getRank() == myHand[i].getRank()){

                removed = myHand[i];                    //stores card to be returned

                myHand[i] = myHand[myHand.size() - 1]; // stores the card at back of the vector to the current position of desired-removed card
                myHand[myHand.size() - 1] = removed;   // Set back of vector to desire-removed card
                myHand.pop_back();                     // use popback to remove the last element in a vector
                return removed;

            }
        }
   // }
    return removed;                                    // returns Ace of spades if not removed properly
}

string Player::showHand() const {

    string Hand;


    if(!myHand.empty()) {

        int j = 0;

        while (j + 1 != myHand.size()) {
            Hand = Hand + myHand[j].toString();
            Hand = Hand + ", ";
            j++;
        }
        Hand = Hand + myHand[j].toString();
    }

    return Hand;
}

string Player::showBooks() const {

    string Book;

    int j = 0;

    if(!myBook.empty()) {

        if (getBookSize() > 0) {
            while (j + 1 != myBook.size()) {

                Book = Book + myBook[j].toString();
                Book = Book + ", ";
                j++;
            }
            Book = Book + myBook[j].toString();

        }
    }
    return Book;
}

int Player::getHandSize() const {

    int handSize = myHand.size();

    return handSize;

}

int Player::getBookSize() const {

    int bookSize = myBook.size();

    return bookSize;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {

    int i;
    int k;

    for(i = 0; i < myHand.size(); i++){
        for(k = i +1; k < myHand.size(); k++){

            if(myHand[i].getRank() == myHand[k].getRank()){
                c1 = myHand[i];
                c2 = myHand[k];
                return true;
            }

        }
    }
    return false;
}

bool Player::sameRankInHand(Card c) const {

    int i;

    for(i = 0; i < myHand.size(); i++){

        if(myHand[i].getRank() == c.getRank()){
                return true;
        }

    }

    return false;
}

