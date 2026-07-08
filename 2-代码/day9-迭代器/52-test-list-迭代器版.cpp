#include "list.hpp"
#include <iostream>
using namespace std;

int main()
{
    List list; // 表示一个空的链表

    list.push_back("hello");
    list.push_back("world");
    list.push_back("iterator");
    list.push_front("C++");

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        cout << *it << endl;
    }
    // for (const auto &c : list)
    // {
    //     cout << c << endl;
    // }
    return 0;
}
