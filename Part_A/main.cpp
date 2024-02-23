#include <iostream>
#include "deck.hpp"

using namespace std;

//Creates a new deck, prints the deck, shuffles the deck, and then prints the shuffled deck
int main()
{
    Deck deck = Deck();  

    cout << "----Before Shuffle:----\n" << deck << endl;
    deck.shuffle();
    cout << endl << endl << "----After Shuffle:----\n" << deck << endl << endl;
}