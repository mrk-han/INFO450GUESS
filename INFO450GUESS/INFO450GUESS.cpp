// INFO450GUESS.cpp : Find the gold, dodge the bomb, win big!  If the user finds a piece of gold, they get an extra guess!
//

#include "stdafx.h"
#include <iostream>
#include <time.h> // Used for seeding
#include <iomanip>  // setw() : Setting field width Using Cout in C++ Programming. 
					// setw() is library function in C++. setw() is declared inside #include<iomanip> setw() will set field width.
					// setw() sets the number of characters to be used as the field width for the next insertion operation.

using namespace std;

//Define global variables needed here
const int ROWS = 8;
const int COLUMNS = 8;
const int BOMB = 1; // For logic in placing bomb on array, place 1 bomb.
int guessesLeft = 5; // For logic in guessing, user gets to guess until they reach max guesses
const int MAX_GOLD = 5; // For logic in placing gold on array, place gold until MAX_GOLD = 5

int main()
{
	// Method declaration
	int initializeArray(char guessArray[ROWS][COLUMNS]);
	int displayArray(char guessArray[ROWS][COLUMNS]);
	int populateArray(char guessArray[ROWS][COLUMNS]);
	int coutGameRules();
	int gameLogic(char guessArray[ROWS][COLUMNS]);


	char guessArray[ROWS][COLUMNS];
	char answer; // Would you like to play again answer


	do

	{
		// Insert Logic Here
		// Maybe can put lopgic below main() and break elements of game into methods
		initializeArray(guessArray);
		// Display Board
		displayArray(guessArray);
		// Secretly change array , but don't show it to "hide" the bombs and gold
		populateArray(guessArray);
		// Explain Rules
		coutGameRules();
		// Ask for coordinate entry from user
		// If they find gold, give them an extra guess and add a point
		// If they find bomb, break out of loop and end game.
		// If they don't find anything, say guess again
		gameLogic(guessArray);
		
		cout << "Would you like to play Again? Enter 'Y' or 'y'" << endl;
		cin >> answer;

	} while (answer == 'Y' || answer == 'y');

	return 0;

}

// Putting ? in the array
int initializeArray(char guessArray[ROWS][COLUMNS])
{
	int row, column;
	for (row = 0; row < ROWS; row++)
	{
		for (column = 0; column < COLUMNS; column++)
		{
			guessArray[row][column] = '?';
		}
	}
	return 0;
}

// Now we display the array
int displayArray(char guessArray[ROWS][COLUMNS])

{
	int row, column;
	cout << endl;
	cout << "   "; // Adding 3 spaces to the top row ... formatting before the Column Labels, so they align with the columns in the array
	for (column = 0; column < COLUMNS; column++)
	{
		cout << setw(3) << column + 1; // Since arrays start at 0, we add 1
	}
	cout << endl;
	cout << "  " << "--------------------------" << endl;
	
	for (row = 0; row < ROWS; row++)
	{
		cout << " " << row + 1 << "|"; // Since arrays start at 0, we add 1
		for (column = 0; column < COLUMNS; column++)
		{
			cout << setw(3) << guessArray[row][column]; // put in ? marks
		}
		cout << endl;
	}

	cout << "  " << "--------------------------" << endl;

	return 0;

}

// Display Game Rules
int coutGameRules()
{
	cout << endl;
	cout << endl;
	cout << "**" << " ********************* " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << "      Find Gold!       " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << "  You have " << guessesLeft << " guesses!  " << "**" << endl;
	cout << "**" << "     There are...      " << "**" << endl;
	cout << "**" << "   5 pieces of gold,   " << "**" << endl;
	cout << "**" << "     and 1 bomb.       " << "**" << endl;
	cout << "**" << "      Good Luck!       " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << " ********************* " << "**" << endl;
	cout << endl;
	cout << endl;
	
	return 0;
}

// Hide boms and gold in the array 
int populateArray(char guessArray[ROWS][COLUMNS])

{
	srand(time(NULL)); // Seed so everything is random

	int gold = 0;
	int bomb = 0;
	int x, y;
	guessesLeft = 5;

	for (gold = 0; gold < MAX_GOLD; gold++)
	{

		x = rand() % ROWS;
		y = rand() % COLUMNS;
		guessArray[x][y] = 'G';

	}

	for (bomb = 0; bomb < BOMB; bomb++)
	{

		x = rand() % ROWS;
		y = rand() % COLUMNS;
		guessArray[x][y] = 'B';

	}

	return 0;

}

int gameLogic(char guessArray[ROWS][COLUMNS]) 
{
	int points = 0;
	int gRow, gColumn;

	do
	{
		cout << "Enter an X coordinate between 1 and 8: ";
		cin >> gRow;
		cout << endl;
		cout << "Enter a Y coordinate between 1 and 8: ";
		cin >> gColumn;
		cout << endl;

		if(guessArray[gRow][gColumn] == 'G')
		{
			cout << "You Found Gold!! You've gained an extra guess and now have " << guessesLeft << " guesses left!";
			guessArray[gRow][gColumn] = 'F';
			points += 1;
			cout << endl;
			continue;
		}
		else if (guessArray[gRow][gColumn] == 'B')
		{
			cout << endl;
			cout << "BOMB! Oh no! You have lost the game." << endl;
			break; // Lose Game
		}
		else {
			cout << "Too bad, no gold." << endl;
			guessesLeft--;
			cout << "You have " << guessesLeft << " guesses left!" << endl << endl;

		}


	} while (guessesLeft > 0);

	return 0;
}

