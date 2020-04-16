final: GoFish_Driver.o player.o deck.o card.o
	g++ -o final  GoFish_Driver.o player.o deck.o card.o
driver: GoFish_Driver.cpp player.h deck.h card.h
	g++ -std=c++11 -c GoFish_Driver.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -std=c++11 -c player.cpp
deck.o: deck.cpp deck.h 
	g++ -std=c++11 -c deck.cpp
card.o: deck.cpp card.h
	g++ -std=c++11 -c card.cpp