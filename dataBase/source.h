//
// Created by Admin on 20.09.2020.
//

#ifndef DATABASE_SOURCE_H
#define DATABASE_SOURCE_H

#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Truck{
    int id;
    char brand[20];
    int loading;

    int addressNextProduct;
    int countProducts;
    bool isExist;
};

struct IndexTruck{
    int id;
    int address;
    bool isExist;
};

struct Product{
    int id;
    char name[20];
    int weight;
    int idTrucks;

    int addressNextProduct;
    bool isExist;
};

struct Inform{
    int idInsertedTrucks;
    int idInsertedProducts;

    int countOfExistingTrucks;
    int countOfExistingProducts;
};
void outputListOfCommand();

struct Inform collectInformFromInformFile();
void setNewInform(const struct Inform inform);
void setDefaultInform();
void outputInformFromFile();
void checkInformFile();

struct Truck createNewTruck(const struct Inform inform);
void outputTheTruck(const struct Truck truck);
struct Truck* getArrayOfTrucks(struct Inform inform);
void setArrayOfTrucks(struct Inform inform, struct Truck* arrayOfTrucks);
struct Truck getTruckById(struct Inform inform);

struct IndexTruck createNewIndexTruck(struct Truck truck, const struct Inform inform);
void outputTheIndexTruck(const struct IndexTruck indexTruck);
struct IndexTruck* getArrayOfIndexTrucks(const struct Inform inform);
void setArrayOfIndexTrucks(struct Inform inform, struct IndexTruck* arrayOfIndexTrucks);

struct Product createNewProduct(const struct Inform inform);
void outputTheProduct(const struct Product product);
struct Product* getArrayOfProduct(const struct Inform inform);
void setArrayOfProducts(struct Inform inform, struct Product* arrayOfProducts);
struct Product* getArrayOfSlavesProduct(struct Truck masterTruck);
void deleteLastOneProduct(struct Inform inform, struct Truck truck);
void deleteLastProduct(struct Inform inform, struct Truck truck);

void insert_m();
void insert_s();
void del_m();
void del_s();
struct Truck get_m();
struct Product get_s();
void update_m();
void update_s();
void ut_m();
void ut_s();

void clearAllFiles();
void outputTrucksIndex();
void outputProductsFile();
int binarySearchIndex(int left, int right, int neededIndex, struct IndexTruck* arrayOfIndexTrucks);
int chooseCorrectIndexOfIdTrucks(struct Inform Inform);
#endif //DATABASE_SOURCE_H
