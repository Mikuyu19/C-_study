#include "stack.hpp"

void Stack::push(Type x)
{
    _list.push_back(x);
}

void Stack::pop()
{
    _list.pop_back();
}

Type Stack::top() const
{
    return _list.back();
}

bool Stack::empty() const
{
    return _list.empty();
}

int Stack::size() const
{
    return _list.size();
}
