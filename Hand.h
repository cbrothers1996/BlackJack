#ifndef HAND_H
#define HAND_H

// Definition of class Hand, but only function prototypes included

#include <iostream>
#include <string>
#include "Card.h"


class Hand 
{
private:
   int value;   //  This should hold the total value of the hand.  Update every time you
                //   add a card 
   int number_of_aces;  //  this should hold the number of Aces in the hand, which is
                        //   useful for calculating hand value.  Update every time you
                        //   add a card
   int number_of_cards;  //  this should hold the total number of cards in the hand.
                         //   Update every time you add a card.
   Card * cards[11];  //  an array of 11 Card pointers to point to the hand's cards.
   std::string hand_holder;  // Holds either "Player" or "Dealer"

   void updateValue();  // Private member function that updates the hand's value.
                        //   It should be called every time a card is added.

public:
   explicit Hand(std::string);  // Constructor, sets hand_holder.  
   ~Hand();  //  Destructor.  Deallocates all cards.  
   Hand & operator++();  //  Adds a randomly chosen card to the hand.  It does so using
                         //   a random number generator, and must use the command 'new'
                         //   to dynamically allocate a new Card. 
//  Below are a set of overloaded operators for comparing the value of a Hand to the 
//   value of another Hand, or to an int.  
   bool operator>(const Hand & rhs) const;  
   bool operator>(int rhs) const;
   bool operator<(const Hand & rhs) const;
   bool operator<(int rhs) const;
   bool operator==(const Hand & rhs) const;
   bool operator==(int rhs) const;
   void printHand();  //  This function prints the cards in the hand, and the total
                      //    value of the hand.   
   void printFirstCard();  // This function prints only the first card in the hand 
                           //  (used for dealer). 

//   It is necessary to write our own copy constructor because of the dynamically
//   allocated memory in this class 
   Hand (const Hand & hand_to_copy) 
     : hand_holder(hand_to_copy.hand_holder), number_of_aces(hand_to_copy.number_of_aces), 
       number_of_cards(hand_to_copy.number_of_cards), value(hand_to_copy.value) 
   { 
     for (int i = 0; i < number_of_cards; i++)
        cards[i] = new Card(*(hand_to_copy.cards[i]));
   }
   void operator= (const Hand & hand_to_copy)  
   { 
     for (int i = 0; i < number_of_cards; i++)
       delete cards[i];
     hand_holder = hand_to_copy.hand_holder;
     number_of_aces = hand_to_copy.number_of_aces;
     number_of_cards = hand_to_copy.number_of_cards;
     value = hand_to_copy.value;
     for (int i = 0; i < number_of_cards; i++)
       cards[i] = new Card(*(hand_to_copy.cards[i]));
   } 
};

#endif
