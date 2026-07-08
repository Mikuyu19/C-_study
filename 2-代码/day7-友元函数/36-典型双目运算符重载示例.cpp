#include <iostream>
using namespace std;

class Demo 
{
public:
    friend Demo operator+(Demo d1, Demo d2);
    Demo(int x=0): _x(x) {}
    void print() const 
    {
        cout << "Demo(" << this->_x << ")" << endl;
    }

    // ==号重载为非静态成员函数
    bool operator==(Demo d2) const 
    {
        if (this->_x == d2._x)
            return true;
        return false;
    }

private:
    int _x;
};

// +号运算符重载为全局函数
Demo operator+(Demo d1, Demo d2)
{
    int x = d1._x + d2._x;
    Demo d3(x);
    return d3;
}

int main(int argc, char const *argv[])
{
    Demo d1(1);
    d1.print();

    Demo d2(2);
    d2.print();

    Demo d3 = d1 + d2; // Demo operator+(Demo d1, Demo d2)
    // Demo d3 = operator+(d1, d2);
    d3.print();

    if (d1 == d2) // d1.operator==(d2)
    {
        cout << "==" << endl;
    }
    else 
    {
        cout << "!=" << endl;
    }
    return 0;
}
