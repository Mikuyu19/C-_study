#include <iostream>
using namespace std;

class Demo
{
public:
    explicit Demo(int x) : _x(x)
    {
    }
    explicit Demo(const char *s)
    {
    }
    void print() const
    {
        cout << "x = " << _x << endl;
    }

private:
    int _x;
};

int main()
{
    Demo d1(100);
    d1.print();

    Demo d2{200};
    d2.print();

    // Demo d3 = 300; //报错
    // d3.print();

    // Demo d4 = "hello"; //报错
    // d4.print();

    return 0;
}