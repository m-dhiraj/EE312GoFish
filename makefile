final: myDriver.o card.o deck.o
	g++ -otest myDriver.o card.o deck.o
driver: myDriver.cpp card.h deck.h
	g++ -c myDriver.cpp
card.o: card.cpp card.h 
	g++ -c card.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp