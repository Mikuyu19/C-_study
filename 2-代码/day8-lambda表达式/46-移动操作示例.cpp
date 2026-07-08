#include <iostream>
#include <string.h>
using namespace std;


class Demo 
{
public:
    Demo(const char* s)
    {
        p = new char[strlen(s)+1];
        strcpy(p, s);
    }
    ~Demo()
    {
        delete[] p;
    }

    Demo(const Demo& rhs)
    {
        cout << "拷贝构造" << endl;
        p = new char[strlen(rhs.p)+1];
        strcpy(p, rhs.p);
    }
    Demo& operator=(const Demo& rhs)
    {
        cout << "拷贝赋值" << endl;
        if (this == &rhs)
            return *this;

        delete[]p;
        p = new char[strlen(rhs.p)+1];
        strcpy(p, rhs.p);

        return *this;
    }

    Demo(Demo&& rhs)
    {
        cout << "移动构造" << endl;
        p = rhs.p;
        rhs.p = nullptr;
    }
    Demo& operator=( Demo&& rhs)
    {
        cout << "移动赋值" << endl;
        if (this == &rhs)
            return *this;

        delete[]p;
        p = rhs.p;
        rhs.p = nullptr;
       
        return *this;
    }


    void print() const 
    {
        cout << p << endl;
    }
private:
    char* p;
};


void swap(Demo& s1, Demo& s2)
{
    Demo tmp = std::move(s1);      // 移动构造
    s1 = std::move(s2);            // 移动赋值
    s2 = std::move(tmp);           // 移动赋值
}

int main(int argc, char const *argv[])
{
    Demo d1("hello");
    d1.print();

    Demo d2("hello world");
    d2.print();

    cout << "---------------" << endl;
    swap(d1, d2); // 交换
    d1.print();
    d2.print();
    return 0;
}
