#include <iostream>
#include <string>
#include <cmath>

// 比较整数
int compare(int a, int b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

// 比较小数
int compare(double a, double b)
{
    const double EPS = 1e-6;

    if (a - b < -EPS)
        return -1;
    if (a - b > EPS)
        return 1;
    return 0;
}

// 比较字符串
int compare(const std::string &a, const std::string &b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

// 查找整数数组
int find(const int arr[], int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// 查找浮点数数组
int find(const float arr[], int len, float target)
{
    const float EPS = 1e-6f;

    for (int i = 0; i < len; i++)
    {
        if (std::fabs(arr[i] - target) < EPS)
            return i;
    }

    return -1;
}

// 查找字符串数组
int find(const std::string arr[], int len, const std::string &target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

int main()
{
    int num = 255;
    std::cout << compare(10, 20) << std::endl;
    std::cout << compare(3.14, 3.14) << std::endl;
    std::cout << compare(std::string("abc"), std::string("abd")) << std::endl;

    int nums[] = {10, 20, 30, 40};
    float scores[] = {1.1f, 2.2f, 3.3f};
    std::string names[] = {"Tom", "Jack", "Lucy"};

    std::cout << find(nums, 4, 30) << std::endl;
    std::cout << find(scores, 3, 2.2f) << std::endl;
    std::cout << find(names, 3, "Jack") << std::endl;

    std::cout << std::showbase << std::hex << num << std::endl;
    return 0;
}