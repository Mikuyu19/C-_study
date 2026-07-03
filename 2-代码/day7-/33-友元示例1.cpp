#include <iostream>
using namespace std;

class Demo
{
public:
    // 全局函数的友元声明
    friend void print_demo(Demo d);
    Demo(int x = 0): x(x) {}

private:
    int x;
};

void print_demo(Demo d)
{
    cout << "d.x = " << d.x << endl;
}


int main(int argc, char const *argv[])
{
    Demo d1(100);
    print_demo(d1);
    return 0;
}
