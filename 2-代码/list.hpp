#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <stdexcept>
using Type = std::string;

class List
{
private:
    struct Node;

public:
    class iterator
    {
    public:
        iterator();
        Type &operator*();
        iterator &operator++();
        bool operator!=(const iterator &rhs) const;

    private:
        friend class List;
        Node *_p;
        iterator(Node *p);
    };

    List();
    ~List();
    void push_back(Type x);
    void push_front(Type x);
    void pop_back();
    void pop_front();
    Type back() const;
    Type front() const;
    int size() const;
    bool empty() const;
    void print() const;
    Type getElem(int n) const;
    iterator begin();
    iterator end();

private:
    struct Node
    {
        Node(Type data);
        Type _data;
        struct Node *_next;
        struct Node *_prev;
    };
    Node *_head;
    Node *_tail;
    int _size;
};

#endif
