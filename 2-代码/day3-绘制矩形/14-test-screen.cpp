#include "screen.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Screen screen;
    screen.init("/dev/fb0");

    Point pos;
    pos.move(100, 100);
    Color color;
    color.setValue(255, 255, 0);

    screen.drawPoint(pos, color);

    return 0;
}
