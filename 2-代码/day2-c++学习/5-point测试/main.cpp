#include <iostream>
#include "Point.hpp"

using namespace std;

int main()
{
    // 创建一个默认坐标对象
    Point p1;

    p1.show();

    // 分别设置 x 和 y
    p1.setX(100);
    p1.setY(200);

    cout << "x = " << p1.getX() << endl;
    cout << "y = " << p1.getY() << endl;

    // 同时设置 x 和 y
    p1.setPoint(300, 400);
    p1.show();

    // 创建对象时直接设置坐标
    Point p2(10, 20);
    p2.show();

    return 0;
}