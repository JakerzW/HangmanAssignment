#include <iostream>

void RunIntro();
void RunGame();
void WordArrays();

bool endgame = false;

int main() 
{
	std::cout << "Welcome to Hangman!";

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
	char WordBank[20][12];
}