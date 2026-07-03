#include <iostream>
using namespace std;

class Demo
{
public:
    Demo(int x, int y): _x(x), _y(y) {}
    void print() const 
    {
        cout << "Demo(" << this->_x << ", " << this->_y << ")" << endl;
    }

    Demo(const Demo& rhs)
    {
        this->_x = rhs._x;
        this->_y = rhs._y;
        cout << "Demo(const Demo&)" << endl;
    }

private:
    int _x;
    int _y;
};

void foo(Demo d)
{

}

Demo foo()
{
    static Demo d(1,1);
    return d;
}

int main(int argc, char const *argv[])
{
    Demo d1(100, 200);
    d1.print();

    Demo d2(d1); // 1
    d2.print();
    cout << "-------------" << endl;
    foo(d1);    // 2
    cout << "-------------" << endl;
    foo();      // 3
    cout << "-------------" << endl;
    return 0;
}
