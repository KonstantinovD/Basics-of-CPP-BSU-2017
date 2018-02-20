#ifndef _READFROMFILE_180215_PRACTICE_W3_
#define _READFROMFILE_180215_PRACTICE_W3_

#include <string>
#include <fstream>
#include <string>

#include "../ReadData.h"
//abstract read class
class ReadFromFile: public ReadData{
private:
    std::string pathToFile;
    std::fstream FIN;
private:
    void openFile();

public:
    explicit ReadFromFile(std::string pathToFile = "");

    ReadFromFile(const ReadFromFile& readF);

    bool eof();

    bool isOpen();

    std::string readLine();

    void setFile(std::string pathToFile);
};



#endif