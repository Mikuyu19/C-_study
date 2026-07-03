#ifndef POINT_H
#define POINT_H

// Point 类：表示屏幕上的一个点，保存 x 和 y 坐标。
class Point
{
public:
    // 默认构造函数：创建点时，如果没有传坐标，就默认放在 (0, 0)。
    Point();

    // 带参数构造函数：创建点时，直接指定 x 和 y 坐标。
    Point(int x, int y);

    // 单独修改 x 坐标。
    void setX(int x);

    // 单独修改 y 坐标。
    void setY(int y);

    // 同时修改 x 和 y 坐标。
    void move(int x, int y);

    // 获取 x 坐标，const 表示这个函数不会修改对象内容。
    int getX() const;

    // 获取 y 坐标，const 表示这个函数不会修改对象内容。
    int getY() const;

private:
    int _x; // 点的横坐标
    int _y; // 点的纵坐标
};

#endif
