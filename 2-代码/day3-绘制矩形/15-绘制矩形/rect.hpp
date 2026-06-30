#ifndef __RECT_HPP__
#define __RECT_HPP__

#include "point.hpp"
#include "color.hpp"
#include "screen.hpp"

// Rect 类：表示一个矩形，包含宽高、左上角位置和颜色。
class Rect
{
public:
    // 默认构造函数：创建一个宽高为 0、位置在 (0, 0)、颜色为黑色的矩形。
    Rect();

    // 只指定矩形大小，位置和颜色使用默认值。
    Rect(int w, int h);

    // 指定矩形大小、位置对象、颜色对象。
    Rect(int w, int h, const Point &pos, const Color &color);

    // 一次性指定矩形的宽高、左上角坐标和 RGB 颜色。
    Rect(int w, int h, int x, int y, int r, int g, int b);

    // 设置矩形大小。
    void resize(int w, int h);

    // 单独设置宽度。
    void setWidth(int w);

    // 单独设置高度。
    void setHeight(int h);

    // 移动矩形左上角到指定坐标。
    void move(int x, int y);

    // 移动矩形左上角到指定 Point 对象的位置。
    void move(const Point &pos);

    // 使用 RGB 三个分量设置矩形颜色。
    void setColor(int r, int g, int b);

    // 使用已有 Color 对象设置矩形颜色。
    void setColor(const Color &color);

    // 把矩形画到指定屏幕上。
    void draw(Screen &screen);

private:
    int _w;       // 矩形宽度
    int _h;       // 矩形高度
    Point _pos;   // 矩形左上角坐标
    Color _color; // 矩形颜色
};

#endif
