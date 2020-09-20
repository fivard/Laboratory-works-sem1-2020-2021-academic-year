//
// Created by Admin on 20.09.2020.
//

#ifndef DATABASE_SOURCE_H
#define DATABASE_SOURCE_H

struct Truck{
    int id;
    char brand[20];
    int loading;
};

struct indexFile{
    int id;
    int address;
};

struct Product{
    int id;
    char name[20];
    int weight;
};

#endif //DATABASE_SOURCE_H
