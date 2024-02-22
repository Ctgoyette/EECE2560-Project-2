#include <iostream>
#include "deck.hpp"

using namespace std;

int main()
{
    Deck deck = Deck();  

    cout << "----Before Shuffle:----\n" << deck << endl;
    deck.shuffle();
    cout << endl << endl << "----After Shuffle:----\n" << deck << endl << endl;
}