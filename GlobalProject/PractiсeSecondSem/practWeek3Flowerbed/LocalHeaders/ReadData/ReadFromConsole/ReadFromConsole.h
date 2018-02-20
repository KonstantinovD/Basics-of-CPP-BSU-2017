#ifndef _READFROMCONSOLE_180215_PRACTICE_W3_
#define _READFROMCONSOLE_180215_PRACTICE_W3_

#include <string>
#include <iostream>
#include <string>

#include "../ReadData.h"
//abstract read class
class ReadFromConsole : public ReadData{
public:
    explicit ReadFromConsole(){};

    ReadFromConsole(const ReadFromConsole& readCL){};

    std::string readLine();

};



#endif