#include "Directory.h"

Directory::Directory(std::string name):name(name){}

Directory::~Directory()
{
    for(auto& d : dirlist){
        delete d;
    }
    for(auto& f : filelist){
        delete f;
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
    for (auto& f : filelist){
        std::cout<<(f->getName());
        std::cout<<std::endl;

    }
}

void Directory::mkdir(std::string name)
{
    Directory* d=this->getelement(name);
    File* f=this->getfileelement(name);
    if(d == nullptr){
        if(f == nullptr){
            dirlist.push_back(new Directory(name));}
    else std::cout<<"mkdir: nem lehet a következő könyvtárat létrehozni: "<<name<<": A fájl már létezik"<<std::endl;
    }
    else std::cout<<"mkdir: nem lehet a következő könyvtárat létrehozni: "<<name<<": A könyvtár már létezik"<<std::endl;
}

bool Directory::touch(std::string name)
{
    Directory* d=this->getelement(name);
    File* f=this->getfileelement(name);
    if(f == nullptr){
        if(d == nullptr){
        filelist.push_back(new File(name));}
        else{ std::cout<<"touch: nem lehet a következő fájlt létrehozni \""<<name<<"\" A könyvtár már létezik"<<std::endl;
            return 1;}}
    else{ std::cout<<"touch: nem lehet a következő fájlt létrehozni \""<<name<<"\" A fájl már létezik"<<std::endl;
        return 1;}
    return 0;
}

void Directory::echo(std::string name, std::string conntent)
{
    File* f=this->getfileelement(name);
    if(f != nullptr){
        f->setContent(conntent);
    }else if(!this->touch(name))
        this->getfileelement(name)->setContent(conntent);
}

Directory *Directory::getelement(std::string name)
{
    for (auto& d : dirlist){
        if(d->getName()==name)
            return d;
    }
    return nullptr;
}

File *Directory::getfileelement(std::string name)
{

    for (auto& d : filelist){
        if(d->getName()==name)
            return d;
    }
    return nullptr;
}

void Directory::rm(std::string name)
{
    Directory* d=this->getelement(name);
    if(d != nullptr){
       if(d->dirlist.size()==0 && d->filelist.size()==0){
        delete d;
        dirlist.remove(d);
        }else std::cout<<"rm: "<<name<<" nem törölhető: A könyvtár nem üres"<<std::endl;
    }else{
        File* f=this->getfileelement(name);
        if(f != nullptr){
            delete f;
            filelist.remove(f);}
        else
        std::cout<<"rm: "<<name<<" nem törölhető: Nincs ilyen fájl vagy könyvtár"<<std::endl;}
}

void Directory::rmrf(std::string name)
{
    Directory* d=this->getelement(name);
    if(d != nullptr){ delete d;
        dirlist.remove(d);}else std::cout<<"rm -rf: "<<name<<" nem törölhető: Nincs ilyen könyvtár"<<std::endl;
}

