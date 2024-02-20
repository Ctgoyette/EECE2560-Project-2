#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include <iostream>
#include <time.h>
#include "card.hpp"
#include "linkedlist.hpp"

using namespace std;

class Deck
{
    public:
        Deck();
        ~Deck();

        /**
         * @brief Shuffles the order of the linked list by randomly selecting an index
         * and sending that card to the back. Process is repeated 200 times.
         * 
         */
        void shuffle();

        /**
         * @brief Erases the card pointed to by the curr pointer of cards
         * Note: Not currently used
         * 
         */
        void removeCard();

        /**
         * @brief Inserts input parameter card at the last element in cards
         * 
         */
        void replace(Card&);

        /**
         * @brief Draws the top card of the deck, removing it from the list
         * 
         * @return Card 
         */
        Card deal();

        /**
         * @brief Outputs one card at a time each on a new line
         * 
         * @param out 
         * @return ostream& 
         */
        friend ostream& operator<< (ostream& out, const Deck&);

        

    private:
        // The linked list containing all cards
        LinkedList<Card> *cards = new LinkedList<Card>;
        // The current number of cards in the deck
        // NOTE MAKE SURE TO UPDATE THIS VALUE WHEN LENGTH OF CARDS IS CHANGED
        int numCards;
        Node<Card> *head;
        
};

#endif