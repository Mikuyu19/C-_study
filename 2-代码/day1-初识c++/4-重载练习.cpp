// 练习：
// 编写算法compare, 实现整数，小数、字符串的比较
// 如果第一个参数小于第二个参数，则返回-1
// 如果第一个参数大于第二个参数，则返回1 ，
// 否则返回0
#include <iostream>
#include <string>
using namespace std;

// 整数版本的compare重载
int compare(int a, int b)
{
    if (a < b)
    {
        return -1;
    }
    else if (a > b)
    {
        return 1;
    }
    return 0;
}

// 浮点数版本的compare重载
int compare(double a, double b)
{
    if (a < b)
    {
        return -1;
    }
    else if (a > b)
    {
        return 1;
    }
    return 0;
}

// 字符串版本的compare重载
// 使用const引用避免拷贝大字符串，效率更高
int compare(const string &a, const string &b)
{
    if (a < b)
    {
        return -1;
    }
    else if (a > b)
    {
        return 1;
    }
    return 0;
}

int main()
{
    // 测试整数比较
    cout << "--- 整数比较 ---" << endl;
    cout << "比较 5 和 10: " << compare(5, 10) << endl; // 期望输出: -1
    cout << "比较 10 和 5: " << compare(10, 5) << endl; // 期望输出: 1
    cout << "比较 5 和 5: " << compare(5, 5) << endl;   // 期望输出: 0
    cout << endl;

    // 测试浮点数比较
    cout << "--- 浮点数比较 ---" << endl;
    cout << "比较 3.14 和 6.28: " << compare(3.14, 6.28) << endl; // 期望输出: -1
    cout << "比较 6.28 和 3.14: " << compare(6.28, 3.14) << endl; // 期望输出: 1
    cout << "比较 3.14 和 3.14: " << compare(3.14, 3.14) << endl; // 期望输出: 0
    cout << endl;

    // 测试字符串比较
    cout << "--- 字符串比较 ---" << endl;
    string s1 = "apple";
    string s2 = "banana";
    cout << "比较 \"apple\" 和 \"banana\": " << compare(s1, s2) << endl; // 期望输出: -1
    cout << "比较 \"banana\" 和 \"apple\": " << compare(s2, s1) << endl; // 期望输出: 1
    cout << "比较 \"apple\" 和 \"apple\": " << compare(s1, s1) << endl;  // 期望输出: 0
    cout << endl;

    return 0;
}