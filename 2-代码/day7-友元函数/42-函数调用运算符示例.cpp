#include <iostream>
using namespace std;


class Demo
{
public:
    void operator()()
    {
        cout << "hello operator()" << endl;
    }
    void operator()(int x)
    {
        cout << "x = " << x  << endl;
    }
};

int main(int argc, char const *argv[])
{
    Demo d1;
    d1();
    d1(100);
    return 0;
}
