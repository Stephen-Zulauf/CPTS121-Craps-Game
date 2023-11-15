

#include "craps.h"
#include "animation.h"

//Open dat file and return game data struct
//todo:check for success
struct gameState loadGameData() {

    FILE* inFile = NULL;
    inFile = fopen("bankBalance.dat", "r");

    struct gameState state;
    fscanf(inFile, "wins = %d\n", &state.wins);
    fscanf(inFile, "losses = %d\n", &state.losses);
    fscanf(inFile, "bank = %d\n", &state.bankBalance);
    fscanf(inFile, "player = %d\n", &state.playerBalance);

    return state;
}

//Write game state to dat file
//todo:check for success
int saveGameData(struct gameState state){
    FILE* outFile = NULL;
    outFile = fopen("bankBalance.dat", "w");

    fprintf(outFile, "wins = %d\n", state.wins);
    fprintf(outFile, "losses = %d\n", state.losses);
    fprintf(outFile, "bank = %d\n", state.bankBalance);
    fprintf(outFile, "player = %d\n", state.playerBalance);

    return 0;
}

//takes seconds to dalay with a while loop
void delayTime(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds) {
        ;
    }

}

//get random number between (1-limit)
int getRandomNumber(int limit) {
    int random;

    random = rand() % limit + 1;

    return random;

}





