#include <iostream>
using namespace std;


// prints the main menu to user
void display_menu(void);

//prompts the user for option once
int get_option(void);

// makes sure option is between 1 and 3, inclusively. For main menu function only
int evaluate_option(int option);

// continues to display menu until optino requirements are satisfied
int menu_select(void);

// display tic tac toe rules to user
void display_rules(void);

// main game play function. activated when option 2, play game, is chosen in main menu
void play_game(void);

// prints the current tic tac toe board to the screen, stylized with lines to divide the squares
void display_board(char board[3][3]);

// lets one player take their turn
void take_turn(char board[3][3], int player);

// checks to see if a player won, and displays the winner if so. Declares the game as a Cat's game if all the spaces are filled and no one has 3 in a row. Returns 1 if the game should continue, 0 if it should end.
int check_winner(char board[3][3], int player);

// checks to see if the selected square is out of bounds or already selected, in which case it returns 0 and prints out relevant statement to user. returns 1 if chosen square is satisfactory, and adds the player's mark to the board
int check_square(char board[3][3], int square, int player);