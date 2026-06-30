#include "screen.hpp"
#include <iostream>
#include "circle.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    // 创建 Screen 对象时直接传入设备名，会自动打开屏幕。
    Screen screen("/dev/fb0");

    // 创建一个圆：
    // 圆心坐标是 (512, 300)，半径是 120，颜色是 RGB(255, 193, 193)。
    Circle c1(512, 300, 120, 255, 193, 193);
    c1.draw(screen);

    return 0;
}
