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
    printf("[11] - general-inform\n");
    printf("[12] - clear-all-files\n\n");
    printf("[13] - output-trucks.ind\n");
    printf("[14] - output-product.fl\n");
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
    info.idInsertedTrucks = info.countOfExistingTrucks = info.countOfExistingProducts = info.idInsertedProducts = 0;
    fwrite(&info, sizeof(struct Inform), 1, inform);
    fclose(inform);
}
void outputTrucksIndex(){
    struct Inform inform;
    struct IndexTruck currentIndexTruck;
    inform = collectInformFromInformFile();

    FILE* trucksIndex = fopen("trucks.ind", "r+b");
    printf("INDEX TRUCKS:");
    for(int i = 0; i < inform.idInsertedTrucks; i++){
        fread(&currentIndexTruck, sizeof(struct IndexTruck), 1, trucksIndex);
        if (currentIndexTruck.isExist) {
            printf("\n[%d] - ", i);
            outputTheIndexTruck(currentIndexTruck);
        }
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
    for(int i = 0; i < inform.idInsertedProducts; i++){
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
    struct IndexTruck* arrayOfIndexTruck = getArrayOfIndexTrucks(inform);

    int indexOfSearchedId;
    outputTrucksIndex();
    printf("Choose index of truck:\n");
    scanf("%d", &indexOfSearchedId);
    while (indexOfSearchedId < 0 || indexOfSearchedId > inform.idInsertedTrucks-1 || !arrayOfIndexTruck[indexOfSearchedId].isExist) {
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
    newTruck.isExist = true;

    return newTruck;
}
void outputTheTruck(const struct Truck truck){
    printf("\nTruck Id = %d", truck.id);
    printf("\nTruck brand = %s", truck.brand);
    printf("\nTruck loading(in ton) = %d", truck.loading);
    printf("\naddressNextProduct = %d", truck.addressNextProduct);
    printf("\ncountProducts = %d", truck.countProducts);
    printf("\nisExist = %d\n", truck.isExist);
}
struct Truck* getArrayOfTrucks(struct Inform inform){
    struct Truck* arrayOfTrucks;
    struct Truck currentTruck;
    arrayOfTrucks = (struct Truck*)malloc(inform.idInsertedTrucks * sizeof(struct Truck));
    FILE* trucksFile = fopen("trucks.fl", "r+b");
    for(int i = 0; i < inform.idInsertedTrucks; i++){
        fread(&currentTruck, sizeof(struct Truck), 1, trucksFile);
        arrayOfTrucks[i] = currentTruck;
    }
    fclose(trucksFile);

    return arrayOfTrucks;
}
void setArrayOfTrucks(struct Inform inform, struct Truck* arrayOfTrucks){
    FILE* trucksFile = fopen("trucks.fl", "w+b");
    for (int i = 0; i < inform.idInsertedTrucks; i++)
        fwrite(&arrayOfTrucks[i], sizeof(struct Truck), 1, trucksFile);
    fclose(trucksFile);
}
//-----------------------IndexTruck--------------------------------//
struct IndexTruck createNewIndexTruck(struct Truck truck,const struct Inform inform){
    struct IndexTruck newIndexTruck;

    newIndexTruck.id = truck.id;
    newIndexTruck.address = inform.idInsertedTrucks*(sizeof(struct Truck));
    newIndexTruck.isExist = true;

    return newIndexTruck;
}
void outputTheIndexTruck(const struct IndexTruck indexTruck){
    printf("id = %d, address = %d, isExist = %d", indexTruck.id, indexTruck.address, indexTruck.isExist);
}
struct IndexTruck* getArrayOfIndexTrucks(struct Inform inform){
    struct IndexTruck* arrayOfIndexTrucks;
    struct IndexTruck currentIndexTruck;
    arrayOfIndexTrucks = (struct IndexTruck*)malloc(inform.idInsertedTrucks * sizeof(struct IndexTruck));
    FILE* trucksIndex = fopen("trucks.ind", "r+b");
    for(int i = 0; i < inform.idInsertedTrucks; i++){
        fread(&currentIndexTruck, sizeof(struct IndexTruck), 1, trucksIndex);
        arrayOfIndexTrucks[i] = currentIndexTruck;
    }
    fclose(trucksIndex);

    return arrayOfIndexTrucks;
}
struct Truck getTruckById(struct Inform inform){
    struct IndexTruck* arrayOfIndexTrucks = getArrayOfIndexTrucks(inform);
    int indexOfTheTruckInTheArray = chooseCorrectIndexOfIdTrucks(inform);
    struct IndexTruck indexTruck = arrayOfIndexTrucks[indexOfTheTruckInTheArray];

    FILE* trucksFile = fopen("trucks.fl", "r+b");
    struct Truck truck;
    fseek(trucksFile, indexTruck.address, 0);
    fread(&truck, sizeof(struct Truck), 1, trucksFile);
    fclose(trucksFile);
    return truck;
}
void setArrayOfIndexTrucks(struct Inform inform, struct IndexTruck* arrayOfIndexTrucks){
    FILE* trucksIndex = fopen("trucks.ind", "w+b");
    for (int i = 0; i < inform.idInsertedTrucks; i++)
        fwrite(&arrayOfIndexTrucks[i], sizeof(struct IndexTruck), 1, trucksIndex);
    fclose(trucksIndex);
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
    newProduct.isExist = true;

    return newProduct;
}
void outputTheProduct(const struct Product product){
    printf("\n\tproduct id = %d", product.id);
    printf("\n\tproduct name = %s", product.name);
    printf("\n\tproduct weight(in kg) = %d", product.weight);
    printf("\n\ttrucks id = %d", product.idTrucks);
    printf("\n\taddressNextProduct = %d", product.addressNextProduct);
    printf("\n\tisExist = %d\n", product.isExist);
}
struct Product* getArrayOfProduct(struct Inform inform){
    struct Product* arrayOfProduct;
    struct Product currentProduct;
    arrayOfProduct = (struct Product*)malloc(inform.idInsertedProducts * sizeof(struct Product));
    FILE* productFile = fopen("products.fl", "r+b");
    for(int i = 0; i < inform.idInsertedProducts; i++){
        fread(&currentProduct, sizeof(struct Product), 1, productFile);
        arrayOfProduct[i] = currentProduct;
    }
    fclose(productFile);

    return arrayOfProduct;
}
struct Product* getArrayOfSlavesProduct(struct Truck masterTruck){
    int sizeOfProductsArray = masterTruck.countProducts;
    struct Product* arrayOfSlavesProduct;
    struct Product tempProduct;
    arrayOfSlavesProduct = (struct Product*)malloc(sizeOfProductsArray * sizeof(struct Product));

    int i = 0;
    FILE* productsFile = fopen("products.fl", "r+b");
    fseek(productsFile, masterTruck.addressNextProduct, 0);
    fread(&tempProduct, sizeof(struct Product), 1, productsFile);
    if (tempProduct.isExist) {
        arrayOfSlavesProduct[i] = tempProduct;
        i++;
    }

    while (tempProduct.addressNextProduct != -1){
        fseek(productsFile, tempProduct.addressNextProduct, 0);
        fread(&tempProduct, sizeof(struct Product), 1, productsFile);
        if (tempProduct.isExist) {
            arrayOfSlavesProduct[i] = tempProduct;
            i++;
        }
    }
    fclose(productsFile);

    return arrayOfSlavesProduct;
}
void setArrayOfProducts(struct Inform inform, struct Product* arrayOfProducts){
    FILE* productsFile = fopen("products.fl", "w+b");
    for (int i = 0; i < inform.idInsertedProducts; i++)
        fwrite(&arrayOfProducts[i], sizeof(struct Product), 1, productsFile);
    fclose(productsFile);
}
/*void deleteLastOneProduct(struct Inform inform, struct Truck truck){
    struct Product* arrayOfProducts = getArrayOfProduct(inform);
    struct IndexTruck* arrayOfIndexTruck = getArrayOfIndexTrucks(inform);
    struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);

    bool flag = true;

    for (int i = 0; i < inform.countOfTrucks && flag; i++)
        if (arrayOfTrucks[i].id == truck.id){
            arrayOfTrucks[i].countProducts = 0;
            arrayOfTrucks[i].addressNextProduct = -1;
            flag = false;
        }

    int indexOfDeletedProduct = truck.addressNextProduct/ sizeof(struct Product);
    if (inform.countOfProducts == 1 || indexOfDeletedProduct == inform.countOfProducts-1){
        inform.countOfProducts--;
        setArrayOfTrucks(inform, arrayOfTrucks);
        setArrayOfProducts(inform, arrayOfProducts);
        setNewInform(inform);
        return;
    }



    struct Product lastProduct = arrayOfProducts[inform.countOfProducts-1];
    arrayOfProducts[indexOfDeletedProduct] = lastProduct;
    int indexInArrayMasterLastProduct = binarySearchIndex(0,inform.countOfTrucks-1,lastProduct.idTrucks, arrayOfIndexTruck);

    struct IndexTruck indexMasterLastProduct = arrayOfIndexTruck[indexInArrayMasterLastProduct];
    struct Truck masterLastProduct = arrayOfTrucks[indexMasterLastProduct.address/ sizeof(struct Truck)];

    if (masterLastProduct.addressNextProduct/ sizeof(struct Product) == inform.countOfProducts-1){

        masterLastProduct.addressNextProduct = indexOfDeletedProduct* sizeof(struct Product);
        arrayOfTrucks[indexMasterLastProduct.address/ sizeof(struct Truck)] = masterLastProduct;

        setArrayOfTrucks(inform, arrayOfTrucks);
        setArrayOfProducts(inform, arrayOfProducts);
        inform.countOfProducts--;
        setNewInform(inform);
        return;
    }

    struct Product* currentProduct = &arrayOfProducts[masterLastProduct.addressNextProduct/ sizeof(struct Product)];
    while (arrayOfProducts[currentProduct->addressNextProduct/ sizeof(struct Product)].id != lastProduct.id)
        currentProduct = &arrayOfProducts[currentProduct->addressNextProduct/ sizeof(struct Product)];

    currentProduct->addressNextProduct = indexOfDeletedProduct* sizeof(struct Product);

    setArrayOfProducts(inform, arrayOfProducts);
    setArrayOfTrucks(inform, arrayOfTrucks);
    inform.countOfProducts--;
    setNewInform(inform);
}
void deleteLastProduct(struct Inform inform, struct Truck truck){
    struct Product* arrayOfProducts = getArrayOfProduct(inform);
    struct IndexTruck* arrayOfIndexTruck = getArrayOfIndexTrucks(inform);
    struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);

    bool flag = true;

    for (int i = 0; i < inform.countOfTrucks && flag; i++)
        if (arrayOfTrucks[i].id == truck.id){
            arrayOfTrucks[i].countProducts--;
            flag = false;
        }

}*/
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
    inform.countOfExistingTrucks = 0;
    inform.countOfExistingProducts = 0;
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

    printf("\ncountOfTrucks is %d", inform.countOfExistingTrucks);
    printf("\ncountOfProducts is %d\n\n", inform.countOfExistingProducts);

    struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);
    for (int i = 0; i < inform.idInsertedTrucks; i++){
        if (arrayOfTrucks[i].isExist)
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

    inform.countOfExistingTrucks++;
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
    for (int i = 0; i < inform.idInsertedTrucks; i++)
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
        for (int i = 0; i < inform.idInsertedTrucks; i++){
            if (arrayOfTrucks[i].id == newProduct.idTrucks) {
                arrayOfTrucks[i].addressNextProduct = inform.idInsertedProducts * sizeof(struct Product);
                arrayOfTrucks[i].countProducts++;
            }
            fwrite(&arrayOfTrucks[i], sizeof(struct Truck), 1, trucksFileWrite);
        }

        fclose(trucksFileWrite);
    } else {

        int index = searchedTruck.addressNextProduct/ sizeof(struct Product);
        struct Product* arrayOfProducts = getArrayOfProduct(inform);

        while (arrayOfProducts[index].addressNextProduct != -1)
            index = arrayOfProducts[index].addressNextProduct/ sizeof(struct Product);

        arrayOfProducts[index].addressNextProduct = inform.idInsertedProducts* sizeof(struct Product);

        FILE* productFile = fopen("products.fl", "w+b");
        for (int i = 0; i < inform.idInsertedProducts; i++)
            fwrite(&arrayOfProducts[i], sizeof(struct Product), 1, productFile);
        fwrite(&newProduct, sizeof(struct Product), 1, productFile);
        fclose(productFile);

        struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);
        FILE* trucksFileWrite = fopen("trucks.fl", "w+b");
        for (int i = 0; i < inform.idInsertedTrucks; i++){
            if (arrayOfTrucks[i].id == newProduct.idTrucks)
                arrayOfTrucks[i].countProducts++;
            fwrite(&arrayOfTrucks[i], sizeof(struct Truck), 1, trucksFileWrite);
        }
        fclose(trucksFileWrite);
    }

    inform.countOfExistingProducts++;
    inform.idInsertedProducts++;
    setNewInform(inform);
}
void del_m(){
    struct Inform inform;
    inform = collectInformFromInformFile();

    struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);
    struct Product* arrayOfProducts = getArrayOfProduct(inform);
    struct IndexTruck* arrayOfIndexTruck = getArrayOfIndexTrucks(inform);

    int indexOfTheTruckInTheArray = chooseCorrectIndexOfIdTrucks(inform);
    struct Truck* masterDeletedTruck = &arrayOfTrucks[indexOfTheTruckInTheArray];

    arrayOfIndexTruck[masterDeletedTruck->id].isExist = false;
    masterDeletedTruck->isExist = false;

    struct Product* slaveProduct = &arrayOfProducts[masterDeletedTruck->addressNextProduct/ sizeof(struct Product)];
    if (slaveProduct->isExist)
        slaveProduct->isExist = false;
    while (slaveProduct->addressNextProduct != -1){
        slaveProduct = &arrayOfProducts[slaveProduct->addressNextProduct/ sizeof(struct Product)];
        slaveProduct->isExist = false;
    }

    setArrayOfTrucks(inform, arrayOfTrucks);
    setArrayOfIndexTrucks(inform, arrayOfIndexTruck);
    setArrayOfProducts(inform, arrayOfProducts);
    inform.countOfExistingProducts -= masterDeletedTruck->countProducts;
    inform.countOfExistingTrucks--;
    setNewInform(inform);

}
void del_s(){
    struct Inform inform;
    inform = collectInformFromInformFile();

    struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);
    struct Product* arrayOfProducts = getArrayOfProduct(inform);
    struct IndexTruck* arrayOfIndexTruck = getArrayOfIndexTrucks(inform);

    int indexOfTheTruckInTheArray = chooseCorrectIndexOfIdTrucks(inform);
    struct Truck* masterDeletedTruck = &arrayOfTrucks[indexOfTheTruckInTheArray];

    if (masterDeletedTruck->countProducts == 0){
        printf("This truck hasn't got a product yet\n");
        return;
    }

    struct Product* arrayOfSlavesProduct = getArrayOfSlavesProduct(*masterDeletedTruck);
    for (int i = 0; i < masterDeletedTruck->countProducts; i++)
        printf("[%d] ", arrayOfSlavesProduct[i].id);
    printf("\nChoose the id of deleted product: ");
    int idOfDeletedProduct;
    scanf("%d", &idOfDeletedProduct);
    arrayOfProducts[idOfDeletedProduct].isExist = false;
    masterDeletedTruck->countProducts--;

    setArrayOfProducts(inform, arrayOfProducts);
    setArrayOfTrucks(inform, arrayOfTrucks);
    inform.countOfExistingProducts--;
    setNewInform(inform);


}
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

    struct Truck truck = getTruckById(inform);

    if (truck.countProducts == 0){
        printf("This truck hasn't got a product yet\n");
        struct Product random;
        random.addressNextProduct=-2;
        return random;
    }

    int sizeOfProductsArray = truck.countProducts;
    struct Product* arrayOfSlavesProduct = getArrayOfSlavesProduct(truck);

    for (int i = 0; i < sizeOfProductsArray; i++)
        printf("[%d] ", i);

    printf("\nChoose the index of the product: ");
    int index;
    scanf("%d", &index);
    return arrayOfSlavesProduct[index];
}
void update_m(){
    struct Inform inform;
    inform = collectInformFromInformFile();

    struct IndexTruck* arrayOfIndexTrucks = getArrayOfIndexTrucks(inform);
    int indexOfSearchedId = chooseCorrectIndexOfIdTrucks(inform);

    struct Truck updatedTruck;
    FILE* trucksFile = fopen("trucks.fl", "r+b");
    fseek(trucksFile, arrayOfIndexTrucks[indexOfSearchedId].address, 0);
    fread(&updatedTruck, sizeof(struct Truck), 1, trucksFile);
    fclose(trucksFile);

    outputTheTruck(updatedTruck);
    printf("Choose the field you want to change\n");
    printf("[0] - brand\n");
    printf("[1] - loading\n");
    int field;
    scanf("%d", &field);
    if (field == 0){
        printf("Enter a new brand:\n");
        scanf("%s", updatedTruck.brand);
    } else {
        printf("Enter a new loading:\n");
        scanf("%d", &updatedTruck.loading);
    }

    struct Truck* arrayOfTrucks = getArrayOfTrucks(inform);
    int indexOfTruck = arrayOfIndexTrucks[indexOfSearchedId].address/ sizeof(struct Truck);
    arrayOfTrucks[indexOfTruck] = updatedTruck;

    trucksFile = fopen("trucks.fl", "w+b");
    for (int i = 0; i < inform.idInsertedTrucks; i++)
        fwrite(&arrayOfTrucks[i], sizeof(struct Truck),1,trucksFile);
    fclose(trucksFile);
}
void update_s(){
    struct Inform inform;
    inform = collectInformFromInformFile();

    struct Truck truck = getTruckById(inform);

    if (truck.countProducts == 0){
        printf("This truck hasn't got a product yet\n");
        return;
    }

    int sizeOfProductsArray = truck.countProducts;
    struct Product* arrayOfSlavesProduct = getArrayOfSlavesProduct(truck);

    for (int i = 0; i < sizeOfProductsArray; i++)
        printf("[%d] ", i);

    printf("\nChoose the index of the product: ");
    int index;
    scanf("%d", &index);
    outputTheProduct(arrayOfSlavesProduct[index]);
    struct Product updatedProduct = arrayOfSlavesProduct[index];


    printf("Choose the field you want to change\n");
    printf("[0] - name\n");
    printf("[1] - weight\n");
    int field;
    scanf("%d", &field);
    if (field == 0){
        printf("Enter a new name:\n");
        scanf("%s", updatedProduct.name);
    } else {
        printf("Enter a new weight:\n");
        scanf("%d", &updatedProduct.weight);
    }

    struct Product* arrayOfProducts = getArrayOfProduct(inform);
    if (index == 0)
        index = truck.addressNextProduct/ sizeof(struct Product);
    else
        index = arrayOfSlavesProduct[index-1].addressNextProduct/ sizeof(struct Product);
    arrayOfProducts[index] = updatedProduct;

    FILE* productsFile = fopen("products.fl", "w+b");
    for (int i = 0; i < inform.idInsertedProducts; i++)
        fwrite(&arrayOfProducts[i], sizeof(struct Product),1,productsFile);
    fclose(productsFile);
}
void ut_m(){
    struct Inform inform;
    struct Truck currentTruck;
    inform = collectInformFromInformFile();

    printf("FILE TRUCKS:\n");
    FILE* trucksFile = fopen("trucks.fl", "r+b");
    for(int i = 0; i < inform.idInsertedTrucks; i++){
        fread(&currentTruck, sizeof(struct Truck), 1, trucksFile);
        if (currentTruck.isExist)
            outputTheTruck(currentTruck);
    }

    fclose(trucksFile);
}
void ut_s(){
    struct Inform inform;
    struct Truck currentTruck;
    inform = collectInformFromInformFile();

    printf("FILE TRUCKS:\n");
    FILE* trucksFile = fopen("trucks.fl", "r+b");
    for(int i = 0; i < inform.idInsertedTrucks; i++){
        fread(&currentTruck, sizeof(struct Truck), 1, trucksFile);
        if (currentTruck.isExist) {
            outputTheTruck(currentTruck);
            if (currentTruck.countProducts > 0) {
                struct Product *arrayOfSlavesProduct = getArrayOfSlavesProduct(currentTruck);
                printf("\nPRODUCTS: \n");
                for (int j = 0; j < currentTruck.countProducts; j++)
                    outputTheProduct(arrayOfSlavesProduct[j]);

            }
            printf("--------------------------------------------------------\n");
        }
    }

    fclose(trucksFile);
}