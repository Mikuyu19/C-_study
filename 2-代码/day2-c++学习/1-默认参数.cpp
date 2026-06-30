#include <iostream>

void print(int count = 1)
{
    std::cout << count << std::endl;
}

int main()
{
    print(10); // 输出 10，使用传入的参数
    print();   // 输出 1，使用默认参数

    return 0;
}