#include <stdio.h>
#include "source.h"

int main() {
    checkInformFile();
    outputInformFromFile();

    int command;
    bool flag = true;
    while (flag) {
        outputListOfCommand();
        scanf("%d", &command);

        switch (command) {
            case 1:
                insert_m();
                break;
            case 12:
                outputInformFromFile();
                break;
            case 13:
                clearAllFiles();
                break;
            case 14:
                outputTrucksFile();
                break;
            case 0:
                flag = false;
                break;
            default:
                printf("Wrong case\n");

        }
    }
    return 0;
}
