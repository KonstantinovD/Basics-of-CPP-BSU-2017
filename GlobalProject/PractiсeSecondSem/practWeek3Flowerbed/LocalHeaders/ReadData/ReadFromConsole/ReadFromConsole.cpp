#include "ReadFromConsole.h"

std::string ReadFromConsole::readLine(){
    std::string str = "";
    std::getline(std::cin, str);
    return str;
}