#include <iostream>

class Demo
{
public:
    void setX(int x)
    {
        _x = x;
    }
    int getX() const
    {
        return _x;
    }

private:
    int _x;
};

int main()
{
    Demo d;
    d.setX(100);
    std::cout << d.getX() << std::endl;
}