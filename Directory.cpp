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
    Directory* d=this->getelement(name);
    if(d == nullptr)
        dirlist.push_back(new Directory(name));
    else std::cout<<"mkdir: nem lehet a következő könyvtárat létrehozni: "<<name<<": A fájl már létezik"<<std::endl;
}

Directory *Directory::getelement(std::string name)
{
    for (auto& d : dirlist){
        if(d->getName()==name)
            return d;
    }
    return nullptr;
}

void Directory::rm(std::string name)
{
    Directory* d=this->getelement(name);
    if(d != nullptr){
       if(d->dirlist.size()==0){
        delete d;
        dirlist.remove(d);
        }else std::cout<<"rm: "<<name<<" nem törölhető: A könyvtár nem üres"<<std::endl;
    }else std::cout<<"rm: "<<name<<" nem törölhető: Nincs ilyen fájl vagy könyvtár"<<std::endl;
}

