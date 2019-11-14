#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <iostream>
#include <list>
#include "File.h"

class Directory
{
private:
    std::string name;
    std::list<Directory*>dirlist;
    std::list<File*>filelist;
public:
    Directory(std::string name);
    ~Directory();
    std::string getName() const;
    void ls();
    void mkdir(std::string name);
    void touch(std::string name);
    Directory* getElement(std::string name);
    File* getFileElement(std::string name);
    bool rm(std::string name, bool rf=0);
};

#endif // DIRECTORY_H

