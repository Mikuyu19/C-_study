#include <iostream>
using namespace std;


class Base 
{
public:
    Base()
    {
        x = 0;
        y = 0;
        z = 0;
        cout << "Base()" << this << endl;
    }
    Base(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        cout << "Base(int,int,int)" << endl;
    }
    ~Base()
    {
        cout << "~Base() " << this << endl;
    }
    int x;
private:
    int y;
protected:
    int z;
};

class Derived: public Base 
{
public:
    Derived()
    {
        cout << "Derived() " << endl;
    }
    Derived(int x, int y, int z): Base(x,y,z), a(0)
    {
        cout << "Dervied(int,int,int)" << endl;
    }
     ~Derived()
    {
        cout << "~Derived() " << this << endl;
    }

    void setValue()
    {
        x = 1;
        // y = 2; // 在类的内部无法直接访问基类的私有成员
        z = 3;
    }

private:
    int a;
    Base b; // 成员对象
};


int main(int argc, char const *argv[])
{
    Derived d1;
    cout << sizeof(d1) << endl;
    cout << "&d1 = " << &d1 << endl;
    
    Derived d2(1,2,3);
    return 0;
}


// {
//     <Base> = {x = 32767, y = -7992, z = 32767}, 
//     <No data fields>
// }
