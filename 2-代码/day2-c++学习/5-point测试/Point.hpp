#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
    // 构造函数：默认坐标为 0, 0
    Point();

    // 构造函数：创建对象时直接设置 x 和 y
    Point(int x, int y);

    // 设置 x 坐标
    void setX(int x);

    // 设置 y 坐标
    void setY(int y);

    // 同时设置 x 和 y
    void setPoint(int x, int y);

    // 获取 x 坐标
    int getX() const;

    // 获取 y 坐标
    int getY() const;

    // 显示坐标
    void show() const;

private:
    int x_; // x 坐标
    int y_; // y 坐标
};

#endif