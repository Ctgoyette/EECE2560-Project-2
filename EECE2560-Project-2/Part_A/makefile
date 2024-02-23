all: output run

output: main.o card.o deck.o
	g++ main.o card.o deck.o -o output

run:
	./output

main.o: deck.hpp main.cpp
	g++ -c main.cpp

deck.o: card.hpp deck.hpp linkedlist.hpp
	g++ -c deck.cpp

card.o: card.cpp
	g++ -c card.cpp

clean:
	rm *.o