#include <iostream>
#include "Hand.h"

using namespace std;

Hand::Hand(std::string temp) : hand_holder(temp) {
	value = 0;
	number_of_cards = 0;
	number_of_aces = 0;
}

Hand::~Hand(){
	for (int i = 0; i < number_of_cards; i++)
		delete cards[i];
}

void Hand::updateValue(){
	value += cards[number_of_cards]->getValue();
}


Hand& Hand::operator++(){
	 // Add more elements to cards
	cards[number_of_cards] = new Card(); // increase the array's size by one
	updateValue();
	
	if (cards[number_of_cards]->getValue() == 11) { //if card is an ace
		number_of_aces++; // increment number of aces if the card is an ace
		if (value > 21)
			value = value - 10;// Change ace's value to 1 if it makes hand bust
	}
	number_of_cards++;
	return *this;
}

bool Hand::operator>(const Hand & rhs) const { //Overload greater than operator for comparing value of one Hand to another Hand
	return (value > rhs.value);
}


bool Hand::operator>(int rhs) const { //Overload greater than operator for comparing value of one Hand to an int
	return(this->value > rhs);
}

bool Hand::operator<(const Hand & rhs) const { //Overload less than operator for comparing value of one Hand to another Hand
	return (value < rhs.value);
}

bool Hand::operator<(int rhs) const { //Overload less than operator for comparing value of one Hand to an int
	return(this->value < rhs);
}

bool Hand::operator==(const Hand & rhs) const { //Overload equivalent operator for comparing value of one Hand to another Hand
	return (value == rhs.value);
}

bool Hand::operator==(int rhs) const { //Overload equivalent operator for comparing value of one Hand to an int
	return(this->value == rhs);
}


void Hand::printFirstCard(){
	cout << "Dealer's first card is: " << cards[0]->getType() << endl << endl;
}

void Hand::printHand(){
	cout << hand_holder << "'s hand is: "; 
	for(int i = 0; i < number_of_cards; i++){
		cout << cards[i]->getType() << " ";
	}
	cout << endl << hand_holder << "'s hand value is: " << value << endl << endl;
}









