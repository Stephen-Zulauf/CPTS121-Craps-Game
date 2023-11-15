#pragma once
#include "craps.h"

//roll dice
struct gameState diceRoll(struct gameState currentState);

//get roll value; "l"- last roll "c"-current roll
int rollValue(struct gameState currentState, char lastOrCurrent);

//decide who goes first
struct gameState rollForShooter(struct gameState);

//betting menu
struct gameState fadeMenu(struct gameState currentState);

//computer turn
struct gameState computerTurn(struct gameState currentState);

//player turn
struct gameState playerTurn(struct gameState currentState);

//Main game loop
struct gameState gameLoop(struct gameState);