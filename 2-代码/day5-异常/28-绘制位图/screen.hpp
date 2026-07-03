#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "point.hpp"
#include "color.hpp"

// Screen 类：负责打开屏幕设备，并在屏幕上画点。
class Screen
{
public:
    // 默认构造函数：只设置一些默认参数，不打开屏幕设备。
    Screen();

    // 带参数构造函数：创建对象时直接打开指定屏幕设备。
    Screen(const char* name);

    // 初始化屏幕设备，例如 "/dev/fb0"。
    void init(const char* name);

    // 在指定坐标画一个指定颜色的点。
    void drawPoint(int x, int y, int color);

    // 用 Point 对象表示坐标，用 Color 对象表示颜色来画点。
    void drawPoint(Point pos, Color color);

private:
    const char* _name; // 屏幕设备文件名，例如 "/dev/fb0"
    int _fd;           // 打开屏幕设备后得到的文件描述符
    int* _addr;        // 显存映射后的起始地址
    int _w;            // 屏幕宽度
    int _h;            // 屏幕高度
    short _bpp;        // 色深，32 表示一个像素占 32 位
};

#endif
