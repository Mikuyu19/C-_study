#include <iostream>
using namespace std;


class Base 
{
public:
    int x;
private:
    int y;
protected:
    int z;
};

class Derived: private Base 
{
public:
    void setValue()
    {
        x = 1;
        // y = 2; // 在类的内部无法直接访问基类的私有成员
        z = 3;
    }

};

class Derived2: public Derived
{
public:
    void test()
    {
        // x = 10; // error
        // y = 20; // error
        // z = 30; // error
    }
};


int main(int argc, char const *argv[])
{
    Derived d1;
    cout << sizeof(d1) << endl;
    // d1.x = 1;   // 私有继承下，类外不能直接访问基类的公有成员
    // d1.y = 2;   // 类外无法直接访问基类的私有成员
    // d1.z = 3;   // 类外无法直接访问基类的保护成员
    return 0;
}


// {
//     <Base> = {x = 32767, y = -7992, z = 32767}, 
//     <No data fields>
// }
