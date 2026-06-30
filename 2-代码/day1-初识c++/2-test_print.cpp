// 练习：给定一个字符串，输出其中的数字
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "请输入一个字符串：" << endl;
    cin >> str;
    for (char c : str)
    {
        if (isdigit(c))
        {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}