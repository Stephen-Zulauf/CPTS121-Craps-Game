#include "bank.h"

//Bank screen Loop
struct gameState bankLoop(struct gameState state) {

    int choice = 0;
    struct gameState currentState = state;

    //menu animation
    system("cls");
    bankAnimation();
    printBankMenu();

    //bank menu
    while (choice != 5) {

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            //pawn stuff
            currentState.playerBalance += 20;
            currentState.bankBalance -= 20;
            printBankBalance(currentState.playerBalance, currentState.bankBalance);
            break;
        case 2:
            //pay back ed
            currentState.bankBalance += 20;
            currentState.playerBalance -= 20;
            printBankBalance(currentState.playerBalance, currentState.bankBalance);
            break;
        case 3:
            //reprint menu
            system("cls");
            bankAnimation();
            printBankMenu();
            break;
        case 4:
            //print balances
            printBankBalance(currentState.playerBalance, currentState.bankBalance);
            break;
        case 5:
            //exit
            printf("Good Day");
            break;
        }

    }

    return currentState;
}