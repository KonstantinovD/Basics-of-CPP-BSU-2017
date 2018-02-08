#include "Text.h"
#include <iostream>

Text::Text(char* str) : Sentence(str)
{

}
Text::Text(char* str, int size) : Sentence()
{
    Sentence::set(str, size);
}
Text::Text(char smb) : Sentence(smb)
{

}
Text::Text(const Text& txt) : Sentence(txt.sentenceStr)
{

}

void Text::push_back(const Sentence& sent){
    this->Sentence::operator+=(Sentence(' '));
    this->Sentence::operator+=(sent);
}

void Text::sortWords(){
    updateSentBegins();
    Sentence::sortWords();
}

void Text::updateSentBegins(){
    sentBegins.clear();
    int begin = 0;

    for (int i = 0; i < lenght - 1; i++){
        if (true == isEndOfSentence(i)){
            if (isSeparatorSign(sentenceStr[i + 1])){
                sentBegins.push_back(std::pair<int, int>(begin, i));
                begin = i + 2;
                while (true == isSeparatorSign(sentenceStr[begin]) && begin < lenght){
                    begin++;
                }
            }
        }
    }
    if (begin < lenght){
        sentBegins.push_back(std::pair<int, int>(begin, lenght - 1));
    }

    std::list<std::pair<int, int>>::iterator it = sentBegins.begin();
    while (it != sentBegins.end()){
        if (it->first == it->second){
            char gbuf = sentenceStr[it->first];
            if (true == isPunctuationMark(sentenceStr[it->first])){
                it = sentBegins.erase(it);
                it--;
            }
        }
        it++;
    }
}

bool Text::isEndOfSentence(int index){
    
    if (index == lenght - 1) return true;

    switch (sentenceStr[index]){
    case '.': case '!': case '?':{ return true; }
    }
    return false;
}

int Text::findSentWithCommonWords(){
    updateSentBegins();
    Sentence* allSent = new Sentence[sentBegins.size()];

    std::list<std::pair<int, int>>::iterator it;
    int arrIt = 0;
    for (it = sentBegins.begin(); it != sentBegins.end(); it++){
        allSent[arrIt].set(sentenceStr + it->first, it->second - it->first + 1);
        arrIt++;
    }

    int maxNumber = 1;
    int localNumber = 1;
    Word compareWord;
    Word resWord;
    for (int i = 0; i < arrIt; i++){//Итерируем предложения
        for (int j = 1; j <= allSent[i].amountOfWords(); j++){//Итерируем слова в предложении
            localNumber = 1;//Каждое слово есть хотя бы в одном предложении
            compareWord.set(allSent[i].getWord(j));
            for (int k = 0; k < i; k++){
                if (allSent[k].findWordLocal(compareWord) != -1) localNumber++;
            }
            for (int k = i + 1; k < arrIt; k++){
                if (allSent[k].findWordLocal(compareWord) != -1) localNumber++;
            }
            if (localNumber > maxNumber) {
                maxNumber = localNumber;
                resWord = compareWord;
            }
        }
    }
    for (int i = 0; i < sentBegins.size(); i++) std::cout << allSent[i] << std::endl;
    std::cout << resWord << std::endl;

    delete[] allSent;
    return maxNumber;
}