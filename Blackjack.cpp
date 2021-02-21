#include "Blackjack.h"
#include "Hand.h"
#include <iostream>
#include <string>

using namespace std;


Hit_or_Stand Blackjack::queryPlayer(){
	cout << "What would you like to do? Enter (h)it or (s)tand: ";
	string temp;
	cin >> temp;
	 // Prompt user to hit or stand, put their input into playerChoice, and display it
	

	if (temp == "h" || temp == "hit") {
		playerChoice = HIT;
		++playerHand; // Perform a hit by adding card to hand and updating value
	}
	else if(temp == "s" || temp == "stand")
		playerChoice = STAND;
	else {
		cout << "Unrecognized value! Please enter again." << endl;
		queryPlayer();
	}
	cout << endl;
	return playerChoice; // Return their response as a Hit_or_stand type	
}

bool Blackjack::doubleDown(double *b) {
	if (playerMoney > (*b * 2) || playerMoney == (*b * 2)) {
		cout << "Would you like to double down? (Y)es or (N)o: ";
		string choice;
		cin >> choice;
		if (choice == "Y" || choice == "y" || choice == "yes" || choice == "Yes") {
			*b = *b * 2;
			++playerHand; //add only one card to player hand and print it
			playerHand.printHand();
			return true;
		}
		else
			return false;
	}
	else 
		return false;
}	

//void Blackjack::split() {
	//Hand playerHand2 = playerHand;
//}


double Blackjack::play(double bet){
	
	//  1. Deal 2 cards each to player and dealer and update values
	++playerHand;
	++playerHand;
	++dealerHand;
	++dealerHand;
	
	//  2. Display one of the dealer's cards and both of your own cards and value
	dealerHand.printFirstCard();
	playerHand.printHand();
	
	//  3. Ask user to hit or stand
	if (playerHand == 21) {
		cout << "Blackjack! Player Wins!" << endl;// Don't ask player to hit or stand if they have blackjack
		playerMoney = playerMoney + bet*1.5;
	}
	else {
		//split();
		bool DD = doubleDown(&bet);
		if (DD)
			goto dbldwn; //If player chooses to double down don't query him
		queryPlayer();
		while (playerChoice == HIT) { // Keep looping while user enters hit
			playerHand.printHand();
			if (playerHand == 21 || playerHand > 21)
				break; // Break from loop if player busts or gets 21
			else
				queryPlayer(); // Keep querying player if he doesn't bust
		}
		
		dbldwn:
		//  4. Print both dealer's cards and play out dealer's turn
		dealerHand.printHand();
		while (dealerHand < 17) { // Dealer hits automatically until his hand is 17 or higher
			++dealerHand;
			dealerHand.printHand();
		}

		//  5. Check win condition, print winner and update money

		if (playerHand > dealerHand) { 
			if (playerHand > 21) { //If player busts
				playerMoney = playerMoney - bet;
				cout << "Player's hand is bust" << endl;
			}

			else { //If player's hand is greater than the dealer's AND he didn't bust
				playerMoney = playerMoney + bet;
				cout << "Player Wins!" << endl;
			}
		}

		else if (playerHand < dealerHand) { 
			if (dealerHand > 21) { //If dealer busts and player doesn't bust
				playerMoney = playerMoney + bet;
				cout << "Dealer's hand is bust. Player Wins!" << endl;
			}
			else { //Neither busted but player's hand was less than dealer's hand
				playerMoney = playerMoney - bet;
				cout << "Dealer Wins." << endl;
			}
		}

		else
			cout << "Push" << endl; // If neither busts and both Hand values are equal
	}
	cout << "Player has " << playerMoney << " dollars" << endl;
	
	//  6. Remove all cards from each player's hand by calling the destructor and play again
	return playerMoney;
}


	
