#include "dir.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <cctype>

Dir::Dir(std::string path):_path(path)
{
    if (!_path.empty() and _path[_path.size() - 1] != '/')
        _path += "/";

    _pdir = opendir(_path.c_str());
    if (_pdir == nullptr)
        throw std::runtime_error("open dir error");

    printf("open dir ok!\n");
}

Dir::~Dir()
{
    closedir(_pdir);
}

List Dir::getAllFilenames()
{
    List list;

    rewinddir(_pdir);
    while (1)
    {
        struct dirent* p = readdir(_pdir);
        if (p == nullptr)
            break;
        std::string pathfile = _path + p->d_name;
        list.push_back(pathfile);
    }

    return list;
}

List Dir::getBitmaps()
{
    List list;

    rewinddir(_pdir);
    while (1)
    {
        struct dirent* p = readdir(_pdir);
        if (p == nullptr)
            break;
        std::string filename = p->d_name;
        if (isBitmap(filename))
            list.push_back(_path + filename);
    }

    return list;
}

bool Dir::isBitmap(std::string filename) const
{
    if (filename.size() < 4)
        return false;

    std::string ext = filename.substr(filename.size() - 4);
    for (int i = 0; i < 4; i++)
    {
        ext[i] = std::tolower(ext[i]);
    }

    return ext == ".bmp";
}
