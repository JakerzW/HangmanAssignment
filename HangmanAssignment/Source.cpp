#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void endGame();
void showInstructions();
void runGame();
void setUpWord();
int menu();

char WordBank[25][20] = { "battlefield","battlefront","mass effect","halo","skyrim","oblivion","minecraft","fifa","counter strike","pacman","pokemon","bioshock","portal","chivalry","grand theft auto","fallout","dota","overwatch","hearthstone","world of warcraft","guild wars","assassins creed","call of duty","crash bandicoot","rayman" };
char WordChosen[20];
char WordChosenHidden[20];

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

int menu()
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
			system("CLS");
			std::cout << "Thanks for playing!";
			Sleep(2000);
			endgame = true;
			system("CLS");
		}
		if (sureQuit == 'n' || sureQuit == 'N')
			menu();
	}
}

void showInstructions()
{
	char menuReturn;
	bool returnValid = false;
	system("CLS");
	std::cout << "You will be shown a word that has been blanked out,\nleaving only the number of dashes to in place of the word or phrase.\nYour job is to guess a letter at a time until you finally unveil the name of the game.\nIf you guess incorrectly, you will lose one of your five lives. \nAs soon as you have lost all of your lives, you lose the game.\nGood luck!\n\n";
	system("PAUSE");
	menu();
}

void runGame()
{
	char LettersGuessed[26];
	bool validInput = false;
	bool letterGuessed = false;
	bool winLoss = false;

	setUpWord();
	system("CLS");
	std::cout << WordChosenHidden << std::endl;
	
	while (!winLoss)
	{
		char guess, validCheck;
		int guessArrayPos = 1;

		std::cout << "Enter your guess: ";
		std::cin >> guess;
		while (!validInput || validCheck <= 'z')
		{
			validCheck = 'a';
			if (guess == validCheck)
				validInput = true;
			validCheck++;
		}
		while (!letterGuessed)
		{
			for (int i = 0; i < guessArrayPos; i++)
			{
				if (guess == LettersGuessed[i])
					letterGuessed = true;
			}
			guessArrayPos++;
		}
	}
}

void checkLetter(char x)
{

}

void setUpWord()
{
	int randWord;
	randWord = std::rand() % 25 + 1;
	//WordChosen = WordBank[randWord];
	for (int i = 0; i < 20; i++)	//copies random word into array
	{
		WordChosen[i] = WordBank[randWord][i];
	}
	for (int i = 0; i < 20; i++)
	{
		if (WordChosen[i] != ' ')
			WordChosenHidden[i] = '_';
	}

	//randomise word chosen
	//insert word into word chosen array and word chosen hidden should be filled with the same number of asterisks as the word chosen
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
