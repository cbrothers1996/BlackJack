#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Hand.h"
#include <ctime>
#include <cstdlib>

enum Hit_or_Stand { HIT, STAND };

class Blackjack
{
  private:
    double playerMoney, playerBet;
//  Objects of class Hand representing the player's hand and the dealer's hand. playerHand 2 is second hand if splitting a pair
    Hand playerHand, dealerHand;
//  An object of enumerated type Hit_or_Stand that holds the player's choice.
    Hit_or_Stand playerChoice;

//  Member function to obtain the player's choice.
    Hit_or_Stand queryPlayer(); //  keep querying the player until a valid choice is
                                //   entered, then return that choice as a Hit_or_Stand. 
	bool doubleDown(double* bet); //Player can double down if he only has two cards which will double his bet 
								  //but only allow his hand to be dealt one additional card before being forced to stand
       

  public:
    Blackjack(double money)
     :playerMoney(money), playerHand("Player"), dealerHand("Dealer")
    { }


//   Member function 'play' plays a round of Blackjack according to the rules
//    of the game, and returns the updated playerMoney. 
    double play(double bet); 
};

#endif
