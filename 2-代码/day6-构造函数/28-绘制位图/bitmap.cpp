#include "bitmap.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>
#include <iostream>
using namespace std;

Bitmap::Bitmap(std::string pathfile) : _pathfile(pathfile), _fd(-1), _size(0), _data_offset(0), _w(0), _h(0), _compression(0), _bpp(0), _pix_data(0)
{
    // 打开 BMP 图片文件
    _fd = open(pathfile.c_str(), O_RDONLY);
    if (_fd == -1)
        throw std::runtime_error("open bmp error");

    // 读取文件开头的两个字节，BMP 文件必须以字符 'B'、'M' 开头。
    char bm[2] = {0};
    read(_fd, bm, 2);
    if (bm[0] != 'B' or bm[1] != 'M')
    {
        close(_fd);
        _fd = -1;
        throw std::logic_error("this is not a bitmap!");
    }

    read(_fd, &_size, 4);

    lseek(_fd, 0x0A, SEEK_SET);
    read(_fd, &_data_offset, 4);

    lseek(_fd, 0x12, SEEK_SET);
    read(_fd, &_w, 4);
    read(_fd, &_h, 4);

    lseek(_fd, 0x1E, SEEK_SET);
    read(_fd, &_compression, 4);
    if (_compression != 0)
    {
        close(_fd);
        _fd = -1;
        throw std::logic_error("only support uncompressed bitmap!");
    }

    // 0x1C 位置保存色深，常见 BMP 图片为 24 位或 32 位。
    lseek(_fd, 0x1C, SEEK_SET);
    read(_fd, &_bpp, 2);
    cout << this->_size << ", " << this->_w << ", " << this->_h << ", " << this->_bpp << endl;

    if (_bpp != 24 and _bpp != 32)
    {
        close(_fd);
        _fd = -1;
        throw std::logic_error("only support 24-bit or 32-bit bitmap!");
    }

	// 不为负数
    int width = _w > 0 ? _w : -_w;
    int height = _h > 0 ? _h : -_h;
    int bytes_per_pixel = _bpp / 8;
    int line_bytes = width * bytes_per_pixel;
    int pad_bytes = (line_bytes % 4 == 0) ? 0 : (4 - line_bytes % 4);
    int total_bytes = (line_bytes + pad_bytes) * height;

    // 跳到像素数组起始位置，把所有像素数据一次性读到内存。
    _pix_data = new char[total_bytes];
    lseek(_fd, _data_offset, SEEK_SET);
    read(_fd, _pix_data, total_bytes);

    // 图片内容已经读入内存，文件描述符可以先关闭。
    close(_fd);
    _fd = -1;
}

Bitmap::~Bitmap()
{
    delete[] _pix_data;
    _pix_data = 0;

    if (_fd != -1)
    {
        close(_fd);
        _fd = -1;
    }
}

void Bitmap::draw(Screen &screen)
{
    draw(screen, 0, 0);
}

void Bitmap::draw(Screen &screen, int x0, int y0)
{
    // BMP 的像素存储顺序通常是 B、G、R，所以读取时先读蓝色，再读绿色，最后读红色。
    unsigned char r, g, b;
    unsigned char *p = (unsigned char *)_pix_data;

    int width = _w > 0 ? _w : -_w;
    int height = _h > 0 ? _h : -_h;
    int bytes_per_pixel = _bpp / 8;
    int line_bytes = width * bytes_per_pixel;

    // BMP 每一行的字节数必须是 4 的倍数，不足的地方会用无效字节补齐。
    int pad_bytes = (line_bytes % 4 == 0) ? 0 : (4 - line_bytes % 4);

    // _w > 0 表示每行从左往右保存，_w < 0 表示每行从右往左保存。
    // _h > 0 表示整张图从下往上保存，_h < 0 表示整张图从上往下保存。
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            b = *p++;
            g = *p++;
            r = *p++;

            if (_bpp == 32)
                p++;

            int x = _w > 0 ? j : width - 1 - j;
            int y = _h > 0 ? height - 1 - i : i;
            screen.drawPoint(x + x0, y + y0, Color(r, g, b).toInt());
        }

        // 跳过每行末尾用于 4 字节对齐的补齐字节。
        p += pad_bytes;
    }
}
