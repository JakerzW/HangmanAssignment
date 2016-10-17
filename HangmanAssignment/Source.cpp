#include <iostream>

void RunGame();

bool endgame = false;

int main() {
	std::cout << "Welcome to Hangman!";

	while (!endgame) {
		RunGame();
	}

	return 0;
	system("PAUSE");

}

void RunGame() {
	char endgamechar;

	std::cout << "Here is your word to guess. If you guess incorrectly, the man will be hanged! Good luck.";
	std::cout << "\nAre you ready to play? y/n: ";
	std::cin >> endgamechar;

	if (endgamechar == 'n')
		endgame = true;
	//if (endgamechar =='y')



}