#include <iostream>
using namespace std;

class Demo 
{
public:
    Demo(int x = 0): _x(x) 
    {
        cout << "构造函数" << endl;
    }
    ~Demo()
    {
        cout << "析构函数" << endl;
    }
    void print() const 
    {
        cout << "Demo(" << _x << ")" << endl;
    }
private:
    int _x;
};


void foo(int x) {}

void foo(int* p) {}

int main(int argc, char const *argv[])
{
    // Demo d1;
    // d1.print();

    Demo* p1 = new Demo(100);
    p1->print();
    delete p1;

    Demo* p2 = new Demo[5];
    delete []p2;


    // foo(NULL); // 语法错误
    foo(nullptr);
    return 0;
}
