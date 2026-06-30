#ifndef LIST_HPP
#define LIST_HPP

#include <string>
using Type = std::string;

class List
{
public:
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
private:
    struct Node
    {
        Node(Type data);
        Type _data;
        struct Node* _next;
        struct Node* _prev;
    };
    Node* _head;
    Node* _tail;
    int _size;
};


#endif