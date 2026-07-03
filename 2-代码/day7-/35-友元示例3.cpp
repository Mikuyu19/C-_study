#include <iostream>
using namespace std;


class Demo
{
public:
    // 友元类声明
    friend class Other;
    Demo(int x = 0) : x(x) {}

private:
    int x;
};


class Other
{
public:
    void print_demo(Demo d);

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
