#include <iostream>
#include <string>
#include "System.h"

int main()
{
    bool exit=false;
    System sys;
    while(!exit){
        std::string command="";
        sys.print();
        getline(std::cin, command);
        if(command=="exit") exit=true;
        sys.command(command);
    }
    return 0;
}
