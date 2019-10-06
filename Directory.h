#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <iostream>
#include <list>
class Directory
{
private:
    std::string name;
    std::list<Directory*>dirlist;
public:
    Directory(std::string name);
    ~Directory();
    std::string getName() const;
    void ls();
    void mkdir(std::string name);
    Directory* getelement(std::string name);
};

#endif // DIRECTORY_H
