#include "stack.hpp"
#include <iostream>
using namespace std;

int main()
{
    LinkStack s1;
    s1.push("hello");
    s1.push("cpp");
    s1.push("world");
    s1.push("!!!");

    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }

    return 0;
}
