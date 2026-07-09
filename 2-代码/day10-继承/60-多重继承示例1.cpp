#include <iostream>
using namespace std;

class Base1
{
public:
    void print() const
    {
        cout << "Base1.x = " << x << endl;
    }

private:
    int x;
};

class Base2
{
public:
    void print() const
    {
        cout << "Base2.x = " << x << endl;
    }

private:
    int x;
};

class Derived : public Base1, public Base2
{
};

int main(int argc, char const *argv[])
{
    Derived d1;
    cout << sizeof(d1) << endl;
    d1.Base1::print();
    d1.Base2::print();
    return 0;
}
