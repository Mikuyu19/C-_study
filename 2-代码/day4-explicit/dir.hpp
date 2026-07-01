#ifndef DIR_HPP
#define DIR_HPP

#include <dirent.h>
#include <string>
#include "list.hpp"

class Dir
{
public:
    Dir(std::string path);
    ~Dir();
    List getAllFilenames();
private:
    std::string _path;
    DIR * _pdir;
};

#endif