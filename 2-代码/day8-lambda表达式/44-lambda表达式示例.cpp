#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 1;
    int y = 2;

    // 定义匿名函数，捕获局部变量的值，无参数，不返回，原地调用
    [=]() -> void
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }();

    // 定义匿名函数，捕获局部变量的引用，一个参数，不返回，原地调用，调用时传参
    [&](int z)
    {
        x += z;
        y += z;
    }(100);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;


    auto print = []{
        cout << "hello lambda!" << endl;
    };

    print();

    return 0;
}
