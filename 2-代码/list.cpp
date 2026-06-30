#include "list.hpp"
#include <iostream>
using namespace std;

List::List(): _head(nullptr), _tail(nullptr), _size(0) {}

List::~List()
{
}

void List::push_back(Type x)
{
    // 创建一个新的结点
    Node* p = new Node(x);

    // 把新结点插入到链表中
    if (_size == 0)
    {
        _head = p;
        _tail = p;
    }
    else 
    {
        p->_prev = _tail;
        _tail->_next = p;
        _tail = p;
    }

    ++_size;
}
void List::push_front(Type x)
{
}
void List::pop_back()
{
}
void List::pop_front()
{
}
Type List::back() const
{
}
Type List::front() const
{
}
int List::size() const
{
    return _size;
}
bool List::empty() const
{
    return _size == 0;
}
void List::print() const
{
    Node* p = _head;
    while (p != nullptr)
    {
        cout << p->_data << endl;
        p = p->_next;
    }
    cout << endl;
}

List::Node::Node(Type data): _data(data), _next(nullptr), _prev(nullptr) {}
