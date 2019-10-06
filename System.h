#ifndef SYSTEM_H
#define SYSTEM_H
#include <list>
#include "Directory.h"

class System
{
private:
    Directory* root;
    std::list<Directory*>RootList;
public:
    System();
    ~System();
    bool command(std::string command);
    void print();


};

#endif // SYSTEM_H
