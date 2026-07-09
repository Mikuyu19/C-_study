#ifndef STACK_HPP
#define STACK_HPP

#include "list.hpp"

class Stack
{
public:
    void push(Type x);
    void pop();
    Type top() const;
    bool empty() const;
    int size() const;

private:
    List _list;
};

using LinkStack = Stack;

#endif
