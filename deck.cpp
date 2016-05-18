#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck()
{
   Shuffle();
}

void Deck::Shuffle()
{
	cards.erase(cards.begin(), cards.end());
    for ( int i = Card::CLUBS; i <= Card::SPADES; i++ )
    {
       for ( int j = Card::TWO; j <= Card::ACE; j++ )
       {
          cards.push_back( Card(Card::SUITS(i),Card::COUNT(j)));
       }
    }
    random_shuffle ( cards.begin(), cards.end() );
}

/* Your code here */

/*
* This function displays the deck of cards that remain after all the players
* have been given their cards.
*/
void Deck::ShowDeck()
{
  for ( int i = 0; i <= cards.size()-1; i++ )
  {
    cout <<(i+1)<<" --> " << cards[i].str() <<endl;
  }
  cout << "\n" << endl;
}

/*
*This function takes in no of cards to deal as parameter and then returns a
* vector containing that many cards to the calling function.
*/
std::vector<Card> Deck::Deal( int count )
{
  //Initialized to parameter cout.
	int no_of_cards = count;
  //Vector is made of size equal to the no of cards to be dealt.
	std::vector<Card> cards_to_deal(no_of_cards);

  /*
  * This block of code stores cards from  vector cards to vector cards_to_deal
  * and then removes the card from the vector, as it has already been dealt. 
  */
  for(int i=0;i<no_of_cards;i++)
  {
    cards_to_deal[i]= cards[0];
    /*
    * erase(int) is called on vector cards which erases the value at the index  
    * position provided by cards.begin() which returns first index position.
    */
    cards.erase( cards.begin() );
  }
  return cards_to_deal;
}
