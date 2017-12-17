#include "..\include\TackInclude.h"
#include <iostream>

#include "localHeaders\symbol.h"
#include "localHeaders\Word.h"
#include "localHeaders\WordNumber.h"
#include "localHeaders\Sentence.h"





void wordProcessingWeek10_1(std::ifstream& FIN){

    Word slovo1, slovo2;
    char* cStr = "deprecatedString";
    char smb = 'T';
    char* ptrstr = nullptr;

    slovo1.set(cStr);
    slovo2.set(smb);

    Word slovo3(slovo1);

    std::cout << slovo1 << " | " << slovo2 << " | " << slovo3 << std::endl << std::endl;

    int size = slovo3.get(cStr);
    int gsiz = slovo3.get(ptrstr, false);
    for (int i = 0; i < gsiz; i++) std::cout << ptrstr[i];
    std::cout << std::endl;

    for (int i = 0; i < size; i++) std::cout << cStr[i];
    std::cout << std::endl;

    Word spell1("arora"), spell2("noon");

    std::cout << spell1.isPalindrom() << " " << spell2.isPalindrom() << " " << slovo1.isPalindrom() << " " << slovo2.isPalindrom() << std::endl;

    Word w1("night"), w2("day"), w4("dan");
    Word w3 = w2;

    if (w3 == w2) std::cout << "w3 == w2" << std::endl;
    if (w1 == w2) std::cout << "w1 == w2" << std::endl;

    std::cout << (w1 < w2) << " " << (w2 < w1) << " " << (w2 < w2) << " " << (w4 < w2) << std::endl;

    Word n1("123"),
        n2("1313"),
        n3("123.11.23"),
        n4("0.15"),
        n5("abc"),
        n6("23f3.2"),
        n7("2500000000");

    std::cout << n1.isWordNumber() << " " << n2.isWordNumber() << " " << n3.isWordNumber() << " " << n4.isWordNumber() << " " << n5.isWordNumber() << " " << n6.isWordNumber()<<" " <<n7.isWordNumber()<<std::endl;

    n1 = n1;
    std::cout << n1 << std::endl;

    WordNumber numb1("100"),
        numb2("1025"),
        numb3("1"),
        numb4(numb1),
        numb5("25");

    WordNumber NNB("100");
    NNB.setNumber(120);
    std::cout << "  ___ " << NNB << std::endl;

    for (int i = 9; i < 11; i++){
        NNB.setNumber(i);
        std::cout << "  ___ " << NNB << std::endl;
    }

    std::cout << numb1 << " " << numb2 << " " << numb3 << " " << numb4 << std::endl;

    for (int i = 0; i < 3; i++){
        WordNumber numb14("123");
        std::cout << numb14 << std::endl;
    }


    int simplyValue = numb1.getNumber();
    std::cout << simplyValue << std::endl;
    simplyValue += 20;

    std::cout << simplyValue << std::endl;

    numb4 = numb1 + numb3;
    std::cout << numb4 << std::endl;

    numb4 = numb4 + NNB;
    std::cout << numb4 << std::endl;

    numb1.setNumber(12);
    numb2.setNumber(2);
    numb3.setNumber(4);
    numb4.setNumber(5);

    std::cout << "**************************" << std::endl;
    numb5 = numb1*numb2;
    std::cout << numb5 << std::endl;

    numb5 = numb1/numb3;
    std::cout << numb5 << std::endl;

    numb5 = numb1/numb4;
    std::cout << numb5 << std::endl;

    std::cout << "**************************" << std::endl;
    Word phrase1("dot dot");
    std::cout << phrase1 << std::endl;
    Word phrase3(' ');
    std::cout << phrase3 << std::endl;
    std::cout << "**************************" << std::endl;

    char* gh = "ohh my pretty woman.";


    Sentence s1("dooo, yes, yes!"),
        s2("abrak  adabra"),
        s3(s2),
        s4('f');

    char* mystr = nullptr;
    char* nu = "dododo";
    int size2;

    size2 = s1.get(mystr, false);
    for (int i = 0; i < size2; i++) std::cout << mystr[i];
    std::cout << "\n";
    size2 = s2.get(nu);
    std::cout << nu << std::endl;

    s4 = s2;
    s4.get(nu);
    std::cout << nu << std::endl;
    s4 += s1;
    s4.get(nu);
    std::cout << nu << std::endl;

    Sentence st1("grow"), st2("grow"), st3(st1);
    Sentence st4("arro"), st5("wrww"), st6("www");

    std::cout << (st1 == st2) << " " << (st1 == st3) << " " << (st2 == st3) << std::endl;
    std::cout << (st1 == st4) << " " << (st5 == st6) << std::endl;

    std::cout << (st4 < st1) << " " << (st5 > st1) << " " << (st6 > st1) << std::endl;
    std::cout << (st1 < st3) << " " << (st6 < st4) << std::endl;
    
    std::cout << st1 << " " << st6 << std::endl;

    st1.set("new");
    st2.set(st4);
    char* srtrt = "aces in exile";

    st3.set(srtrt + 5, 2);

    std::cout << st1 << " " << st2 << " " << st3<<std::endl;
    std::cout << "**************************" << std::endl;

    std::cout << st1.get(1) << std::endl;
    //std::cout <<" " << st1.get(4);

    Sentence words("actual means of communications");
    int pos = words.findWord("of", 4);
    std::cout << pos << std::endl;
    pos = words.findWord("cat");
    std::cout << pos << std::endl;
    pos = words.findWord("of", 210);
    std::cout << pos << std::endl;
    pos = words.findWord("of", 20);
    std::cout << pos << std::endl;
    pos = words.findWord("means");
    std::cout << pos << std::endl;

    for (int i = pos; i < pos + 5; i++) std::cout << words.get(i);
    std::cout << std::endl;

    pos = words.findWord(20, "communications");
    std::cout << pos << std::endl;
    pos = words.findWord("communications");
    std::cout << pos << std::endl;
}