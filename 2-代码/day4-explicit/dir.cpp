#include "dir.hpp"
#include <stdio.h>
#include <stdlib.h>

Dir::Dir(std::string path) : _path(path)
{
    _pdir = opendir(_path.c_str());
    if (_pdir == nullptr)
    {
        perror("opendir error");
        exit(1);
    }
    printf("open dir ok!\n");
}

Dir::~Dir()
{
    closedir(_pdir);
}

List Dir::getAllFilenames()
{
    List list;

    while (1)
    {
        struct dirent *p = readdir(_pdir);
        if (p == nullptr)
            break;
        std::string pathfile = _path + p->d_name;
        list.push_back(pathfile);
    }

    return list;
}
