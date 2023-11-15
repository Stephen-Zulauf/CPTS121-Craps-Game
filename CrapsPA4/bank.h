#pragma once

#include "craps.h"

void bankAnimation();

//prints menu for bank screen
void printBankMenu();

void printBankBalance(int playerBalance, int bankBalance);

struct gameState bankLoop(struct gameState state);