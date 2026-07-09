#include "list.hpp"
#include <iostream>
using namespace std;


class LinkStack: private List // !!私有继承
{
public:
    void push(std::string s)
    {
        push_back(s);
    }
    void pop()
    {
        pop_back();
    }
    std::string top() const 
    {
        return back();
    }
    bool empty() const 
    {
        return List::empty();
    }

};


int main(int argc, char const *argv[])
{
    LinkStack s;
    s.push("a");
    s.push("b");
    s.push("c");
    s.push("d");

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
