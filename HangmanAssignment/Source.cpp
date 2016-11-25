#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

void RunIntro();
void RunGame();
void WordArrays();

bool endgame = false;

int main() 
{
	std::cout << "";
	std::cout << " __     __   _________   ___    __   __________   __        __   _________   ___    __    ";
	std::cout << "|  |   |  | |   ___   | |   \  |  | |   _______| |  \      /  | |   ___   | |   \  |  |   ";
	std::cout << "|  |   |  | |  |___|  | |    \ |  | |  |         |   \    /   | |  |___|  | |    \ |  |   ";
	std::cout << "|  |___|  | |   ___   | |     \|  | |  |   ____  |    \__/    | |   ___   | |     \|  |   ";
	std::cout << "|   ___   | |  |   |  | |  |\     | |  |  |_   | |   _    _   | |  |   |  | |  |\     |   ";
	std::cout << "|  |   |  | |  |   |  | |  | \    | |  |____|  | |  | \__/ |  | |  |   |  | |  | \    |   ";
	std::cout << "|__|	 |__| |__|   |__| |__|  \___| |__________| |__|      |__| |__|   |__| |__|  \___|   ";

	while (!endgame) 
	{
		RunIntro();
	}

	return 0;
	system("PAUSE");

}

void RunIntro() 
{
	char endgamechar;
	bool valid = false;
	std::cout << "You are about to get your word to guess. If you guess incorrectly too many times, \nthe man will be hanged! Good luck.";
	
	while (!valid)
	{
		std::cout << "\nAre you ready to play? y/n: ";
		std::cin >> endgamechar;
		if (endgamechar != ('n', 'N', 'y', 'Y'))
			valid = true;
		else	std::cout << "That is not a valid input, try again.";
	}

	if (endgamechar == ('n' || 'N'))
	{
		char sureQuit;
		std::cout << "\nAre you sure you want to quit? y/n: ";
		std::cin >> sureQuit;
		if (sureQuit == ('y'||'Y'))
			endgame = true;
	}

	if (endgamechar == 'y')
		RunGame();
}

void RunGame()
{

}

void WordArrays()
{
	char WordBank[20][12] = { "",	}

}

/*int menu(void);
bool play_game(void);
void instructions(void);
void exit_game(void);

int main(void)
{
	bool exit_flag = false;
	int option = 0;

	while (exit_flag == false)
	{
		option = menu();
		std::cout << "\n Choice " << option << " Selected\n";
		switch (option)
		{
		case  1:
		{
			system("CLS");
			std::cout << "Guessing Game Selected Enjoy!!\n";
			bool result = play_game();
			if (result == true)
			{
				std::cout << "Congrats you won !! \n";
			}
			else
			{
				std::cout << "Hard Luck you lost !!\n";
			}
			exit_flag = false;
			break;
		}
		case  2:
		{		instructions();
		exit_flag = false;
		break;
		}
		case  3:
		{		exit_game();
		exit_flag = true;
		break;
		}

		default:
		{
			std::cout << "Error Condition.. Exit program\n";
			exit_flag = true;
			break;
		}
		} //end switch                                  
	} //end while               
	std::cin.get();
	return 0;
}


/*int menu(void)
{
	int choice = -1;
	bool test = false;

	do {
		choice = 0;
		system("CLS");
		std::cout << "Please Select Your Option from the Menu\n";
		std::cout << "---------------------------------------\n";
		std::cout << "Play Guessing Game" << std::setw(20) << "Press  1  \n";
		std::cout << "Instructions" << std::setw(26) << "Press  2  \n";
		std::cout << "Exit" << std::setw(34) << "Press  3  \n";
		std::cout << "Choice -> ";
		std::cin >> choice;

		if ((choice > 3) || (choice < 0) || (choice == 0))
		{
			system("CLS");
			test = false;
			std::cout << "Invalid Selection\n";
			Sleep(2000);
		}
		else
		{
			test = true;
		}

	} while (test == false);
	return (choice);
}

bool play_game(void)
{
	system("CLS");
	std::cout << "Play game code\n";
	Sleep(2000);
	return true;
}

void instructions(void)
{
	system("CLS");
	std::cout << "Instructions would be here\n";
	Sleep(2000);
}

void exit_game(void)
{
	system("CLS");
	std::cout << "Exit Selected Thankyou , and Goodbye!\n";
	Sleep(2000);
}*/
