#include <iostream>
using namespace std;

int main()
{
    const int a = 100;
    const int *p = &a;
    int *q = const_cast<int *>(p);

    *q = 200; // 未定义行为

    cout << "a = " << a << endl;
    cout << "*q = " << *q << endl;

    return 0;
}