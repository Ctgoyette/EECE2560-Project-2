#include <iostream>
#include "deck.hpp"
#include <limits>

using namespace std;

int updateScore(float& playerScore, const Card& card)
{
    string val = card.getValue();
    if (val == "6" || val == "5" || val == "4" || val == "3" || val == "2")
    {
        playerScore = 0;
    }
    else if(val == "7")
    {
        playerScore = playerScore/2;
    }
    else if(val == "King" || val == "Queen" || val == "Jack")
    {
        playerScore += 5;
    }
    else if(val == "Ace")
    {
        playerScore += 10;
    }

    if (card.getSuit() == "Hearts")
    {
        playerScore += 1;
    }
    return playerScore;
}

void playFlip()
{
    Deck *gameDeck = new Deck();
    LinkedList<Card> *playerDeck = new LinkedList<Card>;
    LinkedList<Card> *playerHand = new LinkedList<Card>;
    float playerScore = 0.0;
    char userChoice;
    

    for (int i = 0; i < 3; i++)
    {
        gameDeck->shuffle();
    }

    cout << "----Game Deck:----\n" << *gameDeck << endl;

    for (int i = 0; i < 24; i++)
    {
        Card temp = Card(gameDeck->deal());
        playerDeck->addLast(temp);
    }

    cout << "----Top 24 Cards:----\n" << *playerDeck << endl;
    cout << "----Remaining Deck:----\n" << *gameDeck << endl;

    cout << "Welcome to Flip!" << endl;

    for (int i = 0; i < 24; i++)
    {
        cout << "\nCard #" << i+1 << "\nWould you like to flip this card or end the game?\nEnter 'f' to flip or 'e' to end the game" << endl;
        userChoice = cin.get();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (userChoice == 'f')
        {
            Card temp = Card(playerDeck->popNode(1));
            playerScore = updateScore(playerScore, temp);
            playerHand->addLast(temp);

            cout << "\n----Player Hand:----\n" << *playerHand << endl;
            cout << "Current Score: " << playerScore << endl;
        }
        else if (userChoice == 'e')
        {
            break;
        }
        else{
            cout << "Please enter a valid input ('f' or 'e')" << endl;
            i--;
        }
    }

    cout << "Thanks for playing!" << endl;
    cout << "Your final score was: " << playerScore << endl;
}

int main()
{
    playFlip();
    return 0;
}