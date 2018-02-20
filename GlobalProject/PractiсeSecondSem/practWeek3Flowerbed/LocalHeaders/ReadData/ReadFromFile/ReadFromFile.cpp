#include "ReadFromFile.h"

void ReadFromFile::openFile(){
    if (FIN.is_open()) FIN.close(); //in case file we want to open is already opened
    if (pathToFile != ""){//or in case file we want to poen isn't exist and FIN will be connected with the previous file
        FIN.open(pathToFile);
    }
}

ReadFromFile::ReadFromFile(std::string pathToFile){
    this->pathToFile = pathToFile;
    openFile();
}

ReadFromFile::ReadFromFile(const ReadFromFile& readF){
    this->pathToFile = readF.pathToFile;
    openFile();
}

bool ReadFromFile::eof(){//returns true in case eof is reached or file isn't opened
    if (!FIN.is_open() || FIN.eof()) return true;
    return false;
}

bool ReadFromFile::isOpen(){
    return FIN.is_open();
}

std::string ReadFromFile::readLine(){
    std::string str = "";
    if (FIN.is_open()){//in case file not exist and, as a result, FIN isn't opened
        std::getline(FIN, str);
    }
    return str;
}

void ReadFromFile::setFile(std::string pathToFile){
    this->pathToFile = pathToFile;
    openFile();
}