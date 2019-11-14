#ifndef FILE_H
#define FILE_H
#include<string>

class File
{
private:
    std::string name;
public:
    File(std::string name);
    ~File();
    std::string getName() const;
};

#endif // FILE_H
