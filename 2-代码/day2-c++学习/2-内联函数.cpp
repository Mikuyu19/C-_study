#include <iostream>

// inline 表示建议编译器将函数进行内联展开
inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    int ret = add(10, 20);

    std::cout << ret << std::endl;

    return 0;
}