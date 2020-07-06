#include "extra_credit.h"

void display_menu(void) // printing menu
{
	cout << "Welcome to Tic Tac Toe!\n";
	cout << "1. Print Game Rules\n";
	cout << "2. Start a Game of Tic Tac Toe\n";
	cout << "3. Exit\n";
}

int get_option(void) // prompts for option once
{
	int option = 0;
	cout << "Please enter the number corresponding with the desired action: ";
	cin >> option;
	return option;
}

int evaluate_option(int option) // makes sure option is between 1 and 3, inclusively
{
	if (option < 1 || option > 3)
	{
		cout << "That's not a valid option!\n";
		return 0; // not satisfied
	}
	else
	{
		return 1; // satisfied
	}
}

int menu_select(void) // continues to display menu until option requirements are satisfied
{
	int option = 0;
	do {
		display_menu();
		option = get_option();
		system("cls");
	} while (!evaluate_option(option));
	return option;
}

void display_rules(void) // displaying rules to user
{
	cout << "Tic Tac Toe is a paper-and-pencil game for two players, 1 (X) and 2 (O), who take turns marking the\n"
		"spaces in a 3x3 grid with their mark. Player 1 (X) is the first to make a mark. Once a space has been\n"
		"marked, it cannot be marked again. The player who succeeds in placing three of their marks in a\n"
		"horizontal, vertical, or diagonal row wins the game, and the game is over(i.e., no further actions occur).\n"
		"If the board is filled and neither player has won, then it is a Cat's Game, or a draw.\n";
}

void play_game(void) // main gameplay function
{
	char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; // initializing empty board
	int playing = 1; // 1 means game is being played, 0 means it is finished.
	int player = 1; // player 1 goes first

	while (playing) // game being played
	{
		system("cls"); // clear screen
		display_board(board); // print board to user
		take_turn(board, player); // a single player takes a turn
		playing = check_winner(board, player);
		if (player == 1) // if player 1's turn
			player = 2; // player 2 goes next
		else            // if player 2's turn
			player = 1; // player 1 goes next
	}
}

void display_board(char board[3][3]) // print board to user
{
	cout << "Player 1 (X) - Player 2 (O)\n";
	cout << "-------------\n"; // upper line
	for (int i = 0; i < 3; i++)
	{
		cout << "| "; // print leftmost line
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j]; // print actual item in board
			cout << " | "; // print line to the right
		}
		cout << endl;
		if (i < 2) // not the last i loop
		{
			cout << "----+---+----\n"; // print inner line
		}
	}
	cout << "-------------\n"; // print lower line

}

void take_turn(char board[3][3], int player)
{
	int square = 0;
	cout << "It's your turn, player " << player << "!\n";

	do {  // continuously prompt user for the square to mark until it is satisfactory
		cout << "Please enter the number of the square you would like to mark: ";
		cin >> square;
		system("cls");
		display_board(board);
	} while (!check_square(board, square, player));
	system("cls");
	display_board(board); // show change made once square is chosen
}

int check_winner(char board[3][3], int player) // checks if a player has one. It is only necessary to check if a player has won right after they make a mark, rather than checking both players.
{
	int squares_used = 0;

	char mark = 'X'; // mark is 'X'
	if (player == 2) // if player 2
		mark = 'O'; // change mark to 'O'
	// single nested loop that counts the marks in rows and columns. this is possible because a tic tac toe board is a square. Also determines if any spaces are available
	for (int i = 0; i < 3; i++)
	{
		int row_marks = 0;
		int col_marks = 0;
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == mark) // typical i and j loop to count marks in a row
			{
				row_marks++; // add one to num marks
			}
			if (board[j][i] == mark) // i and j are reversed to count marks in a column
			{
				col_marks++; // ad one to num marks
			}
			if (board[i][j] == 'X' || board[i][j] == 'O') // if either player has marked a square
			{
				squares_used++; // add one to squares used
			}
		}
		if (row_marks == 3 || col_marks == 3) // either 3 in a row or 3 in a column for given i loop
		{
			cout << "Player " << player << " wins!\n\n"; // then player who just went has won
			return 0; // end game
		}
	}

	if (board[1][1] == mark) // if player has a mark in the center
	{
		if (board[0][0] == mark && board[2][2] == mark) // check upper left and lower right
		{
			cout << "Player " << player << " wins!\n\n";
			return 0; // end game. diagonal 3 in a row
		}
		if (board[0][2] == mark && board[2][0] == mark) // check lower left and upper right
		{
			cout << "Player " << player << " wins!\n\n";
			return 0; // end game. diagonal 3 in a row
		}
	}

	if (squares_used == 9) // all squares are used and no winner was determined above
	{
		cout << "Cat's Game!\n\n";
		return 0; // game end. draw.
	}
	

	return 1; // if none of the above return statements execute, then the game should continue
}

int check_square(char board[3][3], int square, int player)
{
	if (square < 1 || square > 9) // number out of range
	{
		cout << "That number is not on the board!\n";
		return 0; // request another number
	}

	// navigate through board until at square chosen by user
	int position = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (square == position) // if current position is the square the user wanted to mark
			{
				if (board[i][j] == 'X' || board[i][j] == 'O') // chosen number has already been marked
				{
					cout << "That square is already taken!\n";
					return 0; // request another number
				}
				else
				{
					if (player == 1)
					{
						board[i][j] = 'X'; // player 1 marks an 'X'
					}
					else
					{
						board[i][j] = 'O'; // player 2 marks an 'O'
					}
					return 1; // don't request another number
				}
			}
			position++; // add one to current position every time an item is iterated through in the nested list
		}
	}
}