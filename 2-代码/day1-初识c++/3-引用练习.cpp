// 编写算法swap，实现交换两个整型变量的值
// 要求使用指针和引用 分别实现。
// int a = 1;
// int b = 2;
// swap(&a, &b);
// swap(a, b);

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1;
    int b = 2;
    swap(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}