//
// Created by Admin on 20.09.2020.
//

#ifndef DATABASE_SOURCE_H
#define DATABASE_SOURCE_H

#include <stdbool.h>
#include <stdio.h>

struct Truck{
    int id;
    char brand[20];
    int loading;

    int addressNextProduct;
    int countProducts;
    bool deleted;
};

struct IndexTruck{
    int id;
    int address;
};

struct Product{
    int id;
    char name[20];
    int weight;

    int idTrucks;
    bool deleted;
    int addressNextProduct;
};

struct Inform{
    int idInsertedTrucks;
    int idInsertedProducts;
    int countOfTrucks;
    int countOfProducts;

};
void outputListOfCommand();

struct Inform collectInformFromInformFile();
void setNewInform(const struct Inform inform);
void setDefaultInform();
void outputInformFromRAM(const struct Inform inform);
void outputInformFromFile();
void checkInformFile();

struct Truck createNewTruck(const struct Inform inform);
void outputTheTruck(const struct Truck truck);
struct IndexTruck createNewIndexTruck(struct Truck truck, const struct Inform inform);

void insert_m();

void clearAllFiles();
void outputTrucksFile();
void outputTruckIndex();
void outputProductsFile();
#endif //DATABASE_SOURCE_H
