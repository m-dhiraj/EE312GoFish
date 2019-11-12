#include "player.h"
#include <ctime>
#include <cstdlib>

using namespace std;

    void Player::addCard(Card c){
        myHand.push_back(c);
    }  //adds a card to the hand
    void Player::bookCards(Card c1, Card c2){
        myBook.push_back(c1);
        myBook.push_back(c2);
        removeCardFromHand(c1);
        removeCardFromHand(c2);
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool Player::checkHandForBook(Card &c1, Card &c2){
        if(checkHandForPair(c1, c2)){
            bookCards(c1, c2);
            return true;
        }
        return false;
    }

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    bool Player::rankInHand(Card c) const{
         for (int i = 0; i < myHand.size(); i++){
            if(myHand[i].getRank()==c.getRank())
            return true;
        }
        return false;
    }
    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card Player::chooseCardFromHand() const{
        
        srand((unsigned)time(0));
        int siz= myHand.size();
        if(siz==0){
            siz++;
        }
        int r=rand()%siz;
        
            return myHand[r];
        
    }
    
    //Does the player have the card c in her hand?
    bool Player::cardInHand(Card c) const{
        for (int i = 0; i < myHand.size(); i++){
            if(myHand[i].getRank()==c.getRank()){
            return true;
            }
        }
        return false;
        
    }
    
    //Remove the card c from the hand and return it to the caller
    Card Player::removeCardFromHand(Card c){
        for (int i = 0; i < myHand.size(); i++){
            if(myHand[i].getRank()==c.getRank()){
             Card c=myHand[i];
             myHand.erase(myHand.begin()+i);
             return c;
            }
        }
        
    }
    
    string Player::showHand() const{
        string print="";
        for(int i=0; i<myHand.size();i++){
            print+=myHand[i].toString();
            print+=" ";
        }
        return print;

    }
    string Player::showBooks() const{
        string print="";
        for(int i=0; i<myBook.size();i++){
            print+=myBook[i].toString();
            print+=" ";
        }
        return print;
    }
    
    int Player::getHandSize() const{
        return myHand.size();
    }
    int Player::getBookSize() const{
        return myBook.size()/2;
    }
       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool Player::checkHandForPair(Card &c1, Card &c2){
        for (int i = 0; i < myHand.size(); i++){
            for (int j = i+1; j < myHand.size(); j++){
                if(myHand[i].getRank()==myHand[j].getRank()){
                    c1=myHand[i];
                    c2=myHand[j];
                    return true;
                }
            }
        }
        return false;
        
    }

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    
    bool Player::sameRankInHand(Card c) const{
        for (int i = 0; i < myHand.size(); i++){
            
                if(myHand[i].getRank()==c.getRank()){
                    return true;
                }
            
        }
        return false;
    }
    