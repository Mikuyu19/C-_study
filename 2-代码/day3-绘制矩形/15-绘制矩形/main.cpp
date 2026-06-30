#include "screen.hpp"
#include <iostream>
#include "rect.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    // 创建 Screen 对象时直接传入设备名，会自动调用构造函数打开屏幕。
    Screen screen("/dev/fb0");

    // 也可以用构造函数直接创建点和颜色：
    // Point pos(100, 100);
    // Color color(255, 255, 0);
    // screen.drawPoint(pos, color);

    // 创建矩形时，直接指定：
    // 宽 400、高 200、左上角坐标 (312, 200)、颜色 RGB(255, 193, 193)。
    Rect r1(400, 200, 312, 200, 255, 193, 193);
    r1.draw(screen);

    return 0;
}
