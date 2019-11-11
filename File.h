#ifndef FILE_H
#define FILE_H
#include<string>

class File
{
private:
    std::string name;
    std::string content;
public:
    File(std::string name);
    ~File();
    std::string getName() const;
    void setContent(const std::string &value);
};

#endif // FILE_H
