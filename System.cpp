#include "System.h"
#include <sstream>

System::System()
{
    root = new Directory("root");
    RootList.push_back(root);
}

System::~System()
{
    delete root;
}

bool System::command(std::string command)
{
    std::string arg0, arg1, arg2;
    std::istringstream line(command);
    line>>arg0; line>>arg1; line>>arg2;
    if(arg0=="ls" && arg1.empty()){
        RootList.back()->ls();
    }
    else if(arg0=="mkdir" && !arg1.empty() && arg2.empty()){
        RootList.back()->mkdir(arg1);
    }
    else if(arg0=="touch" && !arg1.empty() && arg2.empty())
        RootList.back()->touch(arg1);
    else if(arg0=="cd" && !arg1.empty()){
        if (arg1==".." && arg2.empty()){
            if (RootList.size()==1) return 1;
            else RootList.pop_back();
        }else if(!arg1.empty() && arg2.empty()){
            Directory* dir=RootList.back()->getElement(arg1);
            if(dir!=nullptr)RootList.push_back(dir);
            else std::cout<<"bash: cd: "<<arg1<<": Nincs ilyen könyvtár"<<std::endl;
        }
    }
    else if(arg0=="rm" && !arg1.empty()){
        if(arg1=="-rf" && !arg2.empty())
            RootList.back()->rm(arg2,1);
        else if(!arg1.empty() && arg2.empty()) RootList.back()->rm(arg1);
    }
    else{
        if((arg0=="exit" && !arg1.empty()) || arg0!="exit")
            std::cout<<"\""<<command<<"\" parancs nem található, vagy hibásak a paraméterek"<<std::endl;
        return 1;
    }
    return 0;
}

void System::print()
{
    std::string user="root@notebook:";
    if(RootList.size()==1)std::cout<<user<<"~#";
    else{
        std::string track="";
        for(auto& r : RootList){
            if(r->getName()!="root")track+="/"+r->getName();
        }
        std::cout<<user<<track<<"# ";
    }

}

