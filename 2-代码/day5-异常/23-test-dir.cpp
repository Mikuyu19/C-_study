#include <iostream>
#include "dir.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Dir dir("./");
    // List list = dir.getAllFilenames();
    // list.print();

    List list = dir.getBitmaps(); // 获取目录下所有的bmp文件名
    list.print();
    std::string filename = list.getElem(1); // 获取链表中的第1个元素
    cout << "filename: " << filename << endl;
    return 0;
}
