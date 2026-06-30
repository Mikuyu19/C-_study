#include "point.hpp"

// 默认构造函数：没有传坐标时，把点设置到 (0, 0)。
Point::Point() : _x(0), _y(0)
{
    // _x = 0;
    // _y = 0;
}

// 创建 Point 对象时，可以直接写 Point p(100, 200);
// 这里会把 _x 初始化为 100，把 _y 初始化为 200。
Point::Point(int x, int y) : _x(x), _y(y)
{
    // _x = x;
    // _y = y;
}

void Point::setX(int x)
{
    _x = x;
}

void Point::setY(int y)
{
    _y = y;
}

void Point::move(int x, int y)
{
    _x = x;
    _y = y;
}

int Point::getX() const
{
    return _x;
}

int Point::getY() const
{
    return _y;
}
