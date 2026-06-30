#include "screen.hpp"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

// 默认构造函数：
// 这里只给成员变量设置安全的初始值，不真正打开屏幕。
// 如果用这种方式创建对象，后面还需要手动调用 init("/dev/fb0")。
Screen::Screen() : _name(0), _fd(-1), _addr(0), _w(1024), _h(600), _bpp(32)
{
    // _name = 0;
    // _fd = -1;
    // _addr = 0;
    // _w = 1024;
    // _h = 600;
    // _bpp = 32;
}

// 带参数构造函数：
// 创建 Screen 对象时直接调用 init，打开屏幕并映射显存。
Screen::Screen(const char *name) : _name(name), _fd(-1), _addr(0), _w(1024), _h(600), _bpp(32)
{
    // _name = 0;
    // _fd = -1;
    // _addr = 0;
    // _w = 1024;
    // _h = 600;
    // _bpp = 32;

    init(name);
}

void Screen::init(const char *name)
{
    _name = name;
    _w = 1024;
    _h = 600;
    _bpp = 32;

    // 打开屏幕设备文件。
    _fd = open(_name, O_RDWR);
    if (_fd == -1)
    {
        perror("open fb0 error");
        exit(1);
    }

    // 把屏幕显存映射到程序地址空间。
    // 映射成功后，就可以通过 _addr 写像素。
    _addr = (int *)mmap(NULL, _w * _h * _bpp / 8, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
    if (_addr == MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    printf("screen init success!\n");
}

void Screen::drawPoint(int x, int y, int color)
{
    // 判断坐标是否在屏幕范围内，防止写到无效位置。
    if (x >= 0 and x < _w and y >= 0 and y < _h)
    {
        // 一维显存地址计算公式：第 y 行第 x 列 = _addr + _w * y + x。
        *(_addr + _w * y + x) = color;
    }
}

void Screen::drawPoint(Point pos, Color color)
{
    // 复用上面的 drawPoint(int, int, int)，避免重复写画点逻辑。
    drawPoint(pos.getX(), pos.getY(), color.toInt());
}
