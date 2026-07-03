#include "list.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

List::List() : _head(nullptr), _tail(nullptr), _size(0) {}

List::List(const List& other) : _head(nullptr), _tail(nullptr), _size(0)
{
    Node *p = other._head;
    while (p != nullptr)
    {
        push_back(p->_data);
        p = p->_next;
    }
}

List& List::operator=(const List& other)
{
    if (this == &other)
        return *this;

    while (!empty())
    {
        pop_front();
    }

    Node *p = other._head;
    while (p != nullptr)
    {
        push_back(p->_data);
        p = p->_next;
    }

    return *this;
}

List::~List()
{
    while (!empty())
    {
        pop_front();
    }
}

void List::push_back(Type x)
{
    // 创建一个新的结点
    Node *p = new Node(x);

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
    // 创建一个新的结点
    Node *p = new Node(x);

    // 把新结点插入到链表中
    if (_size == 0)
    {
        _head = p;
        _tail = p;
    }
    else
    {
        p->_next = _head;
        _head->_prev = p;
        _head = p;
    }
    ++_size;
}
void List::pop_back()
{
    // 删除最后一个结点
    if (_size == 0)
    {
        return;
    }
    Node *p = _tail;
    _tail = p->_prev;
    delete p;
    --_size;
    if (_size == 0)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        _tail->_next = nullptr;
    }
}
void List::pop_front()
{
    // 删除第一个结点
    if (_size == 0)
    {
        return;
    }
    Node *p = _head;
    _head = p->_next;
    delete p;
    --_size;
    if (_size == 0)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        _head->_prev = nullptr;
    }
}
Type List::back() const
{
    // 返回最后一个结点
    if (_size == 0)
    {
        return Type();
    }
    return _tail->_data;
}
Type List::front() const
{
    // 返回第一个结点
    if (_size == 0)
    {
        return Type();
    }
    return _head->_data;
}
int List::size() const
{
    // 返回链表的长度
    return _size;
}
bool List::empty() const
{
    // 判断链表是否为空
    return _size == 0;
}
void List::print() const
{
    // 打印链表
    Node *p = _head;
    while (p != nullptr)
    {
        cout << p->_data << endl;
        p = p->_next;
    }
    cout << endl;
}

Type List::getElem(int n) const
{
    if (n < 1 or n > _size)
        throw std::out_of_range("n out of range!");

    Node *p = _head;
    for (int i = 1; i < n; i++)
    {
        p = p->_next;
    }

    return p->_data;
}

List::Node::Node(Type data) : _data(data), _next(nullptr), _prev(nullptr) {}
