#include <iostream>
using namespace std;

class Demo 
{
public:
    Demo()
    {
        x = 0;
        cout << "Demo()" << endl;
    }
    Demo(int y)
    {
        x = y;
        cout << "Demo(int)" << endl;
    }
    void print() const 
    {
        cout << "x = " << x << endl;
    }
private:
    int x;
};


void foo(Demo d)
{
    d.print();
}

int main(int argc, char const *argv[])
{
    Demo d1; // Demo()
    d1.print();

    Demo d2(100); // Demo(int)
    d2.print();


    // Demo d3(); // 函数声明
    Demo d4{}; // 对象实例化

    d4.print(); // x = 0
    // d3.print(); // 语法错误


    Demo();
    Demo(200);

    foo(d2);
    foo(Demo(300));

    return 0;
}
