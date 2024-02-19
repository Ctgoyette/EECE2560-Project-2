#include <iostream>
#include "deck.hpp"

using namespace std;

int main()
{
    Deck deck = Deck();  

    cout << deck << endl;
    deck.shuffle();
    cout << endl << endl << deck << endl << endl;
}