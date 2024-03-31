#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <iostream>

template <typename T>
class ForwardList
{
private:
    struct Node;
public:
    using value_type = T;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;

    ForwardList();
    ~ForwardList();
    pointer begin();
    pointer end();
    const_pointer cbegin() const;
    const_pointer cend() const;
    bool empty() const;
    void clear();
    void assign(size_type, const_reference);
    void push_front(const_reference);
    void pop_front();
    void push_back(const_reference);
    void pop_back();
    void insert(size_type, const_reference);
    void remove(size_type);
    void reverseIt();
    void reverseRec();
    void print() const;
    void rprint() const;
    Node* getMiddleNode() const;
    bool hasCycle() const;
    size_type getStartPoint() const;

private:
    struct Node
    {
        Node* _next;
        value_type _data;
        Node();
        explicit Node(const_reference);
    };

    Node* _head;
    static size_type _size;

    Node* reverseRecUtil(Node*);
    void rprintUtil(Node*);
};

#include "forward-list.tpp"

#endif // FORWARD_LIST_HPP