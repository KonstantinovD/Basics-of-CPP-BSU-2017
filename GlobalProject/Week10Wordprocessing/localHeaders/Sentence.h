#include "Word.h"

class Sentence
{

protected:
    char* sentenceStr;
    int lenght;
    const char separator = ' ';

public:
    explicit Sentence();
    Sentence(const Sentence&);
    Sentence(char);
    //takes C-string
    Sentence(char*);
    ~Sentence();

public:

    //By default it should be an empty pointer or pointer without dynamic allocation of memory
    //In another case print "false" to use pointer with dynamic allocation of memory
    int get(char*&, bool isCStr = true);
    char get(int);

    void set(const Sentence&);
    void set(char);
    void set(char*);
    void set(char*, int size);

public:
    Sentence& operator=(const Sentence&);
    Sentence& operator+=(const Sentence&);
    bool operator==(Sentence&);
    bool operator>(Sentence&);
    bool operator<(Sentence&);
    
public:
    friend std::ostream& operator<<(std::ostream&, const Sentence&);

public:
    int getLenght();
    void clear();

public:
    //takes C-strings
    int findWord(char* Cstr, int startPos = 0);
    int findWord(int size, char* str, int startPos  = 0);
};