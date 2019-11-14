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
    Directory* d=this->getElement(name);
    File* f=this->getFileElement(name);
    if(d == nullptr){
        if(f == nullptr){
            dirlist.push_back(new Directory(name));}
        else std::cout<<"mkdir: nem lehet a következő könyvtárat létrehozni: "<<name<<": A fájl már létezik"<<std::endl;}
    else std::cout<<"mkdir: nem lehet a következő könyvtárat létrehozni: "<<name<<": A könyvtár már létezik"<<std::endl;
}

void Directory::touch(std::string name)
{
    Directory* d=this->getElement(name);
    File* f=this->getFileElement(name);
    if(f == nullptr){
        if(d == nullptr){
            filelist.push_back(new File(name));}
        else std::cout<<"touch: nem lehet a következő fájlt létrehozni: "<<name<<": A könyvtár már létezik"<<std::endl;}
    else std::cout<<"touch: nem lehet a következő fájlt létrehozni: "<<name<<": A fájl már létezik"<<std::endl;
}

Directory *Directory::getElement(std::string name)
{
    for (auto& d : dirlist){
        if(d->getName()==name)
            return d;
    }
    return nullptr;
}

File *Directory::getFileElement(std::string name)
{

    for (auto& f : filelist){
        if(f->getName()==name)
            return f;
    }
    return nullptr;
}

bool Directory::rm(std::string name, bool rf)
{
    std::list<Directory*>::iterator itr;
    for (itr=dirlist.begin(); itr!=dirlist.end(); ++itr){
        if(itr.operator*()->getName()==name){
            if(rf){
                delete(itr.operator*());
                dirlist.erase(itr);
                return 0;
            }
            else if(itr.operator*()->dirlist.empty() && itr.operator*()->filelist.empty()){
                delete(itr.operator*());
                dirlist.erase(itr);
                return 0;
            }
            else{
                std::cout<<"rm: "<<name<<" nem törölhető: A könyvtár nem üres"<<std::endl;
                return 1;
            }
        }
    }
    std::list<File*>::iterator itr2;
    for (itr2=filelist.begin(); itr2!=filelist.end(); ++itr2){
        if(itr.operator*()->getName()==name){
            delete(itr2.operator*());
            filelist.erase(itr2);
            return 0;
        }
    }
    std::cout<<"rm: "<<name<<" nem törölhető: Nincs ilyen fájl vagy könyvtár"<<std::endl;
    return 1;
}
