
#include "gameloop.h"


//roll dice
struct gameState diceRoll(struct gameState currentState) {

	struct gameState newState = currentState;

	//push current roll to last roll
	newState.lastRoll[0] = newState.currentRoll[0];
	newState.lastRoll[1] = newState.currentRoll[1];

	//get random values for current roll
	newState.currentRoll[0] = getRandomNumber(6);
	newState.currentRoll[1] = getRandomNumber(6);

	return newState;

}

//get roll value; "l"- last roll "c"-current roll
int rollValue(struct gameState currentState, char lastOrCurrent) {
	int value;
	
	switch (lastOrCurrent) {
	case 'l':
		value = currentState.lastRoll[0] + currentState.lastRoll[1];
		break;
	case 'c':
		value = currentState.currentRoll[0] + currentState.currentRoll[1];
		break;
	default:
		value = currentState.currentRoll[0] + currentState.currentRoll[1];
		break;
	}

	return value;

}

//Decide who goes first
struct gameState rollForShooter(struct gameState currentState) {

	struct gameState newState = currentState;

	int choice = 0;
	int subChoice = 0;

	printEd();
	printDialog("Whos up first?");
	printMenuOption('1', "Roll for Shooter");
	printMenuOption('2', "Exit");

	while (choice != 2) {

		//check if choice entered
		scanf("%d", &choice);

		switch (choice) {
		case 1:

			//player throw
			newState = diceRoll(newState);

			//display roll
			printKid();
			printDialog("here I go....");
			delayTime(2);
			printDiceAnimation(newState.currentRoll[0]);
			delayTime(1);
			printDiceAnimation(newState.currentRoll[1]);
			printf("The kid rolled: %d", rollValue(newState, 'c'));
			delayTime(3);

			//computer throw
			newState = diceRoll(newState);

			//display roll
			printEd();
			printDialog("watch out kid...");
			delayTime(2);
			printDiceAnimation(newState.currentRoll[0]);
			delayTime(1);
			printDiceAnimation(newState.currentRoll[1]);
			printf("Crazy Ed rolled: %d", rollValue(newState, 'c'));
			delayTime(3);

			//check whos roll is greater
			if (rollValue(newState, 'l') >= rollValue(newState, 'c')) {

				//player shoots first
				newState.shooter = 1;
				printKid();
				printDialog("I'm up first");
				printMenuOption('1', "roll");

				while (subChoice != 1) {
					scanf("%d", &subChoice);
				}
				choice = 2;


			}
			else {
				//computer shoots first
				newState.shooter = 2;
				printEd();
				printDialog("old Eds up first.");
				printMenuOption('1', "continue");

				while (subChoice != 1) {
					scanf("%d", &subChoice);
				}
				choice = 2;
			}
			break;
		case 2:

			//exit
			break;

		}
	}

	return newState;

}

//Betting menu
struct gameState fadeMenu(struct gameState currentState) {

	int choice = 0;
	int computerBet = 0;
	struct gameState newState = currentState;

	if (newState.shooter == 1) {
		
		//subtract 20 from player balance and put in pot
		newState.playerBalance -= 20;
		newState.pot = 20;

		printKid();
		printDialog("My turn to bet");
		printMenuOption('1', "Increase Pot");
		printMenuOption('2', "Decrease Pot");
		printMenuOption('3', "Place Bet");
		printBetBalance(newState.playerBalance, newState.bankBalance, newState.pot);

		while (choice != 3) {
			//check if choice entered
			scanf("%d", &choice);
			switch (choice) {
			case 1:
				//increase pot by 20 and remove from player-can go into debt
					newState.pot += 20;
					newState.playerBalance -= 20;

					printKid();
					printDialog("My turn to bet");
					printMenuOption('1', "Increase Pot");
					printMenuOption('2', "Decrease Pot");
					printMenuOption('3', "Place Bet");
					printBetBalance(newState.playerBalance, newState.bankBalance, newState.pot);

				break;
			case 2:
				//decrease pot by 20 and add to player balance
				if (newState.pot - 20 >= 20) {

					newState.pot -= 20;
					newState.playerBalance += 20;

					printKid();
					printDialog("My turn to bet");
					printMenuOption('1', "Increase Pot");
					printMenuOption('2', "Decrease Pot");
					printMenuOption('3', "Place Bet");
					printBetBalance(newState.playerBalance, newState.bankBalance, newState.pot);
				}
				else {
					printf("I have to bet something....\n");
				}
				break;
			case 3:
				//exit with message
				printf("match this...");
				break;
			}


		}
		//if player placed bet match it from computer
		newState.bankBalance -= newState.pot;
		newState.pot *= 2;

		system("clr");
		printGameAnimation();
		printf("----- Crazy Ed -------\n");
		printf("Alright here kid!\n");
		printf("--Ed's cash: %d---\n", newState.bankBalance);
		printf("\n");

		
	}
	else {

		//todo: randomize this
		computerBet = 20;

		//subtract computerbet from balance
		newState.bankBalance -= computerBet;

		//set random computer bet to pot
		newState.pot = computerBet;

		printEd();
		printDialog("Ed's Bet");
		printMenuOption('1', "Increase Pot");
		printMenuOption('2', "Decrease Pot");
		printMenuOption('3', "Place Bet");
		printBetBalance(newState.playerBalance, newState.bankBalance, newState.pot);


		while (choice != 3) {

			//check if choice entered
			scanf("%d", &choice);

			switch (choice) {
			case 1:
				//increase pot by 20 and remove from bank balance
				if (newState.bankBalance >= 20 && newState.playerBalance >= (newState.pot + 20)) {

					newState.pot += 20;
					newState.bankBalance -= 20;

					printEd();
					printDialog("Ed's Bet");
					printMenuOption('1', "Increase Pot");
					printMenuOption('2', "Decrease Pot");
					printMenuOption('3', "Place Bet");
					printBetBalance(newState.playerBalance, newState.bankBalance, newState.pot);

				}
				else {
					//check if player is too broke or bank is
					if (newState.playerBalance == 0) {
						printf("I'm too broke.. need to pawn some stuff\n");
					}
					else {
						printf("Ed won't bet that much...\n");
					}
				}
				break;
			case 2:
				//decrease pot by 20 and add to bank balance (can't go lower than computer bet)
				if (newState.pot - 20 >= computerBet) {

					newState.pot -= 20;
					newState.bankBalance += 20;

					printEd();
					printDialog("Ed's Bet");
					printMenuOption('1', "Increase Pot");
					printMenuOption('2', "Decrease Pot");
					printMenuOption('3', "Place Bet");
					printBetBalance(newState.playerBalance, newState.bankBalance, newState.pot);
				}
				else {
					printf("Better Not take Ed's Money...\n");
				}
				break;
			case 3:
				//exit with message
				printf("Second thoughts yet Kid?\n");
				break;
			}

		}
		//if computer placed bet match it from player
		newState.playerBalance -= newState.pot;
		newState.pot *= 2;
		system("clr");
		printGameAnimation();
		printf("----- The Kid -------\n");
		printf("Alright I got the money!\n");
		printf("--Cash now: %d----------\n", newState.playerBalance);
		printf("\n");
		
	}

	return newState;

}

//Computer Turn
struct gameState computerTurn(struct gameState currentState) {

	struct gameState newState = currentState;

	int choice = 0;

	//reset point
	newState.point = 0;

	//reset roll
	newState.currentRoll[0] = 0;
	newState.currentRoll[1] = 0;
	newState.lastRoll[0] = 0;
	newState.lastRoll[1] = 0;

	//initial roll
	newState = diceRoll(newState);

	//display initial roll
	printEd();
	printHeader(newState);
	printDialog("Ed's ganna roll a big one!");
	delayTime(1);
	printDiceAnimation(newState.currentRoll[0]);
	delayTime(1);
	printDiceAnimation(newState.currentRoll[1]);
	delayTime(2);
	printEd();
	printf("Crazy Ed rolled: %d", rollValue(newState, 'c'));
	delayTime(2);

	//check if 7 or 11 
	if (rollValue(newState, 'c') == 7 || rollValue(newState, 'c') == 11) {

		//computer takes pot and dice
		newState.bankBalance += newState.pot;
		newState.pot = 0;
		newState.losses += 1;

		printEd();
		printHeader(newState);
		printDialog("Tough luck Kid!");
		printMenuOption('1', "re-up");
		printMenuOption('2', "cash out");

		
	}
	//check if 2,3 or 12
	else if (rollValue(newState, 'c') == 2 || rollValue(newState, 'c') == 3 || rollValue(newState, 'c') == 12) {

		//computer looses pot, keeps dice
		newState.playerBalance += newState.pot;
		newState.pot = 0;
		newState.wins += 1;
		
		printEd();
		printHeader(newState);
		printDialog("Darn! Want to re-up?");
		printMenuOption('1', "re-up");
		printMenuOption('2', "cash out");

	}
	//else point is assigned and computer keeps rolling
	else {

		//assign point value
		newState.point = rollValue(newState, 'c');

		//roll again
		newState = diceRoll(newState);
		printEd();
		printHeader(newState);
		printDialog("Ed's ganna roll a big one!");
		delayTime(1);
		printDiceAnimation(newState.currentRoll[0]);
		delayTime(1);
		printDiceAnimation(newState.currentRoll[1]);
		delayTime(2);
		printEd();
		printf("Crazy Ed rolled: %d", rollValue(newState, 'c'));
		delayTime(2);

		//keep rolling until 7 
		while (rollValue(newState, 'c') != 7 && rollValue(newState, 'c') != newState.point) {

			//roll again
			newState = diceRoll(newState);

			//display roll
			printEd();
			printHeader(newState);
			printDialog("Ed's ganna roll a big one!");
			delayTime(1);
			printDiceAnimation(newState.currentRoll[0]);
			delayTime(1);
			printDiceAnimation(newState.currentRoll[1]);
			delayTime(2);
			printEd();
			printf("Crazy Ed rolled: %d", rollValue(newState, 'c'));
			delayTime(2);
			
		}

		//If point was rolled first computer gets pot keeps dice
		if (rollValue(newState, 'c') == newState.point) {

			newState.bankBalance += newState.pot;
			newState.pot = 0;
			newState.losses += 1;

			//computer takes pot
			printEd();
			printHeader(newState);
			printDialog("Tough luck Kid!");
			printMenuOption('1', "re-up");
			printMenuOption('2', "cash out");

		}
		//else player gets pot and dice.
		else {

			newState.shooter = 1;
			newState.playerBalance += newState.pot;
			newState.pot = 0;
			newState.wins += 1;

			printEd();
			printHeader(newState);
			printDialog("Darn! Want to re-up?");
			printMenuOption('1', "re-up");
			printMenuOption('2', "cash out");

		}

	}

	return newState;

}

//Player Turn
struct gameState playerTurn(struct gameState currentState) {

	struct gameState newState = currentState;

	int choice = 0;

	//reset point
	newState.point = 0;

	//reset roll
	newState.currentRoll[0] = 0;
	newState.currentRoll[1] = 0;
	newState.lastRoll[0] = 0;
	newState.lastRoll[1] = 0;

	//initial roll
	newState = diceRoll(newState);

	//display initial roll
	printKid();
	printHeader(newState);
	printDialog("I got to get this cash");
	delayTime(1);
	printDiceAnimation(newState.currentRoll[0]);
	delayTime(1);
	printDiceAnimation(newState.currentRoll[1]);
	delayTime(2);
	printKid();
	printf("The Kid Rolled: %d", rollValue(newState, 'c'));
	delayTime(2);

	//check if 7 or 11 
	if (rollValue(newState, 'c') == 7 || rollValue(newState, 'c') == 11) {

		//player takes pot and dice
		newState.playerBalance += newState.pot;
		newState.pot = 0;
		newState.wins += 1;

		printKid();
		printHeader(newState);
		printDialog("Yes! The kid wins");
		printMenuOption('1', "re-up");
		printMenuOption('2', "cash out");


	}
	//check if 2,3 or 12
	else if (rollValue(newState, 'c') == 2 || rollValue(newState, 'c') == 3 || rollValue(newState, 'c') == 12) {

		//player looses pot, keeps dice
		newState.bankBalance += newState.pot;
		newState.pot = 0;
		newState.losses += 1;

		printKid();
		printHeader(newState);
		printDialog("Darn! My moms going to be pissed..");
		printMenuOption('1', "re-up");
		printMenuOption('2', "cash out");

	}
	//else point is assigned and player keeps rolling
	else {

		//assign point value
		newState.point = rollValue(newState, 'c');

		//roll again
		newState = diceRoll(newState);
		printKid();
		printHeader(newState);
		printDialog("I got to get this cash");
		delayTime(1);
		printDiceAnimation(newState.currentRoll[0]);
		delayTime(1);
		printDiceAnimation(newState.currentRoll[1]);
		delayTime(2);
		printf("The Kid rolled: %d", rollValue(newState, 'c'));
		delayTime(2);

		//keep rolling until 7 
		while (rollValue(newState, 'c') != 7 && rollValue(newState, 'c') != newState.point) {

			//roll again
			newState = diceRoll(newState);

			//display roll
			printKid();
			printHeader(newState);
			printDialog("I got to get this cash");
			delayTime(1);
			printDiceAnimation(newState.currentRoll[0]);
			delayTime(1);
			printDiceAnimation(newState.currentRoll[1]);
			delayTime(2);
			printKid();
			printf("The Kid rolled: %d", rollValue(newState, 'c'));
			delayTime(2);

		}

		//If point was rolled first player gets pot keeps dice
		if (rollValue(newState, 'c') == newState.point) {

			newState.playerBalance += newState.pot;
			newState.pot = 0;
			newState.wins += 1;

			//player takes pot
			printKid();
			printHeader(newState);
			printDialog("Yes! The kid wins");
			printMenuOption('1', "re-up");
			printMenuOption('2', "cash out");

		}
		//else computer gets pot and dice.
		else {

			newState.shooter = 2;
			newState.bankBalance += newState.pot;
			newState.pot = 0;
			newState.losses += 1;

			printKid();
			printHeader(newState);
			printDialog("Darn! My moms going to be pissed..");
			printMenuOption('1', "re-up");
			printMenuOption('2', "cash out");

		}

	}

	return newState;

}


/* Main game loop */
struct gameState gameLoop(struct gameState state) {

	int choice = 0;
	int subChoice = 0;

	struct gameState currentState;
	currentState = state;
	currentState.shooter = 0;
	currentState.pot = 0;
	currentState.point = 0;
	//init roll
	currentState.currentRoll[0] = 0;
	currentState.currentRoll[1] = 0;
	currentState.lastRoll[0] = 0;
	currentState.lastRoll[1] = 0;

	/*game loop logic*/

	//check if bank is broke
	if (currentState.bankBalance <= 0) {
		printEd();
		printDialog("Kid, I'm broke. If you want to play payback some of your loans...");
		printMenuOption('1', "Exit");

		while (choice != 1) {
			scanf("%d", &choice);
		}
	}
	//check if player is broke
	else if (currentState.playerBalance <= 0) {
		printKid();
		printDialog("I'm broke. Better go pawn some of my stuff first...");
		printMenuOption('1', "Exit");

		while (choice != 1) {
			scanf("%d", &choice);
		}
	}
	//start game
	else {

		///play or exit*/
		printEd();
		printDialog("Ready to throw Kid?");
		printMenuOption('1', "Throw Dice");
		printMenuOption('2', "Exit");

		choice = 0;

		while (choice != 2) {

			//check if choice entered
			scanf("%d", &choice);

			switch (choice) {
			case 1:
				//throw
				//if shooter hasn't been decided yet
				if (currentState.shooter == 0) {

					//Determine who goes first
					currentState = rollForShooter(currentState);


				}
				//show menu for intial bet
				if (currentState.pot == 0) {

					currentState = fadeMenu(currentState);
				}

				/*player or computer turn*/

				// if computer is shooter play out turn
				if (currentState.shooter == 2) {

					currentState = computerTurn(currentState);
				}
				// if player is shooter play out turn
				else if (currentState.shooter == 1)
				{
					currentState = playerTurn(currentState);

				}

				break;
			case 2:

				break;

			}
		}

	}

	return currentState;

}