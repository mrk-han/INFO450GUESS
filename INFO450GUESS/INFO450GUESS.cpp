// INFO450GUESS.cpp : Find the gold, dodge the bomb, win big!  If the user finds a piece of gold, they get an extra guess!
//

#include "stdafx.h"
#include <iostream>
#include <time.h> // Used for seeding

using namespace std;

//Define variables needed here
const int ROWS = 8;
const int COLUMNS = 8;
const int BOMB = 1; // For logic in placing bomb on array, place 1 bomb.
const int MAX_GUESSES = 5; // For logic in guessing, user gets to guess until they reach max guesses
const int MAX_GOLD = 5; // For logic in placing gold on array, place gold until MAX_GOLD = 5
char guessArray[ROWS][COLUMNS];
char answer; // Would you like to play again answer



int main()

{


	do

	{

		// Insert Logic Here
		// Maybe can put lopgic below main() and break elements of game into methods

		// Display Board
		
		// Explain Rules

		// Ask for coordinate entry from user
		// If they find gold, give them an extra guess and add a point
		// If they find bomb, break out of loop and end game.
		// If they don't find anything, say guess again


		cout << "Would you like to play Again? Enter 'Y' or 'y'";
		cin >> answer;

	} while (answer == 'Y' || answer == 'y');



	return 0;

}

