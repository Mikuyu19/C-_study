#include <iostream>
using namespace std;

// 类的前置声明
class Demo;
class Other;

class Other
{
public:
    void print_demo(Demo d);
};

class Demo
{
public:
    // 其他类成员函数的友元声明
    friend void Other::print_demo(Demo d);
    Demo(int x = 0) : x(x) {}

private:
    int x;
};

void Other::print_demo(Demo d)
{
    cout << "d.x = " << d.x << endl;
}

int main(int argc, char const *argv[])
{
    Demo d1(100);

    Other o1;
    o1.print_demo(d1);
    return 0;
}
