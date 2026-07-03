#include "circle.hpp"

Circle::Circle()
{
    _center.move(0, 0);
    _radius = 0;
    _color.setValue(0, 0, 0);
}

Circle::Circle(int x, int y, int radius, int r, int g, int b)
{
    _center.move(x, y);
    _radius = radius;
    _color.setValue(r, g, b);
}

Circle::Circle(const Point &center, int radius, const Color &color)
{
    _center = center;
    _radius = radius;
    _color = color;
}

void Circle::move(int x, int y)
{
    _center.move(x, y);
}

void Circle::move(const Point &center)
{
    _center = center;
}

void Circle::setRadius(int radius)
{
    _radius = radius;
}

void Circle::setColor(int r, int g, int b)
{
    _color.setValue(r, g, b);
}

void Circle::setColor(const Color &color)
{
    _color = color;
}

void Circle::draw(Screen &screen)
{
    int center_x = _center.getX();
    int center_y = _center.getY();

    // 遍历圆外接正方形里的每一个点。
    for (int y = -_radius; y <= _radius; y++)
    {
        for (int x = -_radius; x <= _radius; x++)
        {
            // 圆的公式：x * x + y * y <= r * r。
            // 满足这个条件的点在圆里面，把它画出来就是实心圆。
            if (x * x + y * y <= _radius * _radius)
            {
                screen.drawPoint(center_x + x, center_y + y, _color.toInt());
            }
        }
    }
}
