#include "File.h"

File::File(std::string name):name(name){}

File::~File(){}

std::string File::getName() const
{
    return name;
}