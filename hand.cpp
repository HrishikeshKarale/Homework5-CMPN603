#include "hand.h"
#include <iostream>


using namespace std;


/* Your code here */

/*
* This function has a Card parameter and it that card to the cards vector.
*/
void Hand::add( Card card )
{
	//push_back() of vector is called on cards vector which adds parameter
	//card to the vector its called on.
	cards.push_back(card);
}

/*
* This function displays all the cards for a particular player from vector cards.
*/
void Hand::showHand()
{
	//this block of code displays the cards alighned to the right. 	
	for(int i=0; i<cards.size(); i++)
	{
		//character space of 6 is assigned to every cout.
		std::cout.width(6);
		//std::right aligns the output to the right of the width of cout.
 		std::cout << std::right << cards[i].str();
	}
}

/*
* This function is responsible for checking poker hands of our respective players
* it checks for five types of poker hands whic hare 'Four of a kind', 'Flush',
* 'Three of a Kind', 'Two Pair' and 'One Pair' respectively accordint to their
* hierarchy of importance.
*/
void Hand::check()
{
	//counter to access different cards in vector cards for flush condition.	
    int k=1;
	int flush = 0;
	int four_of_a_kind = 0;
	int pair=0;

	/*
    * This block of code checks if the cards of our player have a 
    * 'Four of a Kind' poker hand  by comparing values of all its cards.
    */
    for(int i=0;i<3;i++)
    {
    	//Initialize the count of four_of_a_kind variable to 1.
    	four_of_a_kind=1;
    	
    	for(int j=i+1;j<cards.size();j++)
        {
        	//Compare the values of the cards
            if(cards[i].getValue()==cards[j].getValue())
            {
                four_of_a_kind++;
            }
        }
        //this block of code breaks the for loop if four_of_a_kind variable reaches 4
        if(four_of_a_kind==4)
        {
          break;
        }
	}
	/*
	* this block of code bleow checks if the value of four_of_a_kind variable is 4, 
	* if its found to be four then it displays that the player hold's a poker hand of
	* 'Four of a Kind' and then a return statement is run so that it doesnt check for
	* other poker hands.
	*/
	if(four_of_a_kind==4)
	{
		cout<<"  Four of a Kind";
		return;
	}


	/*
	* The code block below checks if the counter k  is less than size of our
	* players cards and then increases count of flush variable if suit's of
	* players cards match each other
	*/
	while(k<cards.size())
	{
		//checks if suits of cards match.
		if(cards[0].getSuit()==cards[k++].getSuit())
		{
			flush++;
		}
	}
	//checks if value of flush variable is equal to total no of cards
	if(flush==cards.size())
	{
		cout<<"  Flush";
		return;
	}


	/*
	* this block of code bleow checks if the value of four_of_a_kind variable is 3, 
	* if its found to be four then it displays that the player hold's a poker hand of
	* 'Three of a Kind' and then a return statement is run so that it doesnt check for
	* other poker hands.
	*/
	if(four_of_a_kind==3)
	{
		cout<<"  Three of a Kind";
		return;
	}


	/*
	* This block of code checks if the cards of our user has one or more pairs in his
	* hand of cards and incereases the counter of pair if a pair of cards is found.
	*/
    for(int i=0; i<cards.size(); i++)
	{
		for(int j=i+1; j<cards.size(); j++)
		{
			//checks if two cards have same value or not
			if(cards[i].getValue()==cards[j].getValue())
			{
				pair++;
				break;
			}
		}
	}
	//checks for value of pair variable and implements code within if condition is found true;
	if(pair==2)
	{
		cout<< "  Two Pair";
	}
	else if(pair==1)
	{
		cout<< "  One Pair";
	}
			
}