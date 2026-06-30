#include "rect.hpp"

// 默认构造函数：创建一个空矩形。
// _pos 和 _color 会自动调用它们自己的默认构造函数。
Rect::Rect() : _w(0), _h(0)
{
    // _w = 0;
    // _h = 0;
}

// 只初始化宽和高，位置、颜色仍然使用默认值。
Rect::Rect(int w, int h) : _w(w), _h(h)
{
    // _w = w;
    // _h = h;
}

// 用已有的 Point 对象和 Color 对象初始化矩形。
// const 引用可以避免复制对象，也保证函数内部不会修改传进来的对象。
Rect::Rect(int w, int h, const Point &pos, const Color &color) : _w(w), _h(h), _pos(pos), _color(color)
{
    // _w = w;
    // _h = h;
    // _pos = pos;
    // _color = color;
}

// 直接把宽、高、坐标、颜色都传进来。
Rect::Rect(int w, int h, int x, int y, int r, int g, int b) : _w(w), _h(h), _pos(x, y), _color(r, g, b)
{
    // _w = w;
    // _h = h;
    // _pos.move(x, y);
    // _color.setValue(r, g, b);
}

void Rect::resize(int w, int h)
{
    _w = w;
    _h = h;
}

void Rect::setWidth(int w)
{
    _w = w;
}

void Rect::setHeight(int h)
{
    _h = h;
}

void Rect::move(int x, int y)
{
    _pos.move(x, y);
}

void Rect::move(const Point &pos)
{
    _pos = pos;
}

void Rect::setColor(int r, int g, int b)
{
    _color.setValue(r, g, b);
}

void Rect::setColor(const Color &color)
{
    _color = color;
}

void Rect::draw(Screen &screen)
{
    // 先拿到矩形左上角的绝对坐标。
    int start_x = _pos.getX();
    int start_y = _pos.getY();

    // 双重循环画满整个矩形：
    // 外层 i 控制行，也就是 y 方向；
    // 内层 j 控制列，也就是 x 方向。
    for (int i = 0; i < _h; i++)
    {
        for (int j = 0; j < _w; j++)
        {
            // 当前像素坐标 = 左上角坐标 + 当前偏移量。
            screen.drawPoint(start_x + j, start_y + i, _color.toInt());
        }
    }
}
