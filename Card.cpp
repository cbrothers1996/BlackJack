#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(){
	

int random = rand() % 12;
const string ranks[] { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const int temp[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
typeString = ranks[random];
initial_value = temp[random];

}

string Card::getType() const{
	return typeString;
} 

int Card::getValue() const{
	return initial_value;
}
