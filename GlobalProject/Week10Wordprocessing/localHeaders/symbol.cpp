#include "symbol.h"

Symbol::Symbol(){character = ' ';}
Symbol::Symbol(const Symbol& obj){character = obj.character;}
Symbol::Symbol(char smb){ character = smb; }
Symbol::Symbol(char* str){
    if (strlen(str) > 0) character = str[0];
    else character = ' ';
}

char Symbol::get(){ return character; }

void Symbol::set(const Symbol& obj){ character = obj.character; }
void Symbol::set(char smb){ character = smb; }
void Symbol::set(char* str){ 
    if (strlen(str) > 0) character = str[0];
    else character = ' ';
}

bool Symbol::isNumeral(){
    return isdigit(character);
}

Symbol& Symbol::operator=(Symbol smb){
    this->character = smb.character;
    return *this;
}

bool Symbol::operator==(Symbol smb){
    return(this->character == smb.character);
}
