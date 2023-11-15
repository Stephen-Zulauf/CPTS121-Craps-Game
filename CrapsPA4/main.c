
#include "craps.h"
#include "animation.h"

int main() {

	//seed random
	srand(time(NULL));

	//load game data from .dat
	struct gameState state;
	state = loadGameData();

	//print the intro animation;
	returnAnimation();

	//print the main menu
	printMainMenu();

	int choice = 0;

	while (choice != 4) {

		//check if choice is entered
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			//go to game screen
			state = gameLoop(state);

			//reprint menu on exit
			system("cls");
			returnAnimation();
			printMainMenu();
			break;
			
		case 2:
			//go to bank screen
			state = bankLoop(state);

			//reprint menu on exit
			system("cls");
			returnAnimation();
			printMainMenu();
			break;

		case 3:
			//reprint menu
			system("cls");
			returnAnimation();
			printMainMenu();
			break;

		case 4:
			//print and exit program
			if (state.wins >= state.losses) {
				system("cls");
				printf("See you around.....");
			}
			else {
				system("cls");
				printf("Later Looser!");
			}
			//save the game data to .dat
			saveGameData(state);
			break;

		}
		

	}

	return 0;
}