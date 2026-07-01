#include "list.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    List list; // 表示一个空的链表
    list.push_back(100);
    list.push_back(200);
    list.push_front(300);
    list.push_front(400);

    list.print(); // 400 300 100 200
    return 0;
}
