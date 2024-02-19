all: output run

output: card.o deck.o main.o
	g++ main.o linkedlist.o card.o deck.o -o output

run:
	./output

main.o: main.cpp deck.hpp
	g++ -c main.cpp

deck.o: card.hpp linkedlist.hpp
	g++ -c deck.cpp

card.o: card.cpp
	g++ -c card.cpp

clean:
	rm *.o