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
    printf("[11] - count-of-slaves-records\n");
    printf("[12] - general-inform\n");
    printf("[13] - clear-all-files\n\n");
    printf("[14] - output-trucks.fl\n");
    printf("[15] - output-trucks.ind\n");
    printf("[16] - output-product.fl\n");
    printf("\n[0] - exit\n");
}
void clearAllFiles(){
    FILE* trucksIndex = fopen("trucks.ind", "w");
    fclose(trucksIndex);

    FILE* trucksFile = fopen("trucks.fl", "w");
    fclose(trucksFile);

    FILE* productsFile = fopen("products.fl", "w");
    fclose(productsFile);

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

    printf("FILE TRUCKS:\n");
    FILE* trucksFile = fopen("trucks.fl", "r+b");
    for(int i = 0; i < inform.countOfTrucks; i++){
        fread(&currentTruck, sizeof(struct Truck), 1, trucksFile);
        outputTheTruck(currentTruck);
    }

    fclose(trucksFile);
}
void outputTrucksIndex(){
    struct Inform inform;
    struct IndexTruck currentIndexTruck;
    inform = collectInformFromInformFile();

    FILE* trucksIndex = fopen("trucks.ind", "r+b");
    printf("INDEX TRUCKS:");
    for(int i = 0; i < inform.countOfTrucks; i++){
        fread(&currentIndexTruck, sizeof(struct IndexTruck), 1, trucksIndex);
        printf("\n[%d] - ", i);
        outputTheIndexTruck(currentIndexTruck);
    }
    printf("\n");
    fclose(trucksIndex);
}
void outputProductsFile(){
    struct Inform inform;
    inform = collectInformFromInformFile();
    struct Product currentProduct;

    printf("FILE PRODUCT:\n");
    FILE* productFile = fopen("products.fl", "r+b");
    for(int i = 0; i < inform.countOfProducts; i++){
        fread(&currentProduct, sizeof(struct Product), 1, productFile);
        outputTheProduct(currentProduct);
    }

    fclose(productFile);
}
int binarySearchIndex(int left, int right, int neededIndex, struct IndexTruck* arrayOfIndexTrucks){
    if (left == right)
        return left;
    int medium = (left+right)/2;
    if (arrayOfIndexTrucks[medium].id > neededIndex)
        binarySearchIndex(left, medium, neededIndex, arrayOfIndexTrucks);
    else
        binarySearchIndex(medium+1, right, neededIndex, arrayOfIndexTrucks);
}
int chooseCorrectIndexOfIdTrucks(struct Inform inform){
    int indexOfSearchedId;
    outputTrucksIndex();
    printf("Choose index:\n");
    scanf("%d", &indexOfSearchedId);
    while (indexOfSearchedId < 0 || indexOfSearchedId > inform.countOfTrucks-1) {
        printf("Wrong id, try again\n");
        outputTrucksIndex();
        scanf("%d", &indexOfSearchedId);
    }
    return indexOfSearchedId;
}
//-----------------------Truck-------------------------------------//
struct Truck createNewTruck(const struct Inform inform){
    struct Truck newTruck;

    printf("Enter brand of the truck:\n");
    scanf("%19s", newTruck.brand);
    printf("Enter loading of the truck(in ton):\n");
    scanf("%d", &newTruck.loading);

    newTruck.id = inform.idInsertedTrucks;
    newTruck.addressNextProduct = -1;
    newTruck.countProducts = 0;

    return newTruck;
}
void outputTheTruck(const struct Truck truck){
    printf("\nTruck Id = %d", truck.id);
    printf("\nTruck brand = %s", truck.brand);
    printf("\nTruck loading(in ton) = %d", truck.loading);
    printf("\naddressNextProduct = %d", truck.addressNextProduct);
    printf("\ncountProducts = %d\n", truck.countProducts);
}
struct Truck* getArrayOfTrucks(struct Inform inform){
    struct Truck* arrayOfTrucks;
    struct Truck currentTruck;
    arrayOfTrucks = (struct Truck*)malloc(inform.countOfTrucks * sizeof(struct Truck));
    FILE* trucksFile = fopen("trucks.fl", "r+b");
    for(int i = 0; i < inform.countOfTrucks; i++){
        fread(&currentTruck, sizeof(struct Truck), 1, trucksFile);
        arrayOfTrucks[i] = currentTruck;
    }
    fclose(trucksFile);

    return arrayOfTrucks;
}
//-----------------------IndexTruck--------------------------------//
struct IndexTruck createNewIndexTruck(struct Truck truck,const struct Inform inform){
    struct IndexTruck newIndexTruck;

    newIndexTruck.id = truck.id;
    newIndexTruck.address = inform.countOfTrucks*(sizeof(struct Truck));

    return newIndexTruck;
}
void outputTheIndexTruck(const struct IndexTruck indexTruck){
    printf("id = %d, address = %d", indexTruck.id, indexTruck.address);
}
struct IndexTruck* getArrayOfIndexTrucks(struct Inform inform){
    struct IndexTruck* arrayOfIndexTrucks;
    struct IndexTruck currentIndexTruck;
    arrayOfIndexTrucks = (struct IndexTruck*)malloc(inform.countOfTrucks * sizeof(struct IndexTruck));
    FILE* trucksIndex = fopen("trucks.ind", "r+b");
    for(int i = 0; i < inform.countOfTrucks; i++){
        fread(&currentIndexTruck, sizeof(struct IndexTruck), 1, trucksIndex);
        arrayOfIndexTrucks[i] = currentIndexTruck;
    }
    fclose(trucksIndex);

    return arrayOfIndexTrucks;
}
//-----------------------Product-----------------------------------//
struct Product createNewProduct(const struct Inform inform){
    struct Product newProduct;
    struct Truck searchedTruck;

    printf("Enter name of the product:\n");
    scanf("%19s", newProduct.name);
    printf("Enter weight of the product:\n");
    scanf("%d", &newProduct.weight);

    newProduct.id = inform.idInsertedProducts;
    searchedTruck = get_m();
    newProduct.idTrucks = searchedTruck.id;
    newProduct.addressNextProduct = -1;

    return newProduct;
}
void outputTheProduct(const struct Product product){
    printf("\nproduct id = %d", product.id);
    printf("\nproduct name = %s", product.name);
    printf("\nproduct weight(in kg) = %d", product.weight);
    printf("\ntrucks id = %d", product.idTrucks);
    printf("\naddressNextProduct = %d\n", product.addressNextProduct);
}
struct Product* getArrayOfProduct(struct Inform inform){
    struct Product* arrayOfProduct;
    struct Product currentProduct;
    arrayOfProduct = (struct Product*)malloc(inform.countOfProducts * sizeof(struct Product));
    FILE* productFile = fopen("products.fl", "r+b");
    for(int i = 0; i < inform.countOfProducts; i++){
        fread(&currentProduct, sizeof(struct Product), 1, productFile);
        arrayOfProduct[i] = currentProduct;
    }
    fclose(productFile);

    return arrayOfProduct;
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

    struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);
    for (int i = 0; i < inform.countOfTrucks; i++){
        printf("[%d] trucks, count of slaves: %d\n", arrayOfTrucks[i].id, arrayOfTrucks[i].countProducts);
    }
}
//-----------------------Main command---------------------------------//
void insert_m(){
    struct Inform inform;
    inform = collectInformFromInformFile();

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
void insert_s(){
    struct Inform inform;
    inform = collectInformFromInformFile();

    struct Product newProduct;
    newProduct = createNewProduct(inform);

    struct IndexTruck* arrayOfIndexTrucks = getArrayOfIndexTrucks(inform);

    int indexOfSearchedTruck = 0;
    for (int i = 0; i < inform.countOfTrucks; i++)
        if (arrayOfIndexTrucks[i].id == newProduct.idTrucks)
            indexOfSearchedTruck = i;

    struct Truck searchedTruck;
    FILE* trucksFile = fopen("trucks.fl", "r+b");
    fseek(trucksFile, arrayOfIndexTrucks[indexOfSearchedTruck].address, 0);
    fread(&searchedTruck, sizeof(struct Truck), 1, trucksFile);
    fclose(trucksFile);

    if (searchedTruck.addressNextProduct == -1){
        FILE* productFile = fopen("products.fl", "a+b");
        fwrite(&newProduct, sizeof(struct Product), 1, productFile);
        fclose(productFile);

        struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);
        FILE* trucksFileWrite = fopen("trucks.fl", "w+b");
        for (int i = 0; i < inform.countOfTrucks; i++){
            if (arrayOfTrucks[i].id == newProduct.idTrucks) {
                arrayOfTrucks[i].addressNextProduct = inform.countOfProducts * sizeof(struct Product);
                arrayOfTrucks[i].countProducts++;
            }
            fwrite(&arrayOfTrucks[i], sizeof(struct Truck), 1, trucksFileWrite);
        }

        fclose(trucksFileWrite);
    } else {

        int index = searchedTruck.addressNextProduct/ sizeof(struct Product);
        struct Product* arrayOfProducts = getArrayOfProduct(inform);

        for (int i = 0; i < inform.countOfProducts; i++)
            outputTheProduct(arrayOfProducts[i]);

        while (arrayOfProducts[index].addressNextProduct != -1)
            index = arrayOfProducts[index].addressNextProduct/ sizeof(struct Product);

        arrayOfProducts[index].addressNextProduct = inform.countOfProducts* sizeof(struct Product);

        FILE* productFile = fopen("products.fl", "w+b");
        for (int i = 0; i < inform.countOfProducts; i++)
            fwrite(&arrayOfProducts[i], sizeof(struct Product), 1, productFile);
        fwrite(&newProduct, sizeof(struct Product), 1, productFile);
        fclose(productFile);

        struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);
        FILE* trucksFileWrite = fopen("trucks.fl", "w+b");
        for (int i = 0; i < inform.countOfTrucks; i++){
            if (arrayOfTrucks[i].id == newProduct.idTrucks)
                arrayOfTrucks[i].countProducts++;
            fwrite(&arrayOfTrucks[i], sizeof(struct Truck), 1, trucksFileWrite);
        }
        fclose(trucksFileWrite);
    }

    inform.countOfProducts++;
    inform.idInsertedProducts++;
    setNewInform(inform);
}
void del_m(){}
void del_s(){}
struct Truck get_m(){
    struct Inform inform;
    inform = collectInformFromInformFile();

    struct IndexTruck* arrayOfIndexTrucks = getArrayOfIndexTrucks(inform);
    int indexOfSearchedId = chooseCorrectIndexOfIdTrucks(inform);

    struct Truck searchedTruck;
    FILE* trucksFile = fopen("trucks.fl", "r+b");
    fseek(trucksFile, arrayOfIndexTrucks[indexOfSearchedId].address, 0);
    fread(&searchedTruck, sizeof(struct Truck), 1, trucksFile);
    fclose(trucksFile);

    return searchedTruck;
}
struct Product get_s(){
    struct Inform inform;
    inform = collectInformFromInformFile();

    struct IndexTruck* arrayOfIndexTrucks = getArrayOfIndexTrucks(inform);
    int indexOfTheTruckInTheArray = chooseCorrectIndexOfIdTrucks(inform);
    struct IndexTruck indexTruck = arrayOfIndexTrucks[indexOfTheTruckInTheArray];

    FILE* trucksFile = fopen("trucks.fl", "r+b");
    struct Truck truck;
    fseek(trucksFile, indexTruck.address, 0);
    fread(&truck, sizeof(struct Truck), 1, trucksFile);
    fclose(trucksFile);

    if (truck.countProducts == 0){
        printf("This truck hasn't got a product yet\n");
        struct Product random;
        random.addressNextProduct=0;
        return random;
    }
    int sizeOfProductsArray = truck.countProducts;
    struct Product* arrayOfSlavesProduct;
    arrayOfSlavesProduct = (struct Product*)malloc(sizeOfProductsArray * sizeof(struct Product));

    FILE* productsFile = fopen("products.fl", "r+b");
    fseek(productsFile, truck.addressNextProduct, 0);
    fread(&arrayOfSlavesProduct[0], sizeof(struct Product), 1, productsFile);
    for (int i = 1; i < sizeOfProductsArray; i++){
        fseek(productsFile, arrayOfSlavesProduct[i-1].addressNextProduct, 0);
        fread(&arrayOfSlavesProduct[i], sizeof(struct Product), 1, productsFile);
    }

    for (int i = 0; i < sizeOfProductsArray; i++)
        printf("[%d] ", i);

    printf("\nChoose the index of the product: ");
    int index;
    scanf("%d", &index);
    return arrayOfSlavesProduct[index];
}
void update_m(){}
void update_s(){}
void ut_m(){}
void ut_s(){}