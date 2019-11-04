
#include <iostream>
#include <string>
#include "card.h"
using namespace std;

    Card::Card(){
        myRank=0;
        mySuit=spades;
    }

    Card::Card(int rank, Suit s){
        myRank=rank;
        mySuit=s;
    }

    string Card::toString()              const  // return string version e.g. Ac 4h Js
    {
        return rankString(myRank)+suitString(mySuit);
    }
    bool Card::sameSuitAs(const Card& c) const  // true if suit same as c
    {
        if((c.myRank==myRank)&&(c.mySuit==mySuit))
        return true;
        return false;
    }
    int  Card::getRank()                 const  // return rank, 1..13
    {
        return myRank;
    }
    string Card::suitString(Suit s)      const  // return "s", "h",...
    {
        string p ="";
        if(s==spades)
        p="s";
        else if(s==hearts)
        p="h";
        else if(s==diamonds)
        p="d";
        else if(s==clubs)
        p="c";
        return p;

    }    
    string Card::rankString(int r)       const  // return "A", "2", ..."Q"  
    {
        if(r==1)
        return "A";
        else if(r==11)
        return "J";
        else if(r==12)
        return "Q";
        else if(r==13)
        return "K";
        else if(r==2)
        return "2";
        else if(r==3)
        return "3";
        else if(r==4)
        return "4";
        else if(r==5)
        return "5";
        else if(r==6)
        return "6";
        else if(r==7)
        return "7";
        else if(r==8)
        return "8";
        else if(r==9)
        return "9";
        else if(r==10)
        return "10";
    } 
    
    bool Card::operator == (const Card& rhs) const
    {
        if((myRank==rhs.myRank)&&(sameSuitAs(rhs)))
        return true;
        else
        return false;
    }
    bool Card::operator != (const Card& rhs) const
    {
        if(rhs.myRank==myRank&&rhs.mySuit==mySuit)
        return false;
        else
        return true;
    }
    ostream& operator << (ostream& out, const Card& c){
        out << c.toString() << endl;
        return out ;
    }