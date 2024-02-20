#include "deck.hpp"

Deck::Deck()
{   
    numCards = 0;

    // Loops through every card value
    for (int i = 2; i < 15; i++)
    {
        // Loops through every card suit
        for (int j = 0; j < 4; j++)
        {   
        
            // Creates a card object and inserts it the end of the list
            Card temp = Card();
            temp.setSuit(j);
            temp.setValue(i);
            cards.addLast(temp);
            numCards ++;
        }
    }
    head = cards.getHead();
}


Deck::~Deck()
{
    Node<Card> *delCard = cards.getHead();
    while (delCard != NULL)
    {
        head = head->next;
        cards.setHead(head);
        delete delCard;
        delCard = head;
        numCards--;
    }
    head = nullptr;
}

void Deck::shuffle()
{
    // Seeds the rand generator
    srand(time(NULL));
    for (int i = 0; i < 200; i++)
    {
        // Generates a random number between 1 and the number of cards inclusive
        int randValue = rand()%numCards + 1;
        // Moves the card at that index to end of list
        cards.addLast(cards.popNode(randValue));
    }
    head = cards.getHead();
}


ostream& operator<< (ostream& out, const Deck& outputDeck){
    if (outputDeck.numCards > 0)
    {
        out << outputDeck.cards;
    }
    else
    {
        out << "Deck is EMPTY";
    }
    return out;
}


void Deck::removeCard()
{
    // Erases node at curr pointer
    cards.erase_element();
    numCards--;
    head = cards.getHead();
}


Card Deck::deal()
{
    Card card = cards.popNode(1);
    head = cards.getHead();
    return card;
}


void Deck::replace(Card& value)
{
    cards.addLast(value);
    head = cards.getHead();
    numCards++;
}