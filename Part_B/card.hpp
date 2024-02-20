#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>
#include <map>

using namespace std;

class Card
{
    public:
        Card();
        Card(const Card& copiedCard);

        /**
         * @brief Set the card value ie. 2-Ace
         * 
         * @param key: an integer key of value 2 through 14 inclusive that sets card value based on map
         */
        void setValue(int key);

        /**
         * @brief Set the card suit ie. Clubs, Hearts, Diamonds, or Spades
         * 
         * @param key: an integer key of value 0 through 3 inclusive that sets card suit based on map
         */
        void setSuit(int key);

        /**
         * @brief Returns a string object of the card's suit
         * 
         * @return string 
         */
        string getSuit() const;

        /**
         * @brief Returns a string object of the card's value
         * 
         * @return string 
         */
        string getValue() const;

        /**
         * @brief Overloads cout to the form of "4 of Clubs" or "Value of Suit"
         * 
         * @param out 
         * @return ostream& 
         */
        friend ostream& operator<< (ostream& out, const Card&);

        Card& operator= (const Card& baseCard);

    private:
        string cardSuit;
        string cardValue;
        
        // Maps an integer key to a card value such as 3, 9, Jack, or Queen
        map<int, string> valueMap;
        // Maps an integer key to a card suit such as Clubs
        map<int, string> suitMap;
};

#endif