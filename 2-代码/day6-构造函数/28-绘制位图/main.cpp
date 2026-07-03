#include "screen.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>
#include <unistd.h>
#include "bitmap.hpp"
#include "dir.hpp"
#include "list.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // 第 1 个参数是 BMP 文件夹路径；不传时默认读取当前目录下的 bmp 文件夹。
    const char *bmp_dir = (argc >= 2) ? argv[1] : "./bmp";

    // 第 2 个参数是每张图片显示的秒数；不传时默认 1 秒。
    int delay_seconds = (argc >= 3) ? atoi(argv[2]) : 1;
    if (delay_seconds <= 0)
        delay_seconds = 1;

    Dir dir(bmp_dir);
    List bmp_list = dir.getBitmaps();

    if (bmp_list.empty())
    {
        cout << "no bmp file in " << bmp_dir << endl;
        return 1;
    }

    cout << "bmp files:" << endl;
    bmp_list.print();

    Screen screen("/dev/fb0");

    while (true)
    {
        for (int i = 1; i <= bmp_list.size(); i++)
        {
            string filename = bmp_list.getElem(i);
            cout << "show: " << filename << endl;

            Bitmap bmp(filename);
            bmp.draw(screen);
        }

        sleep(delay_seconds);
    }
}
