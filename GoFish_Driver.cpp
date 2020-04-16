// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <ctime>
#include <vector>


using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int Winner(Player &p1, Player &p2);

bool checkforpairHelper(Player &p, int handSize);


int main( )
{

    ofstream oFile;
    oFile.open("output.txt");
    oFile << "Output test!!!" << endl;

    Player p1("Nathaniel");
    Player p2("Claudio");



    cout << "Let's play Go Fish!\n" << endl;
    cout << "Player 1 is " << p1.getName() << endl;
    cout << "Player 2 is " << p2.getName() << endl << endl;

    int numCards = 7;
    int handSize1 = 7, handSize2 = 7;

    Deck d;                              //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    //cout << "Dealing cards" << endl << endl;

    //cout << p1.getName() <<" has : " << p1.showHand() << endl;
    //cout << p2.getName() <<" has : " << p2.showHand() << endl;

// debugging
//
//    cout << "books" << p1.showBooks()<< endl;
//    Card debug1(1, Card::Suit(0));
//    Card debug2(1, Card::Suit(1));
//
//    p1.bookCards(debug1, debug2);
//    cout << p1.showBooks() << endl;



// begin playing

    bool p1turn = true, p2turn = false;     //player 1 goes first


    while(Winner(p1, p2) == 0) {


        Card p1Request, p2Request;
        Card p1Draw, p2Draw;
        Card p1NewBook, p2NewBook;
        bool sameRank2, sameRank1;




            while (p1turn && Winner(p1,p2) == 0) {
                //if(Winner(p1,p2) == 0) {
                if (p1.getHandSize() == 0 && d.size() >= 1) {
                    Card pickup;
                    pickup = d.dealCard();
                    p1.addCard(pickup);
               //     cout << p1.getName() << " picks up a " << pickup.toString() << endl;
              //      cout << p1.showHand() << endl;
                }


                while (checkforpairHelper(p1, handSize1)) {

                //    cout << p1.getName() << " has a book " << endl;
                //    cout << p1.showBooks() << endl << endl;

                }


                p1Request = p1.chooseCardFromHand();
                cout << p1.getName() << " asks - Do you have any " << p1Request.getRank() << "'s?" << endl;

                sameRank2 = p2.sameRankInHand(p1Request);

                if (sameRank2) {

                    p1NewBook = p2.removeCardFromHand(p1Request);          // removes card from player 2
                    handSize2--;
                    cout << p2.getName() << " says - Yes, I have a " << p1NewBook.toString() << endl;

                    p1.addCard(p1NewBook);                          // adds it to player 1's hand

                    p1.bookCards(p1Request, p1NewBook);
                    handSize1--;
                    cout << p1.getName() << " books the " << p1NewBook.toString() << endl << endl;
                }

                if (!sameRank2) {
                    cout << p2.getName() << " says - Go Fish!" << endl;

                    p1Draw = d.dealCard();
                    p1.addCard(p1Draw);
                    handSize1++;
                    cout << p1.getName() << "draws a " << p1Draw.toString() << endl << endl;

                    bool check = false;
                    check = checkforpairHelper(p1, handSize1);

                    if (check) {
               //         cout << p1.getName() << " books the " << p1Draw.toString() << endl << endl;

                    }


                    p1turn = false;
                    p2turn = true;
                }

                if (p1.getHandSize() == 0 && d.size() >= 1) {
                    Card pickup;
                    pickup = d.dealCard();
                    p1.addCard(pickup);
               //     cout << p1.getName() << " picks up a " << pickup.toString() << endl;
                   // cout << p1.showHand() << endl;
                }


        }



            while (p2turn == true &&Winner(p1,p2) == 0) {

                //if(Winner(p1,p2) == 0) {
                if (p2.getHandSize() == 0 && d.size() >= 1) {
                    Card pickup;
                    pickup = d.dealCard();
                    p2.addCard(pickup);
               //     cout << p2.getName() << " picks up a " << pickup.toString() << endl;
                    //cout << p2.showHand() << endl;
                }

                while (checkforpairHelper(p2, handSize2)) {

             //       cout << p2.getName() << " has a book " << endl;
               //     cout << p2.showBooks() << endl << endl;

                }


                p2Request = p2.chooseCardFromHand();
                cout << p2.getName() << " asks - Do you have any " << p2Request.getRank() << "'s?" << endl;

                sameRank1 = p1.sameRankInHand(p2Request);

                if (sameRank1) {
                    p2NewBook = p1.removeCardFromHand(p2Request);          // removes card from player 2
                    handSize1--;
                    cout << p1.getName() << " says - Yes, I have a " << p2NewBook.toString() << endl;

                    p2.addCard(p2NewBook);                          // adds it to player 1's hand
                    //p1.removeCardFromHand(p1Request);
                    p2.bookCards(p2Request, p2NewBook);
                    handSize2--;
                    cout << p2.getName() << " books the " << p2NewBook.toString() << endl<< endl;

                }

                if (!sameRank1) {
                    cout << p1.getName() << " says - Go Fish!" << endl;

                    p2Draw = d.dealCard();
                    p2.addCard(p2Draw);
                    handSize1++;
                    cout << p2.getName() << "draws a " << p2Draw.toString() << endl<< endl;

                    bool check = false;
                    check = checkforpairHelper(p2, handSize2);

                    if (check) {
               //         cout << p2.getName() << " books the " << p2Draw.toString() << endl << endl;

                    }

                    p2turn = false;
                    p1turn = true;

                }

                if (p2.getHandSize() == 0 && d.size() >= 1) {
                    Card pickup;
                    pickup = d.dealCard();
                    p2.addCard(pickup);
            //        cout << p2.getName() << " picks up a " << pickup.toString() << endl;
              //      cout << p2.showHand() << endl;
                }

        }


//        cout << endl << p1.getName() << "'s Hand has : " << p1.showHand() << endl;
//        cout << p2.getName() << "'s Hand has : " << p2.showHand() << endl;
//
//        cout << p1.getName() << " book : " << p1.showBooks() << endl;
//        cout << p1.getName() << " book size: " << p1.getBookSize() << endl<< endl;
//
//        cout << p2.getName() << " book : " << p2.showBooks() << endl;
//        cout << p2.getName() << " book size: " << p2.getBookSize() << endl<< endl;
//
//        cout << "Book size: " << p1.getBookSize() + p2.getBookSize() << endl;
//
//        cout << "Deck size: " << d.size() << endl;


    }


    int winner;
    winner = Winner(p1,p2);

    if(winner == 1 ){
        cout << p1.getName() << " wins!" << endl;
        oFile << p1.getName() << " wins!" << endl;

    }

    if(winner == 2 ){
        cout << p2.getName() << " wins!" << endl;
        oFile <<p2.getName() << " wins!" << endl;
    }

    if(winner == 3 ){
        cout << "It's a tie!" << endl;
        oFile << p2.getName() << " wins!" << endl;
    }

    oFile.close();

    return EXIT_SUCCESS;

}




int Winner(Player &p1, Player &p2){

    int p1bookSize, p2bookSize, total;
    p1bookSize = p1.getBookSize();
    p2bookSize = p2.getBookSize();

    total = p1bookSize + p2bookSize;


    if(total == 52){

        if(p1bookSize == p2bookSize){
            return 3;
        }

        if(p1bookSize > p2bookSize){
            return 1;
        }

            return 2;


    }
    return 0;
}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



bool checkforpairHelper(Player &p, int handSize){

//    for(int i = 0; i < handSize; i++){
//
//        for(int k = i +1; k < handSize; k++) {

            if(p.getHandSize() != 0) {
                Card c1, c2;
                bool check = false;
                check = p.checkHandForPair(c1, c2);

                if (check) {
                    p.bookCards(c1, c2);
                    return true;
                }
            }

    return false;
}



