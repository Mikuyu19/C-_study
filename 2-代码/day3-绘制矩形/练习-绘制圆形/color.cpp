#include "color.hpp"

// 默认颜色：黑色。
Color::Color() : _red(0), _green(0), _blue(0)
{
    // _red = 0;
    // _green = 0;
    // _blue = 0;
}

// 创建 Color 对象时，可以直接写 Color c(255, 0, 0);
// 这里会把颜色初始化成红色。
Color::Color(int r, int g, int b) : _red(r), _green(g), _blue(b)
{
    // _red = r;
    // _green = g;
    // _blue = b;
}

void Color::setValue(int r, int g, int b)
{
    _red = r;
    _green = g;
    _blue = b;
}

void Color::setRed(int r)
{
    _red = r;
}

int Color::getRed() const
{
    return _red;
}

int Color::toInt() const
{
    // 例如 RGB(255, 193, 193) 会被合成 0xFFC1C1。
    // 红色左移 16 位，绿色左移 8 位，蓝色放在最低 8 位。
    int v = _red << 16 | _green << 8 | _blue;

    return v;
}
