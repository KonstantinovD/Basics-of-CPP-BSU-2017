#ifndef _READDATA_180215_PRACTICE_W3_
#define _READDATA_180215_PRACTICE_W3_

#include <string>
//abstract read class
class ReadData{
public:
    virtual std::string readLine() = 0;
};



#endif