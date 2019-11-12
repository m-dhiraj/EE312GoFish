#include <cstdlib>
#include <string>
#include <iostream>
#include "card.h"
#include "deck.h"
#include <vector>
#include <fstream>
#include "player.h"

using namespace std;
int checkGameStatus(Player p1, Player p2, Deck d){
    cout<<" * ";
    if((d.size()<0&&(p1.getBookSize()+p2.getBookSize()==26)))
        return 1;
    return 0;
}
int main(int argc, char *argv[])
{
    ofstream file;
    file.open("gofish_results.txt");
    cout<<"Playing";
    Deck d;
    d.shuffle();
    Player p1("Geoffery");
    Player p2("Sameer");
    Card c1;
    Card c2;
    bool PLAYING =true;
    bool p1CONT=false;
    bool p2CONT=false;

    for(int i=0; i< 7;i++){
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }
    
    while (p1.checkHandForBook(c1,c2)){
        file<<p1.getName()<<" books the "<<c1.rankString(c1.getRank())<<endl;
        file<<endl;
    }
    while (p2.checkHandForBook(c1,c2)){
        file<<p2.getName()<<" books the "<<c1.rankString(c1.getRank())<<endl;
        file<<endl;
    }
    while(checkGameStatus(p1, p2, d)==0){
        if(p1.getHandSize()==0&&d.size()>=0)
        p1.addCard(d.dealCard());
        else if(checkGameStatus(p1, p2, d)==0&&p1.getHandSize()>0){
        do{
            c1=p1.chooseCardFromHand();
            file<<p1.getName()<<" asks - do you have a "<<c1.rankString(c1.getRank())<<endl;
            if(p2.cardInHand(c1)){
                file<<p2.getName()<<" says - yes I have a "<<c1.rankString(c1.getRank())<<endl;
                file<<p1.getName()<<" books the "<<c1.rankString(c1.getRank())<<endl;
                file<<endl;
                c2=p2.removeCardFromHand(c1);
                p1.addCard(c2);
                p1.checkHandForBook(c1,c2);
                p1CONT=true;
            }
            else{
                file<<p2.getName()<<" says - Go Fish!"<<endl;
                if(d.size()>=0){
                c1=d.dealCard();
                p1.addCard(c1);
                file<<p1.getName()<<" draws a "<<c1.toString()<<endl;
                file<<endl;}
                p1CONT=false;
                p2CONT=true;
                if(p1.checkHandForBook(c1,c2))
                file<<p1.getName()<<" books the "<<c1.rankString(c1.getRank())<<endl;
                file<<endl;
            }
            
        }while(p1CONT==true);
        
        
    }
     if(p2.getHandSize()==0&&d.size()>=0)
        p2.addCard(d.dealCard());
         else if(checkGameStatus(p1, p2, d)==0&&p2.getHandSize()>0){
        do{
            c1=p2.chooseCardFromHand();
            file<<p2.getName()<<" asks - do you have a "<<c1.rankString(c1.getRank())<<endl;
            if(p1.cardInHand(c1)){
                file<<p1.getName()<<" says - yes I have a "<<c1.rankString(c1.getRank())<<endl;
                file<<p2.getName()<<" books the "<<c1.rankString(c1.getRank())<<endl;
                file<<endl;
                c2=p1.removeCardFromHand(c1);
                p2.addCard(c2);
                p2.checkHandForBook(c1,c2);
                p2CONT=true;
            }
            else{
                file<<p1.getName()<<" says - Go Fish!"<<endl;
                if(d.size()>=0){
                c1=d.dealCard();
                p2.addCard(c1);
                file<<p2.getName()<<" draws a "<<c1.toString()<<endl;
                file<<endl;}
                p2CONT=false;
                p1CONT=true;
                if(p2.checkHandForBook(c1,c2))
                file<<p2.getName()<<" books the "<<c1.rankString(c1.getRank())<<endl;
            }
           
        }while(p2CONT==true);
        
        
    }
    }
    if(checkGameStatus(p1,p2,d)==1){
        file<<"The Deck Has Run Out of Cards!!!"<<endl;
        file<<p1.getName()<<"'s hand :"<<p1.showHand()<<endl;
        file<<p2.getName()<<"'s hand :"<<p2.showHand()<<endl;
        file<<p1.getName()<<"'s books :"<<p1.showBooks()<<endl;
        file<<p2.getName()<<"'s books :"<<p2.showBooks()<<endl;
        file<<p1.getName()<<"'s book size :"<<p1.getBookSize()<<endl;
        file<<p2.getName()<<"'s book size :"<<p2.getBookSize()<<endl;
        if(p1.getBookSize()>p2.getBookSize())
        file<<p1.getName()<<" WINS!"<<endl;
        else if(p2.getBookSize()>p2.getBookSize())
        file<<p2.getName()<<" WINS!"<<endl;
        else if(p1.getBookSize()==p2.getBookSize())
        file<<"ITS A TIE!"<<endl;

        cout<<endl;
        cout<<p1.getName()<<"'s deck :"<<p1.getBookSize()<<endl;
        cout<<p2.getName()<<"'s deck :"<<p2.getBookSize()<<endl;

    }
    file.close();
    return 0;

}