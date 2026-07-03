#ifndef BITMPA_HPP
#define BITMPA_HPP

#include <string>
#include "screen.hpp"

class Bitmap
{
public:
    // 构造函数：传入 BMP 图片路径，读取图片头信息和像素数据。
    Bitmap(std::string pathfile);

    // 析构函数：释放像素缓冲区，并关闭还没有关闭的图片文件。
    ~Bitmap();

    // 把当前位图绘制到指定屏幕对象上。
    void draw(Screen& screen);

    // 把当前位图绘制到屏幕的指定起始位置。
    void draw(Screen& screen, int x0, int y0);

private:
    std::string _pathfile; // BMP 图片文件路径。
    int _fd;               // 打开图片文件后得到的文件描述符。
    int _size;             // BMP 文件总大小，单位是字节。
    int _data_offset;      // 像素数组在 BMP 文件中的起始偏移位置。
    int _w;                // 图片宽度，单位是像素。
    int _h;                // 图片高度，单位是像素。
    int _compression;      // 压缩方式，0 表示不压缩。
    short _bpp;            // 色深：每个像素占多少位，例如 24 表示 BGR 三字节。
    char* _pix_data;       // 像素数据缓冲区，保存从 BMP 文件中读出的颜色数据。
};

#endif
