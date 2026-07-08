#include <iostream>
using namespace std;

class Demo
{
public:
    friend Demo &operator++(Demo &d);
    friend Demo operator++(Demo &d, int);
    Demo(int x = 0) : x(x) {}
    void print() const
    {
        cout << "Demo(" << x << ")" << endl;
    }

    // 前--重载为成员函数
    Demo &operator--()
    {
        --this->x;
        return *this;
    }

    // 后--重载为成员函数，int只是占位，用来区分前--和后--
    Demo operator--(int)
    {
        Demo tmp = *this;
        --this->x;
        return tmp;
    }

private:
    int x;
};

// 前++重载为全局函数
Demo &operator++(Demo &d)
{
    ++d.x;
    return d;
}

// 后++重载为全局函数
Demo operator++(Demo &d, int)
{
    Demo tmp = d;
    ++d.x;
    return tmp;
}

int main(int argc, char const *argv[])
{
    Demo d1(100);
    d1.print();

    cout << "前置++" << endl;
    Demo d2 = ++d1; // operator++(d1)
    d1.print(); // 101
    d2.print(); // 101

    cout << "前置--" << endl;
    --d1;       // d1.operator--()
    d1.print(); // 100

    cout << "-------------" << endl;

    cout << "后置++" << endl;
    Demo d3 = d1++; // operator++(d1, int)  
    d1.print(); // 101
    d3.print(); // 100

    cout << "后置--" << endl;
    Demo d4 = d1--; // d1.operator--(int)
    d1.print(); // 100
    d4.print(); // 101

    return 0;
}
