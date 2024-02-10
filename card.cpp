#include "card.hpp"



Card::Card()
{
        valueMap[2] = "2";
        valueMap[3] = "3";
        valueMap[4] = "4";
        valueMap[5] = "5";
        valueMap[6] = "6";
        valueMap[7] = "7";
        valueMap[8] = "8";
        valueMap[9] = "9";
        valueMap[10] = "10";
        valueMap[11] = "Jack";
        valueMap[12] = "Queen";
        valueMap[13] = "King";
        valueMap[14] = "Ace";
    
        suitMap[0] = "Clubs";
        suitMap[1] = "Diamonds";
        suitMap[2] = "Hearts";
        suitMap[3] = "Spades";
};


void Card::setSuit(int key)
{
    cardSuit = suitMap[key];
};


void Card::setValue(int key)
{
    cardValue = valueMap[key];
}


string Card::getSuit()
{
    return cardSuit;
}


string Card::getValue()
{
    return cardValue;
}


ostream& operator<< (ostream& out, const Card& outputCard){
    out << outputCard.cardValue << " of " << outputCard.cardSuit;
    return out;
}