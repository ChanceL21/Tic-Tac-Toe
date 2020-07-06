#include "extra_credit.h"

int main(void)
{
	int option = 0, program_running = 1;

	while (program_running)
	{
		option = menu_select(); // displaying menu and returning satisfactory option

		switch (option)
		{
		case 1: display_rules(); // display game rules
			break;
		case 2: play_game(); // activate main gameplay function
			break;
		case 3: program_running = 0; // discontinuing while loop and therefore ending the program
			cout << "Thanks for playing!\n";
			break;
		}
	}

	return 0;
}