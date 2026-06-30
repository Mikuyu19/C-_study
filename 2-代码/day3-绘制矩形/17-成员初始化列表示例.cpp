#include <iostream>
using namespace std;


class Other
{
public:
    Other(int x) // 自定义构造函数，编译器就不会再生成默认构造函数
    {

    }
};

class Demo 
{
public:
    Demo(int x, int y): _y(y), _r(_x), _oth(100)
    {
        _x = x;
        // _y = y;
        // _r = _x;
    }
private:
    int _x;
    const int _y; // 成员是常量
    int& _r;      // 成员是引用
    Other _oth;   // 成员对象没有默认构造函数
};

int main(int argc, char const *argv[])
{
    Demo d1(1,2);
    return 0;
}
