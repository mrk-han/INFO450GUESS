// INFO450GUESS.cpp : Find the gold, dodge the bomb, win big!  If the user finds a piece of gold, they get an extra guess!
//

#include "stdafx.h"
#include <iostream>
#include <time.h> // Used for seeding
#include <iomanip>  

using namespace std;

//TODO: Still need to fix bug where if we input iuashdfuiahsdfuoasdf as gRow or gColumn the console outputs "please enter integer between 1 and 8" as many times as there were characters inputted

//Define global variables needed here
const int ROWS = 8;
const int COLUMNS = 8;
int guessesLeft = 5; // For logic in guessing, user gets to guess until they reach max guesses

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


	do // do/while loop
	{
		initializeArray(guessArray);
		displayArray(guessArray);
		populateArray(guessArray);
		coutGameRules();
		gameLogic(guessArray);

		cout << "Would you like to play Again? Enter 'Y' or 'y'" << endl;
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			guessesLeft = 5; // Reset guesses if user plays again
		}

	} while (answer == 'Y' || answer == 'y'); // Execute code above if user enter Y or y

	return 0;

}

// Start off by iterating through array and placing question marks in every position .. this will not print the array to the console yet!
int initializeArray(char guessArray[ROWS][COLUMNS])
{
	int row, column;

	guessesLeft = 5; // Need to make sure guesses reset to 5 when array is initialized.  If they aren't set to 5 here, user can close out of game and upon starting again will have less than 5 lives.

	// Iterate through array and put a ? in every position
	for (row = 0; row < ROWS; row++)
	{
		for (column = 0; column < COLUMNS; column++)
		{
			guessArray[row][column] = '?';
		}
	}
	return 0;
}

// Print the array to the console
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
			cout << setw(3) << guessArray[row][column]; // Helps display the array with spacing to be more readable
		}
		cout << endl;
	}

	cout << "  " << "--------------------------" << endl;

	return 0;

}

// Explain Rules, simple cout to display rules to user
int coutGameRules()
{
	cout << "**" << " ********************* " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << "      Find Gold!       " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << "  You have 5 guesses!  " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << "  Earn an extra guess  " << "**" << endl;
	cout << "**" << "  when you find gold!  " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
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

// Secretly place gold and bombs in array , but don't show it to "hide" the bombs and gold.
int populateArray(char guessArray[ROWS][COLUMNS])

{

	int bombInputCounter = 0;
	int x, y;
	int goldInputCounter = 0;
	srand(time(NULL)); // Seed so everything is random

	// Adds a piece of gold at a random (X,Y) coordinate until 5 pieces are placed
	do {
		x = rand() % ROWS; // Get a random Row #
		y = rand() % COLUMNS; // Get a random Column #

		if (guessArray[x][y] != 'G')
		{
			guessArray[x][y] = 'G'; // Put 'G' for Gold at the random (X,Y) Coordinate
			goldInputCounter++; // Hacky way of making sure 5 pieces of gold are input ... see the Update
		}
		// Probably need a do this for loop while guessArrayXY 'G' are <= 5 to make sure there are always 5 on the array

	} while (goldInputCounter < 5);// guessArray contains <= 5 'G' characters

   // Adds a bomb at a random (X,Y) coordinate
	do
	{
		x = rand() % ROWS; // Get a random Row #
		y = rand() % COLUMNS; // Get a random Column #

		if (guessArray[x][y] != 'G') 		// If random row and column are equal to 'G', go back to beginning of loop and get another random row and column.  This prevents a bomb covering up a piece of gold!!!! FINALLY FOUND THE FREAKING BUG OMG SO HAPPY
											// Update: Found out that I should be doing this, but ALSO needed to switch to do/while loop and implement the bombInputCounter to make sure there were correct amount of bombs being put in.
		{
			guessArray[x][y] = 'B'; // Put 'B' for Bomb at the random (X,Y) coordinate
			bombInputCounter++;
		}


	} while (bombInputCounter < 1);



	return 0;

}






// This is where the magic happens
int gameLogic(char guessArray[ROWS][COLUMNS])
{
	int points = 0;
	int gRow, gColumn; // gRow = guessRow; gColumn = guessColumn

	do
	{
		// Ask for coordinate entry from user
		cout << "Enter an X coordinate between 1 and 8: ";
		cin >> gRow;

		//While the input entered is not an integer, prompt the user to enter an integer.
		while (!cin || gRow > 8 || gRow < 1)
		{
			cout << "Please enter an integer that is between 1 and 8: ";
			cin.clear();
			cin.ignore();
			cin >> gRow;
		}

		gRow--; // Subtract 1 so it matches array display... since arrays start at 0, user would have had to guess coordinate (0,0) when they were trying to find gold at (1,1) so we fix this here.
		cout << endl;
		cout << "Enter a Y coordinate between 1 and 8: ";
		cin >> gColumn;

		//While the input entered is not an integer, prompt the user to enter an integer.
		while (!cin || gColumn > 8 || gColumn < 1)
		{
			cout << "Please enter an integer that is between 1 and 8: ";
			cin.clear();
			cin.ignore();
			cin >> gColumn;
		}

		gColumn--; // Subtract 1 so it matches array display ... since arrays start at 0, user would have had to guess coordinate (0,0) when they were trying to find gold at (1,1) so we fix this here.
		cout << endl;

		// If they find gold, give them an extra guess (or just don't take a guess away) and add a point ***THIS IS EXTRA CREDIT***
		if (guessArray[gRow][gColumn] == 'G')
		{
			cout << "You Found Gold!! You've gained an extra guess and now have " << guessesLeft << " guesses left!";
			guessArray[gRow][gColumn] = 'F'; // This makes it so user knows where they found gold at the end of the game 
											// AND also prevents user from guessing the same coordinate over and over to get as many points as they want.
			points += 1; // Give user a point if they find gold!
			cout << endl;
			cout << endl;
			continue; // Go back to beginning of loop
		}
		// If they find bomb, break out of loop and end game.
		else if (guessArray[gRow][gColumn] == 'B')
		{
			cout << endl;
			cout << "BOMB! Oh no! You have lost the game." << endl << endl; // User is going to be S A D when they get this message.
			break; // Lose Game
		}
		// If they don't find anything, say TOO BAD and subtract a guess
		else 
		{
			cout << "Too bad, no gold." << endl;
			guessesLeft--; // Decrement guessesLeft by 1
			cout << "You have " << guessesLeft << " guesses left!" << endl << endl;

		}


	} while (guessesLeft > 0); // Do this loop until user has 0 guessesLeft

	cout << "You've earned " << points << " points!" << endl;
	cout << "Better luck next time!" << endl;
	// Display array at the end where all of the gold and bombs were placed at the end
	cout << "Here's your board:" << endl << endl;

	// Take out question marks from array
	for (gColumn = 0; gColumn < COLUMNS; gColumn++)
	{
		for (gRow = 0; gRow < ROWS; gRow++) 
		{
			if (guessArray[gRow][gColumn] == '?') 
			{
				guessArray[gRow][gColumn] = ' ';
			}
		}
	}

	// The logic below displays the guessArray to the user but adds the hidden bombs and hidden gold.  Also shows where the user found gold!
	cout << "   "; // Adding 3 spaces to the top row ... formatting before the Column Labels, so they align with the columns in the array
	for (gColumn = 0; gColumn < COLUMNS; gColumn++)
	{
		cout << setw(3) << gColumn + 1; // Since arrays start at 0, we add 1.  Setw helps formatting --- spaces columns out
	}
	cout << endl;
	cout << "  " << "--------------------------" << endl;

	for (gRow = 0; gRow < ROWS; gRow++)
	{
		cout << " " << gRow + 1 << "|"; // Since arrays start at 0, we add 1
		for (gColumn = 0; gColumn < COLUMNS; gColumn++)
		{
			cout << setw(3) << guessArray[gRow][gColumn]; // Helps display the array with spacing to be more readable
		}
		cout << endl;
	}

	cout << "  " << "--------------------------" << endl;


	return 0;
}



