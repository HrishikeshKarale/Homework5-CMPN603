#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  vector< Hand > hands;
  Deck deck;
  int players; 
  int seed;
  int sizeOfHand = 5;
  int total_cards_to_distribute;

  cout << "Enter seed: ";
  cin >> seed;
  srand(unsigned(seed));

  cout << "Enter number of players: ";
  cin >> players; 
   
  //resizes vector hands to the no of players playing the game.
  hands.resize(players);
   
  //calculates and stores total no of cards to be dealt during the game.
  total_cards_to_distribute = sizeOfHand * players;

  deck.Shuffle();

  //vector is made of type Card and initialized to total no of cards distributed
  vector<Card> cards_to_distribute(total_cards_to_distribute);
  //vector is initialized by calling Deck::deal() which returns a vector or cards
  cards_to_distribute = deck.Deal(total_cards_to_distribute);

  /*
  * cards from the vector cards_to_distribute are distributed to the players in
  * a round-robin 
  */
 for(int i=0; i<hands.size(); i++)
   for(int j=0;j<total_cards_to_distribute;j++)
   {
     if(j%players==i)
     {
      //Hand::add() is called on hand[] which send current card as parameter.
       hands[i].add(cards_to_distribute[j]);
       j=j+players-1;
     }
   }

  /*
  * This block of code displays cards of our player and checks for 
  * poker hands for his respective cards.
  */
  for(int i=0; i<hands.size(); i++)
 {  
    cout << "Player " << (i+1) << " Hand: ";
    //Hand::showHand() is called which displays cards of our respective player
    hands[i].showHand();
    /*
    * Hand::check() is called on current hand[] which checks for poker hands
    * and displays the highest values poker hand.
    */
    hands[i].check();
    cout << endl;
  }

  /*
  * The commented block below displays the remaining cards in the deck after
  * players have been given their cards.
  */
	//deck.ShowDeck();

}
