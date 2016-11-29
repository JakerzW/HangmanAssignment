#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void endGame();
void showInstructions();
void runGame();
void wordArrays();
int menu(void);
void exit();

bool endgame = false;

int main() 
{
	int menuOption = 0;
	while (!endgame)
	{
		menuOption = menu();
		switch (menuOption)
		{
			case 1:	runGame();
				break;
			case 2: showInstructions();
				break;
			case 3: endGame();
				break;
		}
	}
	return 0;
	//system("PAUSE");
}

int menu(void)
{
	int choice = -1;
	bool test = false;

	do {
		choice = 0;
		system("CLS");
		std::cout << " __     __   _________   ___    __   __________   __        __   _________   ___    __\n";
		std::cout << "|  |   |  | |   ___   | |   \\  |  | |   _______| |  \\      /  | |   ___   | |   \\  |  |\n";
		std::cout << "|  |   |  | |  |___|  | |    \\ |  | |  |         |   \\    /   | |  |___|  | |    \\ |  |\n";
		std::cout << "|  |___|  | |   ___   | |     \\|  | |  |   ____  |    \\__/    | |   ___   | |     \\|  |\n";
		std::cout << "|   ___   | |  |   |  | |  |\\     | |  |  |_   | |   _    _   | |  |   |  | |  |\\     | \n";
		std::cout << "|  |   |  | |  |   |  | |  | \\    | |  |____|  | |  | \\__/ |  | |  |   |  | |  | \\    |\n";
		std::cout << "|__|   |__| |__|   |__| |__|  \\___| |__________| |__|      |__| |__|   |__| |__|  \\___| \n";
		std::cout << "---------------------------------------------------------------------------------------\n";
		std::cout << std::setw(36) << "Play Hangman" << std::setw(26) << "Press  1  \n";
		std::cout << std::setw(36) << "Instructions" << std::setw(26) << "Press  2  \n";
		std::cout << std::setw(28) << "Exit" << std::setw(34) << "Press  3  \n";
		std::cout << std::endl << std::setw(45) << "Choice: ";
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
	} 
	while (test == false);
	return (choice);
}

void endGame()
{
	endGame();
	bool validChoice = false;
	char sureQuit;
	while (!validChoice)
	{
		system("CLS");
		std::cout << "Are you sure you want to quit? y/n: ";
		std::cin >> sureQuit;
		if (sureQuit == 'y' || sureQuit == 'Y' || sureQuit == 'n' || sureQuit == 'N')
		{
			validChoice = true;
		}
		else
		{
			std::cout << "That is not a valid option, try again.";
			Sleep(1500);
			system("CLS");
		}
		if (sureQuit == 'y' || sureQuit == 'Y')
		{
			exit();
			endgame = true;
			system("CLS");
		}
		if (sureQuit == 'n' || sureQuit == 'N')
			menu();
	}
}

void showInstructions()
{

}

void runGame()
{

}

void wordArrays()
{
	//char WordBank[25][25] = ("battlefield","battlefront","halo","skyrim","oblivion","minecraft","fifa","csgo","pacman","pokemon","bioshock","portal","chivalry","gta","fallout","dota","overwatch","hearthstone");
}

void exit()
{
	system("CLS");
	std::cout << "Thanks for playing!";
	Sleep(2000);
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
}*/
