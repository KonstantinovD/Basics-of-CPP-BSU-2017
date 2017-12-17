#include "../include/TackInclude.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "../Week8Classes/localHeaders/StackOOP.h"
#include "localHeaders/QueueOOP.h"
#include "localHeaders/ListOOP.h";


struct CommodityItem{ //ANY CHANGES IN THIS SRUCT SHOULD CORRELATE WITH ENUM BELOW IT
    int id;
    std::string name;
    int upc;
    std::string producer;
    unsigned int price;
    unsigned int expireDate;
    unsigned int quantity;
};

enum CommodityItemFields{
    id = 0,
    name,
    upc,
    producer,
    price,
    expireDate,
    quantity,
    FIELDS_PRODUCT
};

struct AverageValue{
    int sum;
    int numberOfItems;
    std::string name;
};


static int countNumberSize(int number){
    int size = 0;
    if (number == 0) return 1;
    while (number != 0){
        number = number / 10;
        size++;
    }
    return size;
}

static void setFormat(ListOOP<CommodityItem> &itemDatabase, int* formatOutput){
    for (int i = 0; i < itemDatabase.getSize(); i++){
        int numberOutputSize = 1;

        //set field 1 format
        numberOutputSize = countNumberSize(itemDatabase.get(i).id);
        if (numberOutputSize > formatOutput[id]) formatOutput[id] = numberOutputSize;
        //set field 2 format
        if (itemDatabase.get(i).name.size() > formatOutput[name]) formatOutput[name] = itemDatabase.get(i).name.size();
        //set field 3 format
        numberOutputSize = countNumberSize(itemDatabase.get(i).upc);
        if (numberOutputSize > formatOutput[upc]) formatOutput[upc] = numberOutputSize;
        //set field 4 format
        if (itemDatabase.get(i).producer.size() > formatOutput[producer]) formatOutput[producer] = itemDatabase.get(i).producer.size();
        //set field 5 format
        numberOutputSize = countNumberSize(itemDatabase.get(i).price);
        if (numberOutputSize > formatOutput[price]) formatOutput[price] = numberOutputSize;
        //set field 6 format
        numberOutputSize = countNumberSize(itemDatabase.get(i).expireDate);
        if (numberOutputSize > formatOutput[expireDate]) formatOutput[expireDate] = numberOutputSize;
        //set field 7 format
        numberOutputSize = countNumberSize(itemDatabase.get(i).quantity);
        if (numberOutputSize > formatOutput[quantity]) formatOutput[quantity] = numberOutputSize;
    }
}

static void outputProduct(std::ofstream& FOUT, CommodityItem& item, int* formatOutput)
{
    FOUT << std::setw(formatOutput[id]) << item.id << "|";
    FOUT << std::setw(formatOutput[name]) << item.name << "|";
    FOUT << std::setw(formatOutput[upc]) << item.upc << "|";
    FOUT << std::setw(formatOutput[producer]) << item.producer << "|";
    FOUT << std::setw(formatOutput[price]) << item.price << "|";
    FOUT << std::setw(formatOutput[expireDate]) << item.expireDate << "|";
    FOUT << std::setw(formatOutput[quantity]) << item.quantity << std::endl;
}

namespace Sorting{

    //For sort2 function
    bool cmp2(AverageValue& first, AverageValue& second){
        if (first.name.compare(second.name)) return false;
        return (first.name < second.name);
    }
    //Sort 2 is necessary for tacks B and C
    void sort2(ListOOP<AverageValue> &list, std::ofstream &FOUT){
        std::vector<AverageValue> outputArr(list.getSize());

        for (int i = 0; i < list.getSize(); i++){
            outputArr[i] = list.get(i);
        }

        std::sort(outputArr.begin(), outputArr.end(), cmp2);

        for (int i = 0; i < outputArr.size(); i++){
            if (outputArr[i].sum == -1){
                FOUT << " " << outputArr[i].name << " " << outputArr[i].numberOfItems << std::endl;
            }
            else FOUT << " " << outputArr[i].name << " " << ((float)outputArr[i].sum / outputArr[i].numberOfItems) << std::endl;
        }
    }

    

    //For sort3 function, tack E
    bool cmp3(CommodityItem& first, CommodityItem& second){
        if (first.price < second.price) return true;
        else {
            if (first.name.compare(second.name)) return false;
            if (first.name < second.name) return true;
        }
        return false;
    }
    //For sort3 function, tack F
    bool cmp4(CommodityItem& first, CommodityItem& second){
        return (first.expireDate < second.expireDate);
    }
    //Sort 3 is necessary for tacks E, F
    void sort3(ListOOP<CommodityItem>& list, std::ofstream &FOUT, int tackNumber = -1){
        std::vector<CommodityItem> outputArr(list.getSize());

        for (int i = 0; i < list.getSize(); i++){
            outputArr[i] = list.get(i);
        }

        if (tackNumber == 1){
            std::sort(outputArr.begin(), outputArr.end(), cmp3);
            for (int i = 0; i < outputArr.size(); i++){
                FOUT << outputArr[i].price << " " << outputArr[i].name << " " << outputArr[i].id << " " << outputArr[i].producer<<std::endl;
            }
            return;
        }

        if (tackNumber == 2){
            std::sort(outputArr.begin(), outputArr.end(), cmp4);
            for (int i = 0; i < outputArr.size(); i++){
                FOUT << " " << outputArr[i].expireDate << " " << outputArr[i].quantity << " " << outputArr[i].name << " " << outputArr[i].id << " " << outputArr[i].upc << std::endl;
            }
            return;
        }
        return;
    }

}



static void tackA(ListOOP<CommodityItem> &database, int* formatOutput, std::ofstream& FOUT){
    FOUT.open("resources/programOutput/Week9_1output1.txt");

    std::string userString;
    std::cout << "input name" << std::endl;
    std::cin >> userString;

    
    for (int i = 0; i < database.getSize(); i++)
    {
        if (database.get(i).name == userString)
            outputProduct(FOUT, database.get(i), formatOutput);
    }
    FOUT.close();
}

static void tackB(ListOOP<CommodityItem> &database, std::ofstream& FOUT){
    
    //Tack B
    FOUT.open("resources/programOutput/Week9_1output2.txt");
    

    AverageValue pushedElement;
    ListOOP<AverageValue> nameAndPrice;

    
    bool isNoElementAdded = false;

    for (int i = 0; i < database.getSize(); i++){
        isNoElementAdded = false;
        for (int j = 0; j < nameAndPrice.getSize(); j++){//Iterate list of unique names with average price
            if (database.get(i).name == nameAndPrice.get(j).name){
                nameAndPrice.get(j).sum += database.get(i).price;
                nameAndPrice.get(j).numberOfItems++;
                isNoElementAdded = true;
                break;
            }
        }
        if (false == isNoElementAdded){
            pushedElement.name = database.get(i).name;
            pushedElement.sum = database.get(i).price;
            pushedElement.numberOfItems = 1;
            nameAndPrice.append(pushedElement);
        }
    }
    Sorting::sort2(nameAndPrice, FOUT);
    FOUT.close();

}

static void tackC(ListOOP<CommodityItem> &database, std::ofstream& FOUT){
    FOUT.open("resources/programOutput/Week9_1output3.txt");
    //ListOOP<CommodityItem> listToSort;

    AverageValue pushedElement;
    ListOOP<AverageValue> creator;


    bool isNoElementAdded = false;

    for (int i = 0; i < database.getSize(); i++){
        isNoElementAdded = false;
        for (int j = 0; j < creator.getSize(); j++){//Iterate list of unique names with average price
            if (database.get(i).producer == creator.get(j).name){
                creator.get(j).numberOfItems++;
                isNoElementAdded = true;
                break;
            }
        }
        if (false == isNoElementAdded){
            pushedElement.name = database.get(i).producer;
            pushedElement.numberOfItems = 1;
            pushedElement.sum = -1;
            creator.append(pushedElement);
        }
    }
    
    Sorting::sort2(creator, FOUT);
    FOUT.close();
}

static void tackD(ListOOP<CommodityItem> &database, int* formatOutput, std::ofstream& FOUT){
    FOUT.open("resources/programOutput/Week9_1output4.txt");

    std::string userString;
    int userValue;
    std::cout << "input name" << std::endl;
    std::cin >> userString;
    std::cout << "input max price" << std::endl;
    std::cin >> userValue;

    //No sort is needed, we have only one type of product to output
    for (int i = 0; i < database.getSize(); i++){
        if (database.get(i).name == userString && database.get(i).price <= userValue){
            outputProduct(FOUT, database.get(i), formatOutput);
        }
    }
    FOUT.close();
}

static void tackE(ListOOP<CommodityItem> &database, std::ofstream& FOUT){
    FOUT.open("resources/programOutput/Week9_1output5.txt");
    Sorting::sort3(database, FOUT, 1);
    FOUT.close();
}

static void tackF(ListOOP<CommodityItem> &database, std::ofstream& FOUT){
    FOUT.open("resources/programOutput/Week9_1output6.txt");
    
    int dateExpire = 0;
    int timeIntervals = 0;
    std::cout << "input limit expire Date" << std::endl;
    std::cout << "input the year" << std::endl;
    std::cin >> dateExpire;

    std::cout << "input the month" << std::endl;
    std::cin >> timeIntervals;
    dateExpire *= 100;
    dateExpire += timeIntervals;

    std::cout << "input the day" << std::endl;
    std::cin >> timeIntervals;
    dateExpire *= 100;
    dateExpire += timeIntervals;

    ListOOP<CommodityItem> unspoiledProducts;
    for (int i = 0; i < database.getSize(); i++){
        if (database.get(i).expireDate > dateExpire){
            unspoiledProducts.append(database.get(i));
        }
    }

    Sorting::sort3(unspoiledProducts, FOUT, 2);
    FOUT.close();
}

static void executeTacks(ListOOP<CommodityItem> &database, int* formatOutput)
{
    std::ofstream FOUT;

    tackA(database, formatOutput, FOUT);
    
    tackB(database, FOUT);

    tackC(database, FOUT);

    tackD(database, formatOutput, FOUT);

    tackE(database, FOUT);

    tackF(database, FOUT);
}



static void chooseProcessing(std::ifstream& FIN){
    int formatOutput[FIELDS_PRODUCT];//Array to store arguments for setw();
    for (int i = 0; i < FIELDS_PRODUCT; i++) formatOutput[i] = 0;

    int numberOfProducts;
    FIN >> numberOfProducts; 
    if (numberOfProducts < 1) return;

    ListOOP<CommodityItem> itemDatabase;

    CommodityItem tempObjForListAdding;
    for (int i = 0; i < numberOfProducts; i++){
        FIN >> tempObjForListAdding.id >> tempObjForListAdding.name >> tempObjForListAdding.upc >> tempObjForListAdding.producer;
        FIN >> tempObjForListAdding.price >> tempObjForListAdding.expireDate >> tempObjForListAdding.quantity;
        itemDatabase.append(tempObjForListAdding);
    }
    setFormat(itemDatabase, formatOutput);

    executeTacks(itemDatabase, formatOutput);//main work, choosing and sorting
}

void processingFilesWeek9_1(std::ifstream& FIN)
{
    FIN.open("resources/processingFilesWeek9_1.txt");
    chooseProcessing(FIN);
}




/*
//For sort3 function, the last tack
bool cmp1(CommodityItem& first, CommodityItem& second){
if (first.name.compare(second.name)) return false;
if (first.name < second.name) return true;
}*/

/*
if (tackNumber == 3){
std::sort(outputArr.begin(), outputArr.end(), cmp1);
for (int i = 0; i < outputArr.size(); i++){
outputProduct(FOUT, outputArr[i], formatOutput);
}
return;
}*/