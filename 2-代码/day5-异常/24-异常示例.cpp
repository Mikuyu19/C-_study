#include <iostream>
using namespace std;

void foo(int x)
{
    if (x < 0)
        throw 1; // 抛出整型异常
        // throw "error";
    cout << "x = " << x << endl;
}

int main(int argc, char const *argv[])
{
    try
    {
        foo(-1);
        foo(1);
    }
    catch (int err)
    {
        cout << "捕获int类型的异常：" << err << endl;
        return 1;
    }
    catch (double err)
    {
        cout << "捕获double类型的异常：" << err << endl;
        return 1;
    }

    return 0;
}
