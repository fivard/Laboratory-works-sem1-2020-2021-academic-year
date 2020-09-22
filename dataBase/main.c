#include <stdio.h>
#include "source.h"

int main() {
    checkInformFile();
    outputInformFromFile();

    int command;
    bool flag = true;
    struct Truck truck;
    struct Product product;
    while (flag) {
        outputListOfCommand();
        scanf("%d", &command);

        switch (command) {
            case 1:
                insert_m();
                break;
            case 2:
                insert_s();
                break;
            case 3:
                del_m();
                break;
            case 4:
                del_s();
                break;
            case 5:
                truck = get_m();
                outputTheTruck(truck);
                break;
            case 6:
                product = get_s();
                outputTheProduct(product);
            case 7:
                update_m();
                break;
            case 8:
                update_s();
                break;
            case 9:
                ut_m();
                break;
            case 10:
                ut_s();
                break;
            case 11:
                outputInformFromFile();
                break;
            case 12:
                clearAllFiles();
                break;
            case 13:
                outputTrucksIndex();
                break;
            case 14:
                outputProductsFile();
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
