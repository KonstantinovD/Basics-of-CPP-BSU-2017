#include "../../include/TackInclude.h"
#include <iostream>
#include <algorithm>
#include <string>

#include "localHeaders\TemplateArr.h"

template <typename T>
static void prntIntArr(TemplateArr<T>& arr){
    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }std::cout << std::endl;
}

void templatesPractW1_3(std::ifstream& FIN){

    TemplateArr<int> intar(3);
    prntIntArr(intar);

    intar[2] = 4;
    prntIntArr(intar);

    intar.insert(2, 44);
    prntIntArr(intar);

    TemplateArr<int>::iterator iterObj = intar.begin();
    std::advance(iterObj, 2);
    std::cout << *(iterObj) << std::endl;
    for (int i = 0; i < intar.size(); i++){
        intar[i] = i + 1;
    }
    prntIntArr(intar);

    intar.push_front(70);
    prntIntArr(intar);

    intar.push_back(-43);
    prntIntArr(intar);

    intar.pop_back();
    prntIntArr(intar);
    intar.pop_back();
    prntIntArr(intar);

    intar.erase(2);
    prntIntArr(intar);

    intar.push_back(-40);
    intar.push_back(12);
    prntIntArr(intar);

    std::cout << "elements are: ";
    std::for_each(intar.begin(), intar.end(), [](int v){std::cout << v << " "; });
    std::cout << std::endl << "there are ";
    int numberOfOdd = std::count_if(intar.begin(), intar.end(), [](int n){ return n % 2 == 0; });
    std::cout << numberOfOdd << " odd numbers" << std::endl;



    TemplateArr<std::string> text(3, "-");
    prntIntArr(text);

    text[2] = "mum";
    prntIntArr(text);

    text.insert(2, "dad");
    prntIntArr(text);

    TemplateArr<std::string>::iterator iterStr = text.begin();
    std::advance(iterStr, 2);

    std::cout << *(iterStr) << std::endl;
   

    char elem = 'A';
    std::string insStr = "";
    for (int i = 0; i < text.size(); i++){

        insStr.push_back(elem);
        text[i] = insStr;
        elem++;
    }
    prntIntArr(text);

    text.push_front("PUSHFRONT");
    prntIntArr(text);

    text.push_back("PUSHBACK");
    prntIntArr(text);

    text.pop_back();
    prntIntArr(text);
    text.pop_back();
    prntIntArr(text);

    text.erase(2);
    prntIntArr(text);

    text.push_back("PB2");
    text.push_back("PB3");
    prntIntArr(text);

    std::cout << "elements are: ";
    std::for_each(text.begin(), text.end(), [](std::string s){std::cout << s << " "; });
    std::cout << std::endl << "there are ";

    int numberOfAStart = std::count_if(text.begin(), text.end(), [](std::string s){ return s.front() == 'A'; });
    std::cout << numberOfAStart << " strings which starts from \"A\"" << std::endl;


}