#include <iostream>
#include "Point.hpp"

using namespace std;

// 默认构造函数
Point::Point()
{
    x_ = 0;
    y_ = 0;
}

// 带参数构造函数
Point::Point(int x, int y)
{
    x_ = x;
    y_ = y;
}

// 设置 x 坐标
void Point::setX(int x)
{
    x_ = x;
}

// 设置 y 坐标
void Point::setY(int y)
{
    y_ = y;
}

// 同时设置 x 和 y
void Point::setPoint(int x, int y)
{
    x_ = x;
    y_ = y;
}

// 获取 x 坐标
int Point::getX() const
{
    return x_;
}

// 获取 y 坐标
int Point::getY() const
{
    return y_;
}

// 显示坐标
void Point::show() const
{
    cout << "x = " << x_ << ", y = " << y_ << endl;
}