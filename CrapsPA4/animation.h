#pragma once
#include "craps.h"

/*main menu animations*/

//print main menu
void printMainMenu();

/*art by Morfina https ://www.asciiart.eu/miscellaneous/dice
print intro animation*/
void introAnimation();

/*art by Morfina https ://www.asciiart.eu/miscellaneous/dice
print short version of intro animation*/
void returnAnimation();

/*bank menu animations*/

//print bank animation
void bankAnimation();

//print banking menu
void printBankMenu();

//print the bank balance
void printBankBalance(int playerBalance, int bankBalance);

/*game loop animations*/

//print gameloop main animation
void printGameAnimation();

//print dice animations
void printDiceAnimation(int);

//print crazy ed
void printEd();

//print the Kid
void printKid();

//print menu option
void printMenuOption(char number, char* lable);

//print dialog
void printDialog (char* dialog);

//print gameplay stats header
void printHeader(struct gameState state);

//print betting balance
void printBetBalance(int playerBalance, int bankBalance, int pot);




