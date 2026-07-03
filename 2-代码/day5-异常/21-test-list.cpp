#include "list.hpp"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    // List list; // 表示一个空的链表
    // list.push_back(100);
    // list.push_back(200);
    // list.push_front(300);
    // list.push_front(400);

    // list.print(); // 400 300 100 200


    List l2;
    l2.push_back("hello");
    l2.push_back("cpp");
    l2.push_back("world");
    l2.push_back("!!!");
    l2.print();

    for (int i = 1; i <= l2.size(); i++)
    {
        cout << l2.getElem(i) << ' ';
    }
    cout << endl;

    return 0;
}


