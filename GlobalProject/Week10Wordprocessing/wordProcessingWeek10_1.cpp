#include "..\include\TackInclude.h"
#include <iostream>
#include <fstream>

#include "localHeaders\symbol.h"
#include "localHeaders\Word.h"
#include "localHeaders\WordNumber.h"
#include "localHeaders\Sentence.h"
#include "localHeaders\Text.h"


void wordProcessingWeek10_1(std::ifstream& FIN){

    /*
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

    Sentence words("actual means of communications of");
    int pos = words.findWord("of", 20);
    std::cout << pos <<" +_+_+_+_+_"<< std::endl;
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

    std::cout <<std::endl<< "***********************" << std::endl;
    Sentence words2("actual: means of communication: are, developed faster and faster"),
        words3(words2);
    std::cout << words2.getLenght() << std::endl;
    std::cout << words2.amountOfWords() << std::endl;
    words2.deleteWord("are");
    std::cout << words2 << std::endl;
    words2.deleteWord("off");
    std::cout << words2 << std::endl;
    words2.deleteWord(6, "faster");
    std::cout << words2 << std::endl;

    words2.deleteWord("means", 7);
    std::cout << words2 << std::endl;
    std::cout << words2.amountOfWords() << std::endl;

    std::cout << "***********************" << std::endl;
    std::cout << "***********************" << std::endl;

    words3.insertWord(6, "for us", 7);
    std::cout << words3 << std::endl;

    words3.insertWord("forewer", 71);
    std::cout << words3 << std::endl;

    words3.insertWord("we");
    std::cout << words3 << std::endl;
    //words3.changeWord(13, "communication", 7, "talking", 0);
    //std::cout << words3 << std::endl;
    words3.changeWord(13, "communication", 7, "talking", 27);
    std::cout << words3 << std::endl;
    words3.changeWord(Word("actual"), Word("slower"));
    std::cout << words3 << std::endl;
    std::cout << words3.amountOfWords() << std::endl;

    char* str = nullptr;
    int sizeWord = words3.getWord(3, str);
    for (int i = 0; i < sizeWord; i++) std::cout << str[i];
    std::cout << std::endl;

    std::cout << words3.getWord(5) << std::endl;
    pos = words3.findWord(Word("forewer"));
    std::cout << pos << std::endl;
    words3.deleteWord(Word("means"));
    std::cout << words3 << std::endl;
    words3.swapWords(4, 7);
    std::cout << words3 << std::endl;
    //std::cout << words3.swapWordsByIndexs(3, 59) << std::endl;;
    words3.swapWords(1, 9);
    std::cout << words3 << std::endl;
    words3.swapWords(1, 12);
    std::cout << words3 << std::endl;

    words3.swapWordsByIndexs(8, 36);
    std::cout << words3 << std::endl;

    words3.swapWords(2, 3);
    std::cout << words3 << std::endl;

    words3.sortWords();
    std::cout << words3 << std::endl;

    std::cout << (Word("of") > Word("we")) << std::endl;

    WordNumber* arr = nullptr;
    Sentence strWithNum("A 100 years old man said that it was 36 years ago in 1980, when the 23000 men vote for John.");
    

    int amountOfWN = 0;
    //int amountOfWN = strWithNum.findWordNumbers(arr);

    //for (int i = 0; i < amountOfWN; i++) std::cout << arr[i] << " ";
    //std::cout << std::endl;

    Sentence anotherNum("abr 124.12 bo now it 123 isn't 599 um33 utf-8 to the river");
    amountOfWN = anotherNum.findWordNumbers(arr);
    for (int i = 0; i < amountOfWN; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    int sum;
    amountOfWN = anotherNum.SortWordNumbers(arr, sum);
    for (int i = 0; i < amountOfWN; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << sum << std::endl;

    Text txt("now");
    Text t2("again");

    std::cout << (txt < t2) << std::endl;

    txt.push_back(anotherNum);
    std::cout << txt << std::endl;

    txt.push_back(Sentence("But. it actually was. Really! I know it."));
    std::cout << txt <<"|"<< std::endl;

    std::cout << txt.findSentWithCommonWords() << std::endl;

    std::cout << '\n' << '\n' <<"----------------------------"<< '\n';
    */
    FIN.open("resources/wordProcessingWeek10_1.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    const int MAX_STR_SIZE = 1000;

    for (int i = 0; i < numberOfTests; i++)
    {
        /*
        char inpText[MAX_STR_SIZE];
        //FIN.get();
        //FIN.getline(inpText, MAX_STR_SIZE);

        FIN.get();
        int it = 0;
        char a;
        while (!FIN.eof() && it < MAX_STR_SIZE){
            inpText[it] = FIN.get();
            if (inpText[it] == -1){
                it--;
            }
            it++;
        }


        Text story(inpText, it);
        Word spell;

        std::cout << "Searching of common words:" << std::endl<<std::endl;
        std::cout<<story.findSentWithCommonWords()<<std::endl;
        std::cout<<std::endl << story << std::endl;

        std::cout << "input word to find its position: ";
        std::cin.get();
        std::cin.getline(inpText, MAX_STR_SIZE);
        std::cout << "input position to start search from: ";
        int pos;
        std::cin >> pos;
        std::cout << story.findWord(inpText, pos)<<std::endl;

        std::cout << "input word to check is it a palindrom: ";
        std::cin.get();
        std::cin.getline(inpText, MAX_STR_SIZE);
        spell.set(inpText);
        std::cout << "is it a palindrom? " << spell.isPalindrom() << std::endl;

        std::cout << "input word to delete it: ";
        std::cin.getline(inpText, MAX_STR_SIZE);
        spell.set(inpText);
        std::cout << "input position to start from: ";
        std::cin >> pos;
        std::cout << "Has word been deleted? " << story.deleteWord(spell, pos) << std::endl;
        std::cout << story << std::endl;

        
        int pos2;
        std::cout << "input the number of the first word to swap it: ";
        std::cin >> pos;
        std::cout << "input the number of the second word to swap it: ";
        std::cin >> pos2;
        std::cout << "Have words been swapped? " << story.swapWords(pos, pos2) << std::endl;
        std::cout << story << std::endl<<std::endl;

        std::cout << "sort words: " << std::endl;
        story.sortWords();
        std::cout << story << std::endl;
        std::cout << std::endl;

        std::cout <<"find WordNumbers"<< std::endl;
        WordNumber* arr = nullptr;
        Sentence anotherNum("abr 124.12 bo now it 123 isn't 599 um33 utf-8 to the river");
        int amountOfWN = anotherNum.findWordNumbers(arr);
        for (int i = 0; i < amountOfWN; i++) std::cout << arr[i] << " ";
        std::cout << std::endl;
        delete[] arr;
        std::cout << std::endl;

        std::cout << "sort WordNumbers and find sum" << std::endl;
        arr = nullptr;
        int sumOfWordNumbers;
        amountOfWN = anotherNum.SortWordNumbers(arr, sumOfWordNumbers);
        for (int i = 0; i < amountOfWN; i++) std::cout << arr[i] << " ";
        std::cout << std::endl;
        std::cout <<"result sum is "<< sumOfWordNumbers << std::endl;

        /*
        std::cout << "Searching of common words:" << std::endl;

        story.findSentWithCommonWords();*/
        
        Text tex("dror");
        std::cout << tex << std::endl;

        tex.deleteWord("dror", 0);
        std::cout << tex << std::endl;

    }

}