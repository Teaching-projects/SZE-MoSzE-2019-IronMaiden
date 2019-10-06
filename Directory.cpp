#include "Directory.h"

Directory::Directory(std::string name):name(name){}

Directory::~Directory()
{
    for(auto& d : dirlist){
        delete d;
    }
}

std::string Directory::getName() const
{
    return name;
}

void Directory::ls()
{
    for (auto& d : dirlist){
        std::cout<<(d->getName());
        std::cout<<std::endl;

    }
}

void Directory::mkdir(std::string name)
{
    dirlist.push_back(new Directory(name));
}

Directory *Directory::getelement(std::string name)
{
    for (auto& d : dirlist){
        if(d->getName()==name)
            return d;
    }
    return nullptr;
}

