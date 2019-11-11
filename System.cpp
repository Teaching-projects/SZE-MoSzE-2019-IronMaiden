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
    if(arg0=="ls" && arg1==""){
        RootList.back()->ls();
    }
    else if(arg0=="mkdir" && arg1!="" && arg2==""){
        RootList.back()->mkdir(arg1);
    }
    else if(arg0=="touch" && arg1!="" && arg2=="")
        RootList.back()->touch(arg1);
    else if(arg0=="cd"){
        if (arg1==".." && arg2==""){
            if (RootList.size()==1) return 1;
            else RootList.pop_back();
        }else if(arg1!="" && arg2==""){
            Directory* dir=RootList.back()->getelement(arg1);
            if(dir!=nullptr)RootList.push_back(dir);
            else std::cout<<"bash: cd: "<<arg1<<": Nincs ilyen könyvtár"<<std::endl;
        }
    }
    else if(arg0=="rm"){
        if(arg1=="-rf" && arg2!="")
            RootList.back()->rmrf(arg2);
        else if(arg1!="" && arg2=="") RootList.back()->rm(arg1);
    }
    else{
        if((arg0=="exit" && (arg1!="" || arg2!=""))|| arg0!="exit")
            std::cout<<"\""<<command<<"\" parancs nem található."<<std::endl;
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

