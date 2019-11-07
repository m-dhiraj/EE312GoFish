#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
    Deck::Deck(){
        for(int i=0;i<13;i++){
            Card c1(i+1, Card::spades);
            myCards[i]=c1;
            Card c2(i+1, Card::hearts);
            myCards[i+13]=c2;
            Card c3(i+1, Card::diamonds);
            myCards[i+26]=c3;
            Card c4(i+1, Card::clubs);
            myCards[i+39]=c4;
        }
        
        myIndex=51;
        srand((unsigned)time(0));


    }           // pristine, sorted deck

    void Deck::shuffle() {
        
        for(int i=0;i<myIndex*3;i++)
        {
            int index1= rand()%myIndex;
            int index2= rand()%myIndex;
            Card temp=myCards[index1];
            myCards[index1]=myCards[index2];
            myCards[index2]=temp;
        }
    }  // shuffle the deck, all 52 cards present
    Card Deck::dealCard(){
            Card c=myCards[myIndex];
            myIndex--;
            return c;
        
    }   // get a card, after 52 are dealt, fail 

    int  Deck::size() const{
        return myIndex;
    }