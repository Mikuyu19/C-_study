#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"
#include "color.hpp"
#include "screen.hpp"

// Circle 类：表示一个圆，包含圆心、半径和颜色。
class Circle
{
public:
    // 默认构造函数：圆心在 (0, 0)，半径为 0，颜色为黑色。
    Circle();

    // 创建圆时直接指定圆心坐标、半径和 RGB 颜色。
    Circle(int x, int y, int radius, int r, int g, int b);

    // 创建圆时使用已有的 Point 和 Color 对象。
    Circle(const Point &center, int radius, const Color &color);

    // 设置圆心坐标。
    void move(int x, int y);

    // 使用已有 Point 对象设置圆心。
    void move(const Point &center);

    // 设置半径。
    void setRadius(int radius);

    // 使用 RGB 三个分量设置颜色。
    void setColor(int r, int g, int b);

    // 使用已有 Color 对象设置颜色。
    void setColor(const Color &color);

    // 把圆画到屏幕上。
    void draw(Screen &screen);

private:
    Point _center; // 圆心坐标
    int _radius;   // 圆的半径
    Color _color;  // 圆的颜色
};

#endif
