#include <iostream>
using namespace std;

class Base 
{
public:
    void setX(int x)
    {
        this->x = x;
        cout << "Base::setX()" << endl;
    }
    int getX() const 
    {
        return x;
    }
protected:
    int x;
};

class Derived: public Base 
{
public:
    void setX(int x)
    {
        this->x = x;
        cout << "Derived::setX()" << endl;
    }
    int getX() const 
    {
        return x;
    }
protected:
    int x;
};

int main(int argc, char const *argv[])
{
    Derived d1;
    d1.setX(100);
    cout << d1.getX() << endl;
    cout << d1.Base::getX() << endl;
    return 0;
}
