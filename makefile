final: myDriver.o card.o deck.o player.o
	g++ -otest myDriver.o card.o deck.o player.o
driver: myDriver.cpp card.h deck.h
	g++ -c myDriver.cpp
card.o: card.cpp card.h 
	g++ -c card.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
player.o: player.cpp card.h
	g++ -c player.cpp