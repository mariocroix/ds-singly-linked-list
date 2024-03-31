#ifndef FORWARD_LIST_TPP
#define FORWARD_LIST_TPP

#include "forward-list.hpp"

template <typename T>
typename ForwardList<T>::size_type ForwardList<T>::_size = 0;

template <typename T>
ForwardList<T>::ForwardList()
    : _head {nullptr} {}

template <typename T>
ForwardList<T>::~ForwardList()
{
    Node* curr = _head;
    while (curr != nullptr)
    {
        Node* next = curr->_next;
        delete curr;
        curr = next;
    }
}

template <typename T>
typename ForwardList<T>::pointer ForwardList<T>::begin()
{
    return _head;
}

template <typename T>
typename ForwardList<T>::pointer ForwardList<T>::end()
{
    Node* curr = _head;
    while (curr != nullptr)
    {
        curr = curr->_next;
    }
    return curr;
}

template <typename T>
typename ForwardList<T>::const_pointer ForwardList<T>::cbegin() const
{
    return _head;
}

template <typename T>
typename ForwardList<T>::const_pointer ForwardList<T>::cend() const
{
    Node* curr = _head;
    while (curr != nullptr)
    {
        curr = curr->_next;
    }
    return curr;
}

template <typename T>
bool ForwardList<T>::empty() const
{
    return static_cast<bool>(_size);
}

template <typename T>
void ForwardList<T>::clear()
{
    Node* curr = _head;
    while (curr != nullptr)
    {
        Node* next = curr->_next;
        delete curr;
        curr = next;
    }
    _size = 0;
}

template <typename T>
void ForwardList<T>::assign(ForwardList::size_type count, ForwardList::const_reference data)
{
    size_t i = 0;
    Node* curr = _head;
    while (i < count && curr != nullptr)
    {
        ++i;
        curr->_data = data;
        curr = curr->_next;
    }
    while (i < count)
    {
        ++i;
        Node* newNode = new Node(data);
        push_back(newNode);
    }

    _size = i - 1;
}

template <typename T>
void ForwardList<T>::push_front(ForwardList::const_reference data)
{
    Node* newNode = new Node(data);
    newNode->_next = _head;
    _head = newNode;

    ++_size;
}

template <typename T>
void ForwardList<T>::pop_front()
{
    if (_size == 0) {
        throw std::out_of_range("The list is empty.");
    }
    else if (_size == 1)
    {
        delete _head;
        _head = nullptr;
    }
    else
    {
        Node* tmp = _head;
        _head->_next = _head->_next->_next;
        delete tmp;
    }

    --_size;
}

template <typename T>
void ForwardList<T>::push_back(ForwardList::const_reference data)
{
    Node* newNode = new Node(data);

    if (_size == 0)
    {
        _head = newNode;
    }
    else
    {
        Node* curr = _head;
        while (curr->_next != nullptr)
        {
            curr = curr->_next;
        }
        curr->_next = newNode;
    }

    ++_size;
}

template <typename T>
void ForwardList<T>::pop_back()
{
    if (_size == 0)
    {
        throw std::out_of_range("The list is empty.");
    }
    else if (_size == 1)
    {
        delete _head;
        _head = nullptr;
    }
    else
    {
        Node* curr = _head;
        while (curr->_next->_next != nullptr)
        {
            curr = curr->_next;
        }
        delete curr->_next;
        curr->_next = nullptr;
    }

    --_size;
}

template <typename T>
void ForwardList<T>::insert(ForwardList::size_type pos, ForwardList::const_reference data)
{
    if (pos > _size || pos < 0)
    {
        throw std::out_of_range("Position out of range");
    }
    if (pos == _size)
    {
        push_back(data);
    }
    else if (pos == 0)
    {
        push_front(data);
    }
    else
    {
        Node* curr = _head;
        for (size_t i = 0; i < pos - 1; ++i)
        {
            curr = curr->_next;
        }
        Node* newNode = new Node(data);
        newNode->_next = curr->_next;
        curr->_next = newNode;

        ++_size;
    }
}

template <typename T>
void ForwardList<T>::remove(ForwardList::size_type pos)
{
    if (pos < 0 || pos >= _size)
    {
        throw std::out_of_range("Position out of range");
    }
    if (pos == _size - 1)
    {
        pop_back();
    }
    else if (pos == 0)
    {
        pop_front();
    }
    else
    {
        Node* curr = _head;
        for (size_t i = 0; i < pos - 1; ++i)
        {
            curr = curr->_next;
        }
        Node* tmp = curr->_next;
        curr->_next = curr->_next->_next;
        delete tmp;

        --_size;
    }
}

template <typename T>
void ForwardList<T>::reverseIt()
{
    Node* prev = nullptr;
    Node* curr = _head;
    Node* next = nullptr;

    while (curr != nullptr)
    {
        next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }
}

template <typename T>
void ForwardList<T>::reverseRec()
{
    _head = reverseRecursivelyUtil(_head);
}

template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::reverseRecUtil(ForwardList::Node* node)
{
    if (node == nullptr || node->_next == nullptr)
    {
        return node;
    }
    Node* tmp = reverseRecUtil(node->_next);
    tmp->_next = node;
    node->_next = nullptr;
    // return node;
}

template <typename T>
void ForwardList<T>::print() const
{
    Node* curr = _head;
    while (curr != nullptr)
    {
        std::cout << curr->_data << " ";
        curr = curr->_next;
    }
    std::cout << std::endl;
}

template <typename T>
void ForwardList<T>::rprint() const
{
    reversePrintUtil(_head);
    std::cout << std::endl;
}

template <typename T>
void ForwardList<T>::rprintUtil(ForwardList::Node* curr)
{
    if (curr == nullptr) {
        return;
    }

    reversePrintUtil(curr->_next);
    std::cout << curr->_data << " ";
}

template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::getMiddleNode() const
{
    Node* hare = _head->_next;
    Node* tortoise = _head->_next->_next;

    while (hare->_next != nullptr && hare != nullptr)
    {
        hare = hare->_next->_next;
        tortoise = tortoise->_next;
    }

    return tortoise;
}

template <typename T>
bool ForwardList<T>::hasCycle() const
{
    Node* hare = _head->_next;
    Node* tortoise = _head->_next->_next;

    while (hare->_next != nullptr && hare != nullptr)
    {
        hare = hare->_next->_next;
        tortoise = tortoise->_next;

        if (hare == tortoise)
        {
            return true;
        }
    }

    return false;
}

template <typename T>
typename ForwardList<T>::size_type ForwardList<T>::getStartPoint() const
{
    Node* hare = _head->_next;
    Node* tortoise = _head;

    while (hare->_next != nullptr && hare != nullptr)
    {
        hare = hare->_next->_next;
        tortoise = tortoise->_next;

        if (hare == tortoise)
        {
            tortoise = _head;
            size_t index = 0;

            while (hare != tortoise)
            {
                ++index;
                hare = hare->_next;
                tortoise = tortoise->_next;
            }

            return index;
        }
    }
}

template <typename T>
ForwardList<T>::Node::Node()
    : _next {nullptr}
    , _data {ForwardList<T>::value_type()} {}

template <typename T>
ForwardList<T>::Node::Node(ForwardList<T>::const_reference data)
    : _next {nullptr}
    , _data {data} {}

#endif // FORWARD_LIST_TPP