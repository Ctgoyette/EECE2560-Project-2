
all: output run

output: main.o card.o deck.o node.o
	g++ main.o card.o deck.o node.o -o output

run:
	output

main.o: main.cpp deck.hpp linklist.hpp
	g++ -c main.cpp

card.o: card.cpp card.hpp 
	g++ -c card.cpp

deck.o: deck.cpp deck.hpp linklist.hpp
	g++ -c deck.cpp

node.o: node.cpp
	g++ -c node.cpp

clean:
	rm *.o