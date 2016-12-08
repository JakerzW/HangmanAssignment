#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void endGame();
void showInstructions();
void runGame();
void setUpWord();
void hangStatus(int state);
int menu();

char WordBank[25][20] = { "battlefield","battlefront","mass_effect","halo","skyrim","oblivion","minecraft","fifa","counter_strike","pacman","pokemon","bioshock","portal","chivalry","grand_theft_auto","fallout","dota","overwatch","hearthstone","world_of_warcraft","guild_wars","assassins_creed","call_of_duty","crash_bandicoot","rayman" };
char WordChosen[20];
char WordChosenHidden[20];
int wordLength = 0;

bool endgame = false;

int main() //sets up the game
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
}

int menu() //main menu
{
	int choice = -1;
	bool test = false;

	do {
		choice = 0;
		system("CLS");
		std::cout << " __     __   _________   ___    __   __________   __        __   _________   ___    __\n";		//outputs hangman in big letters
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
		if ((choice > 3) || (choice < 0) || (choice == 0))	//checks choice for the menu
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

void endGame() //function used to end the game
{
	bool validChoice = false;
	char sureQuit;
	while (!validChoice)
	{
		system("CLS");
		std::cout << "Are you sure you want to quit? y/n: ";
		std::cin >> sureQuit;
		if (sureQuit == 'y' || sureQuit == 'Y' || sureQuit == 'n' || sureQuit == 'N')	//checks validation of input for game exit
		{
			validChoice = true;
		}
		else	//returns if option isn't valid
		{
			std::cout << "That is not a valid option, try again.";
			Sleep(1500);
			system("CLS");
		}
		if (sureQuit == 'y' || sureQuit == 'Y')	//ends game
		{
			system("CLS");
			std::cout << "Thanks for playing!";
			Sleep(2000);
			endgame = true;
			system("CLS");
		}
		if (sureQuit == 'n' || sureQuit == 'N')	//returns to main menu
			menu();
	}
}

void showInstructions()	//shows the instructions and then returns to menu
{
	char menuReturn;
	bool returnValid = false;
	system("CLS");
	std::cout << "You will be shown a word that has been blanked out,\nleaving only the number of dashes to in place of the word or phrase.\n";
	std::cout << "Your job is to guess a letter at a time until you finally unveil the name of the game.\nIf you guess incorrectly, you will lose one of your five lives. ";
	std::cout << "\nAs soon as you have lost all of your lives, you lose the game.\nNote that you must use lower case letters.\n\nGood luck!\n\n";
	system("PAUSE");
	menu();
}

void runGame()	//the main bulk of the game
{
	char guessedArray[26];
	bool validInput = false;
	bool letterGuessed = false;
	bool spaceInGuessedArray = false;
	bool letterCorrect = false;
	bool win = false;
	int lives = 10;
	int guessCount = 0;

	setUpWord();
	system("CLS");
	//std::cout << WordChosenHidden << std::endl;
	
	while ((!win) && (lives > 0))
	{
		system("CLS");
		validInput = false;

		/*std::cout << "Hangman!\n\n";
		hangStatus(lives);
		std::cout << "Your word is: ";
		for (int i = 0; i < wordLength; i++)
		{
			std::cout << WordChosenHidden[i] << " ";
		}
		std::cout << "\n\nLives left: " << lives << "\n";
		
		if (guessCount > 0)
		{
			std::cout << "Characters guessed: ";
			for (int i = 1; i < (guessCount + 1); i++)
			{
				std::cout << guessedArray[i] << " ";
			}
		}*/

		while (!validInput)
		{
			std::cout << "Hangman!\n\n";
			hangStatus(lives);
			std::cout << "Your word is: ";
			for (int i = 0; i < wordLength; i++)
			{
				std::cout << WordChosenHidden[i] << " ";
			}
			std::cout << "\n\nLives left: " << lives << "\n";

			if (guessCount > 0)
			{
				std::cout << "Characters guessed: ";
				for (int i = 1; i < (guessCount + 1); i++)
				{
					std::cout << guessedArray[i] << " ";
				}
			}

			if (strcmp(WordChosen, WordChosenHidden) == 0)	//repeat check if missed
			{
				system("CLS");
				std::cout << "Congratulations!\n  You've WON!\n\n";
				win = true;
				system("PAUSE");
			}

			std::cout << "\n\nEnter your guess: ";
			char guess = 0;
			letterGuessed = false;
			letterCorrect = false;
			std::cin >> guess;
			char validCheck = 'a';
			while ((!validInput) && (validCheck <= 'z'))
			{
				if (guess == validCheck)
					validInput = true;	//checks the validation of the character entered
				validCheck++;
			}
			if (validInput)
			{
				for (int i = 1; i < (guessCount + 1); i++)
				{
					if (guess == guessedArray[i])
						letterGuessed = true; 
				}
				if (!letterGuessed)
				{
					for (int i = 0; i < wordLength; i++)	//for every char in the word array, the guessed letter that matches the letter in the word is 
					{										//replaced in the display word and the guess is added to guessed array
						if (guess == WordChosen[i])
						{
							WordChosenHidden[i] = guess;
							letterCorrect = true;
							if (strcmp(WordChosen, WordChosenHidden) == 0)
							{
								system("CLS");
								std::cout << "Congratulations!\n  You've WON!\n\n";
								win = true;
								system("PAUSE");
							}
						}
					}
					guessCount++;
					guessedArray[guessCount] = guess;
				}
				if (letterGuessed)
				{
					std::cout << "That input is not valid, please try again.";
					Sleep(1200);
					system("CLS");
				}
				else if (!letterCorrect)
					lives--;
			}
			if (!validInput)
			{
				std::cout << "That input is not valid, please try again.";
				Sleep(1200);
				system("CLS");
			}
		}			
	}
	if (lives == 0)
	{
		system("CLS");
		std::cout << " I'm sorry!\nYou've LOST!\n\n";
		system("PAUSE");
	}
	
}

void setUpWord()
{
	int randWord;
	srand(time(NULL));
	randWord = rand() % 25 + 1;
	strcpy(WordChosen, WordBank[randWord]);
	wordLength = strlen(WordChosen);
	for (int i = 0; i < wordLength; i++)
	{
		WordChosenHidden[i] = '_';
	}
}	

void hangStatus(int state)
{
	switch (state)
	{
	case 10:
	{
		//no lives lost
	}
	break;
	case 9:
	{
		std::cout << "                    " << std::endl;
		std::cout << "                    " << std::endl;
		std::cout << "                    " << std::endl;
		std::cout << "                    " << std::endl;
		std::cout << "                    " << std::endl;
		std::cout << "                    " << std::endl;
		std::cout << "                    " << std::endl;
		std::cout << "                    " << std::endl;
		std::cout << "                    " << std::endl;
		std::cout << "____________________" << std::endl;

	}
	break;
	case 8:
	{
		std::cout << "                    " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;

	}
	break;
	case 7:
	{
		std::cout << "____________________" << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;

	}
	break;
	case 6:
	{
		std::cout << "____________________" << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;

	}
	break;
	case 5:
	{
		std::cout << "____________________" << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           O    " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;

	}
	break;
	case 4:
	{

		std::cout << "____________________" << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           O    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;
	}
	break;
	case 3:
	{
		std::cout << "____________________" << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           O    " << std::endl;
		std::cout << "  ||           |\\  " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;

	}
	break;
	case 2:
	{
		std::cout << "____________________" << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           O    " << std::endl;
		std::cout << "  ||          /|\\  " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;

	}
	break;
	case 1:
	{
		std::cout << "____________________" << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           O    " << std::endl;
		std::cout << "  ||          /|\\  " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||            \\  " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;

	}
	break;
	case 0:
	{
		std::cout << "____________________" << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||           O    " << std::endl;
		std::cout << "  ||          /|\\  " << std::endl;
		std::cout << "  ||           |    " << std::endl;
		std::cout << "  ||          / \\  " << std::endl;
		std::cout << "  ||                " << std::endl;
		std::cout << "__||________________" << std::endl;

	}
	break;

	default:

		break;
	}

}
