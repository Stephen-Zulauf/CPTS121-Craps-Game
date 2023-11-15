#include "animation.h"

void printMainMenu() {
    printf("Select a choice from the menu:\n");
    printf("(1) Play Craps!\n");
    printf("(2) Pawn Shop\n");
    printf("(3) Reprint Menu\n");
    printf("(4) Exit\n");
    printf("\n");
}

//Art by Morfina https://www.asciiart.eu/miscellaneous/dice
void introAnimation() {
    printf("CRAP");
    delayTime(1);
    system("cls");
    printf("--CRAP");
    delayTime(1);
    system("cls");
    printf("---CRAP");
    delayTime(1);
    system("cls");
    printf("----CRAP");
    delayTime(1);
    system("cls");
    printf("-----CRAP");
    delayTime(1);
    system("cls");
    printf("------CRAP");
    delayTime(1);
    system("cls");
    printf("-------CRAP");
    delayTime(1);
    system("cls");
    printf("--------CRAP");
    delayTime(1);
    system("cls");
    printf("---------CRAP");
    delayTime(1);
    system("cls");
    printf("----------CRAP");
    delayTime(1);
    system("cls");
    printf("-----------CRAP");
    delayTime(1);
    system("cls");
    printf("------------CRAP");
    delayTime(1);
    system("cls");
    printf("-------------CRAP");
    delayTime(1);
    system("cls");
    printf("--------------CRAP");
    delayTime(1);
    system("cls");
    printf("---------------CRAP");
    delayTime(1);
    system("cls");
    printf("----------------CRAP");
    delayTime(1);
    system("cls");
    printf("-----------------CRAP");
    delayTime(1);
    system("cls");
    printf("------------------CRAP");
    delayTime(1);
    system("cls");
    printf("-------------------CRAP");
    delayTime(1);
    system("cls");
    printf("--------------------CRAPS");
    delayTime(1);
    printf("\n");
    printf("               (( _______\n");
    printf("     _______     /\\O    O\\\n");
    printf("    /O     /\\   /  \\      \\\n");
    printf("   /   O  /O \\ / O  \\O____O\\ ))\n");
    printf("((/_____O/    \\\\    /O     /\n");
    printf("  \\O    O\\    / \\  /   O  /\n");
    printf("   \\O    O\\ O/   \\/_____O/\n");
    printf("    \\O____O\\/ )) mrf      ))\n");
    printf("  ((\n");
    printf("\n");
    delayTime(1);
    printf("-------------------------\n");

}

//Art by Morfina https://www.asciiart.eu/miscellaneous/dice
void returnAnimation() {
    printf("--------------------CRAPS");
    printf("\n");
    printf("               (( _______\n");
    printf("     _______     /\\O    O\\\n");
    printf("    /O     /\\   /  \\      \\\n");
    printf("   /   O  /O \\ / O  \\O____O\\ ))\n");
    printf("((/_____O/    \\\\    /O     /\n");
    printf("  \\O    O\\    / \\  /   O  /\n");
    printf("   \\O    O\\ O/   \\/_____O/\n");
    printf("    \\O____O\\/ )) mrf      ))\n");
    printf("  ((\n");
    printf("\n");
    printf("-------------------------\n");
}

/*Bank menu animations*/

void bankAnimation() {
    printf("\n");
    printf("---ED's Pawn Shop---\n");
    printf("  .     '     ,\n");
    printf("    _________\n");
    printf(" _ /_|_____|_\\ _\n");
    printf("   '. \\   / .'\n");
    printf("     '.\\ /.'\n");
    printf("       '.'\n");
    printf("\n");
}

void printBankMenu() {

    printf("Select a choice from the menu:\n");
    printf("(1) Pawn Something\n");
    printf("(2) Pay Loan\n");
    printf("(3) Reprint Menu\n");
    printf("(4) Print Balance\n");
    printf("(5) Exit\n");
    printf("\n");

}

void printBankBalance(int playerBalance, int bankBalance) {
    system("cls");
    bankAnimation();
    printBankMenu();
    printf("--------------------------\n");
    printf("| Player Balance: $%d     |\n", playerBalance);
    printf("|                         |\n");
    printf("| Ed's Balance:   $%d     |\n", bankBalance);
    printf("|                         |\n");
    printf("|                         |\n");
    printf("--------------------------\n");
    printf("\n");
}

/*Game Loop Animations*/

//print gameloop main animation
void printGameAnimation() {
    system("cls");
    printf("\n");
    printf("                      ____...  \n");
    printf("             .-\"--\"\"\"\".__    `.\n");
    printf("            |            `    |\n");
    printf("  (         `._....------.._.:\n");
    printf("   )         .()''        ``().\n");
    printf("  '          () .=='  `===  `-.\n");
    printf("   . )       (  (0)    (0)      \n");
    printf("    )         )     /        J\n");
    printf("   (          |.   /      . (\n");
    printf("   $$         (.  (_'.   , )|`\n");
    printf("   ||         |\\`-....--'/  ' \\\n");
    printf("  /||.        \\  | | | /  /   \\.\n");
    printf(" //||(\\        \\ `-===-'  '    \\o.\n");
    printf(".//7' |)         `. --   / (     OObaaaad888b.\n");
    printf("(<<. / |     .a888b`.__.'d\\     OO888888888888a.\n");
    printf(" \\  Y' |    .8888888aaaa88POOOOOO888888888888888.\n");
    printf("  \\  \\ |   .888888888888888888888888888888888888b\n");
    printf("   |   |  .d88888P88888888888888888888888b8888888.\n");
    printf("   b.--d .d88888P8888888888888888a:f888888|888888b\n");
    printf("   88888b 888888|8888888888888888888888888\\8888888\n");
    printf("\n");
}

//print dice animations
void printDiceAnimation(int diceValue) {

    switch (diceValue) {
    case 1:
        printf("     _______ \n");
        printf("    |       |\n");
        printf("    |   o   |\n");
        printf("    |       |\n");
        printf("    '-------'\n");
        break;
    case 2:
        printf("     _______ \n");
        printf("    | o     |\n");
        printf("    |       |\n");
        printf("    |     o |\n");
        printf("    '-------'\n");
        break;
    case 3:
        printf("     _______ \n");
        printf("    | o     |\n");
        printf("    |   o   |\n");
        printf("    |     o |\n");
        printf("    '-------'\n");
        break;
    case 4:
        printf("     _______ \n");
        printf("    | o   o |\n");
        printf("    |       |\n");
        printf("    | o   o |\n");
        printf("    '-------'\n");
        break;
    case 5:
        printf("     _______ \n");
        printf("    | o   o |\n");
        printf("    |   o   |\n");
        printf("    | o   o |\n");
        printf("    '-------'\n");
        break;
    case 6:
        printf("     _______ \n");
        printf("    | o   o |\n");
        printf("    | o   o |\n");
        printf("    | o   o |\n");
        printf("    '-------'\n");
        break;
    }

}

void printEd() {
    system("cls");
    printf("\n");
    printf("                      ____...  \n");
    printf("             .-\"--\"\"\"\".__    `.\n");
    printf("            |            `    |\n");
    printf("  (         `._....------.._.:\n");
    printf("   )         .()''        ``().\n");
    printf("  '          () .=='  `===  `-.\n");
    printf("   . )       (  (0)    (0)      \n");
    printf("    )         )     /        J\n");
    printf("   (          |.   /      . (\n");
    printf("   $$         (.  (_'.   , )|`\n");
    printf("   ||         |\\`-....--'/  ' \\\n");
    printf("  /||.        \\  | | | /  /   \\.\n");
    printf(" //||(\\        \\ `-===-'  '    \\o.\n");
    printf(".//7' |)         `. --   / (     OObaaaad888b.\n");
    printf("(<<. / |     .a888b`.__.'d\\     OO888888888888a.\n");
    printf(" \\  Y' |    .8888888aaaa88POOOOOO888888888888888.\n");
    printf("  \\  \\ |   .888888888888888888888888888888888888b\n");
    printf("   |   |  .d88888P88888888888888888888888b8888888.\n");
    printf("   b.--d .d88888P8888888888888888a:f888888|888888b\n");
    printf("   88888b 888888|8888888888888888888888888\\8888888\n");
    printf("\n");
    printf("-----------------Crazy Ed----------------------------\n");
}

void printKid() {
    system("cls");
    printf("\n");
    printf("      ////^\\\\\\\\\n");
    printf("      | ^   ^ |\n");
    printf("     @ (o) (o) @\n");
    printf("      |   <   |\n");
    printf("      |  ___  |\n");
    printf("       \\_____/\n");
    printf("     ____|  |____\n");
    printf("    /    \\__/    \\\n");
    printf("   /              \\\n");
    printf("  /\\_/|        |\\_/\\\n");
    printf(" / /  |        |  \\ \\\n");
    printf("( <   |        |   > )\n");
    printf(" \\ \\  |        |  / /\n");
    printf("  \\ \\ |________| / /\n");
    printf("   \\ \\|\n");
    printf("\n");
    printf("-------The Kid--------\n");
}

void printMenuOption(char number, char* lable) {
    printf("%c) %s\n", number, lable);
}

//print dialog
void printDialog(char* dialog) {
    printf("\"%s\"\n", dialog);
}

//print gameplay stats header
void printHeader(struct gameState state) {
    printf("|Last Role:%d-Point:%d-Pot:%d|\n", rollValue(state, 'l'),state.point,state.pot);

}

//print betting balance
void printBetBalance(int playerBalance, int bankBalance, int pot) {
    printf("\n");
    printf("--------------------------\n");
    printf("| Player Balance: $%d     |\n", playerBalance);
    printf("|                         |\n");
    printf("| Bank Balance:   $%d     |\n", bankBalance);
    printf("|                         |\n");
    printf("| Pot:            $%d     |\n", pot);
    printf("--------------------------\n");
    printf("\n");
    
}
