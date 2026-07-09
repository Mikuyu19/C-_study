#include <iostream>
using namespace std;

class Base
{
public:
    Base(int x = 0) : x(x) {}
    void print() const
    {
        cout << "x = " << x << endl;
    }
    void setX(int x)
    {
        this->x = x;
    }

private:
    int x;
};

class Derived : public Base
{
public:
    Derived(int x = 0, int y = 0) : Base(x), y(y) {}
    void print() const
    {
        Base::print(); // 显示调用基类的同名成员
        cout << "y = " << y << endl;
    }

private:
    int y;
};

int main(int argc, char const *argv[])
{
    Derived d1(100, 200);
    d1.print();

    Base b1 = d1; // 初始化
    b1.print();

    d1.setX(1000);

    b1 = d1; // 赋值
    b1.print();

    cout << "-------1------" << endl;
    Base *p1 = &d1;
    p1->print(); // 调用的是基类中的print函数
    Derived *q = static_cast<Derived *>(p1);
    q->print(); // 调用的是派生类中新增加的print函数

    cout << "-------2------" << endl;
    Base &r = d1;
    r.print(); // 调用的是基类中的print函数
    cout << "-------3------" << endl;
    d1.print();
    return 0;
}
