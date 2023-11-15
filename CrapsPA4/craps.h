#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "gameloop.h"
#include "bank.h"
#include "animation.h"


//struct to hold persisted game data
struct gameState {
	int wins;
	int losses;
	int bankBalance;
	int playerBalance;

	//0 if undecided 1 if player going first 2 if computer
	int shooter;
	//current pot
	int pot;
	//current roll
	int currentRoll[2];
	//last roll
	int lastRoll[2];
	//point
	int point;
	//turn counter
	int turn;
};

//Open dat file and return game state
struct gameState loadGameData();

//Write game state to dat file
int saveGameData(struct gameState);

//takes seconds to delay with a while loop
void delayTime(int);

//get random number between (1-limit)
int getRandomNumber(int);

