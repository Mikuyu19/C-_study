#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }
    A(int x)
    {
        this->x = x;
        cout << "A(int)" << endl;
    }
    int x;
};
class B : public virtual A
{
public:
    B()
    {
        cout << "B()" << endl;
    }
};
class C : public virtual A
{
public:
    C()
    {
        cout << "C()" << endl;
    }
};
class D : public B, public C
{
public:
    D()
    {
        cout << "D()" << endl;
    }
    D(int x): A(x) 
    {
        cout << "D(int)" << endl;
    }
};

int main(int argc, char const *argv[])
{
    D d1;
    cout << sizeof(d1) << endl;
    D d2(200);
    return 0;
}

// 普通的菱形继承时，派生类对象的内存布局
// {
//     <B> = {<A> = {x = -7992}, <No data fields>}, 
//     <C> = {<A> = {x = 32767}, <No data fields>}, 
//     <No data fields>
// }

// 虚继承时，派生类对象的内存布局
// {
//     <B> = {<A> = {x = -134522288}, _vptr.B = 0x555555557c98 <vtable for D+24>}, 
//     <C> = {_vptr.C = 0x555555557cb0 <VTT for D>}, 
//     <No data fields>
// }