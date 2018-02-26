# INFO450GUESS

# Topics Covered: 2-D Arrays, Functions, Function Parmeters/Arguments, Conditional Statements

## Functional Requirements:
- Write a Program that builds an 8x8 board game with 5 pieces of hidden gold and 1 hidden BOMB.
- The user gets 5 chances (guesses) to find the gold, earning a point for each found Gold.
- After each guess, the user is informed if they found Gold or not and how many guesses they have left.
- If the user finds the BOMB before finding all the gold, the game is over. LOSER! No more guesses.
- The game starts with presenting a game board with the contents hidden.
- The game allows the user to guess 5 times, by entering an x-coordinate and an y-coordinate for each guess.
- At the end of the game,
	- The player is presented with the number of Points earned. (gold that was found)
	- The player is presented with the game board with the Contents showing “G” = Gold, “F” = found Gold “B” = bomb
	- The player is asked if they want to play again.
- If the player selects to play again, games starts over by presenting the hidden board.
- The game will repeat for as long as the player wants to play.

## Extra credit (10pts)
- Each piece of gold found rewards a user with an extra guess

## Non-Functional Requirements
- The game must use a 2-D array as the Game Board
- The program must use at least 2 functions for the game (can be more!)
	- To initialize the game board with Gold and Bomb
	- To present the game board to the user
- The board 2-D array should be declared in the main() function and passed to the initialize and show functions
- The program should use const variables for the game board size
- The game should use the rand() function to randomly set the gold and bomb at different x,y positions in the array for each game played
	- (Note: srand( time(NULL)); can be used to seed the rand function);
- The user should be allowed to continue to play games until they decide to quit.

## Submission Requirements
- You should upload your program to your github account in a repository called: INFO450GUESS
- Turn in your project on blackboard by uploading the URL to your github repository
- Note: coding standards adherence will now be part of the overall grade for the project

## Coding Standards:

### Naming:
- Variable names should be short, yet meaningful. e.g. int width; (instead of int w;)
- All variable, function and method names should be as descriptive as possible and follow lower camelCase. e.g. calculateArea
- All classes should start with a capital letter, then follow camelCase for the remaining. e.g. class BankAccount
- Constant variables and enumerated types should be in all Caps. (e.g. const float MINWAGE=11.50;
- Global variables are discouraged (but may be used for declaring const variables if needed)

### Formatting:
- Lines should not exceed 78 characters
- One statement per line
- Curly braces for code blocks should align on the left with the body of block indented

### Comments:
- Consider your comments a story describing the system.
- Each function definition should be preceded with a description of what the function does
- Comments should describe sections of code – NOT each line of code
- Comments should weave together and inform someone else at another point of time just exactly what you did and why.
