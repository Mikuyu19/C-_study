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
    List getBitmaps(); // 获取所有的bmp文件

    bool isBitmap(std::string filename) const;
private:
    std::string _path;
    DIR * _pdir;
};

#endif
