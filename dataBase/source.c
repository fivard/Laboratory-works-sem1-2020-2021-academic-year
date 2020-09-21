//
// Created by Admin on 20.09.2020.
//

#include "source.h"

void outputListOfCommand(){
    printf("\nChoose the number of a command: \n");
    printf("[1] - insert-m\n");
    printf("[2] - insert-s\n");
    printf("[3] - del-m\n");
    printf("[4] - del-s\n");
    printf("[5] - get-m\n");
    printf("[6] - get-s\n");
    printf("[7] - update-m\n");
    printf("[8] - update-s\n");
    printf("[9] - ut-m\n");
    printf("[10] - ut-s\n");
    printf("[11] - count-of-slave-records\n");
    printf("[12] - general-inform\n");
    printf("[13] - clear-all-files\n");
    printf("[14] - output-trucks.fl\n");
    printf("\n[0] - exit\n");
}
void clearAllFiles(){
    FILE* trucksIndex = fopen("trucks.ind", "w");
    fclose(trucksIndex);

    FILE* trucksFile = fopen("trucks.fl", "w");
    fclose(trucksFile);

    FILE* inform = fopen("inform.dat", "w+b");
    struct Inform info;
    info.idInsertedTrucks = info.countOfTrucks = info.countOfProducts = info.idInsertedProducts = 0;
    fwrite(&info, sizeof(struct Inform), 1, inform);
    fclose(inform);
}
void outputTrucksFile(){
    struct Inform inform;
    struct Truck currentTruck;
    inform = collectInformFromInformFile();

    FILE* trucksFile = fopen("trucks.fl", "r+b");
    for(int i = 0; i < inform.countOfTrucks; i++){
        fread(&currentTruck, sizeof(struct Truck), 1, trucksFile);
        outputTheTruck(currentTruck);
    }

    fclose(trucksFile);
}
//-----------------------Truck-------------------------------------//
struct Truck createNewTruck(const struct Inform inform){
    struct Truck newTruck;

    printf("Enter brand of the truck:\n");
    scanf("%19s", newTruck.brand);
    printf("Enter loading of the truck:\n");
    scanf("%d", &newTruck.loading);

    newTruck.id = inform.idInsertedTrucks;
    newTruck.addressNextProduct = -1;
    newTruck.countProducts = 0;
    newTruck.deleted = false;

    return newTruck;
}
void outputTheTruck(const struct Truck truck){
    printf("\nTruck Id = %d", truck.id);
    printf("\nTruck brand = %s", truck.brand);
    printf("\nTruck loading(int ton) = %d", truck.loading);
    printf("\naddressNextProduct = %d", truck.addressNextProduct);
    printf("\ncountProducts = %d", truck.countProducts);
    printf("\ndeleted = %d\n", truck.id);
}
//-----------------------IndexTruck--------------------------------//
struct IndexTruck createNewIndexTruck(struct Truck truck,const struct Inform inform){
    struct IndexTruck newIndexTruck;

    newIndexTruck.id = truck.id;
    newIndexTruck.address = inform.countOfTrucks*(sizeof(struct Truck));

    return newIndexTruck;
}
//-----------------------Inform------------------------------------//
void checkInformFile(){
    FILE* size_info = fopen("inform.dat", "r+b");

    fseek(size_info,0,SEEK_END);
    int pos = ftell(size_info);
    fseek(size_info, 0, SEEK_SET);
    fclose(size_info);

    if (pos == -1)
        setDefaultInform();
}
struct Inform collectInformFromInformFile(){
    struct Inform inform;

    FILE* size_info = fopen("inform.dat", "r+b");
    fread(&inform, sizeof(struct Inform), 1, size_info);
    fclose(size_info);
    return inform;
}
void setDefaultInform(){
    FILE* info = fopen("inform.dat", "w+b");
    struct Inform inform;
    printf("Data base is empty\n");
    printf("Filling...\n");
    inform.idInsertedProducts = 0;
    inform.idInsertedTrucks = 0;
    inform.countOfProducts = 0;
    inform.countOfTrucks = 0;
    fwrite(&inform, sizeof(struct Inform), 1, info);
    fclose(info);
}
void setNewInform(struct Inform inform){
    FILE* info = fopen("inform.dat", "w+b");
    fwrite(&inform, sizeof(struct Inform), 1, info);
    fclose(info);
}
void outputInformFromFile(){
    struct Inform inform;
    inform = collectInformFromInformFile();
    printf("\nIdInsertedTrucks is %d", inform.idInsertedTrucks);
    printf("\nidInsertedProducts is %d", inform.idInsertedProducts);
    printf("\ncountOfTrucks is %d", inform.countOfTrucks);
    printf("\ncountOfProducts is %d\n\n", inform.countOfProducts);

    //TODO Посчитать для каждого грузовика количество продуктов
}
void outputInformFromRAM(struct Inform inform){
    printf("\nIdInsertedTrucks is %d", inform.idInsertedTrucks);
    printf("\nidInsertedProducts is %d", inform.idInsertedProducts);
    printf("\ncountOfTrucks is %d", inform.countOfTrucks);
    printf("\ncountOfProducts is %d\n\n", inform.countOfProducts);
}

//-----------------------Main command---------------------------------//
void insert_m(){
    struct Inform inform;
    inform = collectInformFromInformFile();
    printf("START\n");
    outputInformFromFile(inform);

    struct Truck newTruck;
    struct IndexTruck newIndexTruck;

    newTruck = createNewTruck(inform);
    newIndexTruck = createNewIndexTruck(newTruck, inform);

    FILE* trucksFile = fopen("trucks.fl", "a+b");
    fwrite(&newTruck, sizeof(struct Truck), 1, trucksFile);
    fclose(trucksFile);

    FILE* trucksIndex = fopen("trucks.ind", "a+b");
    fwrite(&newIndexTruck, sizeof(struct IndexTruck), 1, trucksIndex);
    fclose(trucksIndex);

    inform.countOfTrucks++;
    inform.idInsertedTrucks++;
    setNewInform(inform);
}