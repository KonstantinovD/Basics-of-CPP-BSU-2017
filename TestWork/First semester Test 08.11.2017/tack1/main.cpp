#include <string>
#include <iostream>
using namespace std;

bool checkIsLiteral(char& smb)//Check is letter consonant
{
    switch (smb)
    {
    case 'a': case 'A': case 'E': case 'e': case 'I': case 'i': case 'O': case 'o': case 'U': case 'u': case 'Y': case 'y': return false;
    }
    return true;
}

//Punctuation marks usually follows up the word, so we should separate them from words symbols
bool isPunctuationMark(char& smb){
    switch (smb)
    {
    case '.': case ',': case '\"': case '!': case '?': case ':': case ';': case '(':case ')': case '-':case ' ': return true;
    }
    return false;
}

//to catch apostrophe(and all the symbols like it), because it increases the lenght of the word, but isn't a letter
bool isWordSignNotLetter(char& smb){
    switch (smb)
    {
    case '\'': return true;
    }
    return false;
}

void clearString(string& text, int necessaryLenght)
{
    text.append(" ");
    int lenghtOfWord = 0;
    int indexOfBegin = 0;
    int additionalSigns = 0;

    int i = 0;
    while (i < text.length())
    {
        if (false == isPunctuationMark(text[i])) {
            i++;
            lenghtOfWord++;
            if (true == isWordSignNotLetter(text[i])) {
                additionalSigns++;
                lenghtOfWord--;
            }
        }
        else{
            i++;
            if (lenghtOfWord == necessaryLenght){
                if (true == checkIsLiteral(text[indexOfBegin])){
                    for (int i = 0; i < (necessaryLenght + additionalSigns); i++) text.erase(text.begin() + indexOfBegin);
                    if (text[indexOfBegin] == ' ') text.erase(text.begin() + indexOfBegin);//in case puncluation sign follows up the word we shouldn't delete it
                    else {
                        if(indexOfBegin > 0) text.erase(text.begin() + indexOfBegin - 1);
                    }
                    i = indexOfBegin;
                }
            }
            additionalSigns = 0;
            lenghtOfWord = 0;
            indexOfBegin = i;
        }

    }
    text.erase(text.begin() + text.size() - 1);
}


int main()
{
    string text;
    cout << "Input text" << endl;
    getline(cin, text);
    cout << "Input lenght" << endl;
    int necessaryLenght;
    cin >> necessaryLenght;

    clearString(text, necessaryLenght);
  
    cout << text;

    system("pause");
    return 0;
}