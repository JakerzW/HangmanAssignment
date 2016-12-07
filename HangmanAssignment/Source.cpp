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
char GuessedChars[26];

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
	std::cout << "You will be shown a word that has been blanked out,\nleaving only the number of dashes to in place of the word or phrase.\nYour job is to guess a letter at a time until you finally unveil the name of the game.\nIf you guess incorrectly, you will lose one of your five lives. \nAs soon as you have lost all of your lives, you lose the game.\nGood luck!\n\n";
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
	bool winLoss = false;
	int lives = 10;

	setUpWord();
	system("CLS");
	//std::cout << WordChosenHidden << std::endl;
	
	while (!winLoss)
	{
		char guess, validCheck = 'a';
		int correctArrayPos = 1;
		int guessedArrayPos = 1;

		std::cout << "Your word is: " << WordChosenHidden << "\n\n";
		std::cout << "Lives left: " << lives << std::endl;
		/*for (size_t i = 0; i < 27; i++)
		{

		}*/
		std::cout << "Characters guessed: " << GuessedChars << "\n\n";

		while (!validInput)
		{
			std::cout << "Enter your guess: ";
			std::cin >> guess;
			while ((!validInput) && (validCheck <= 'z'))
			{
				validCheck = 'a';
				if (guess == validCheck)
					validInput = true;
				validCheck++;
			}
			if (validInput)
			{
				while ((!letterGuessed) && (!spaceInGuessedArray))
				{
					int i = 0;

					if (guessedArray[i] == ' ')
						spaceInGuessedArray = true;
					if (guess == guessedArray[i])
						letterGuessed = true;

					guessedArrayPos++;
					i++;
				}
				while (!letterCorrect)
				{
					for (int i = 0; i < correctArrayPos; i++)
					{
						if (guess == WordChosen[i])
							letterCorrect = true;
					}
					correctArrayPos++;
				}
			}
			else
			{
				std::cout << "That input is not valid, please try again.";
			}
		}			
	}
}

void setUpWord()
{
	int randWord;
	randWord = std::rand() % 25 + 1;
	strcpy(WordChosen, WordBank[randWord]);
	int wordLength = strlen(WordChosen);
	for (int i = 0; i < wordLength; i++)
	{
		WordChosenHidden[i] = '_';
	}
}	
