// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H
#include <iostream>
#include <stdexcept>
using namespace std;

struct EmptyDLList : public std::runtime_error
{
    explicit EmptyDLList(char const *msg = nullptr) : runtime_error(msg) {}
};

struct InvalidOperation : public std::runtime_error
{
    explicit InvalidOperation(char const *msg = nullptr) : runtime_error(msg) {}
};

// class DLList<T>; // class declaration

// doubly linked list node
template <typename T>
struct DLListNode
{
    T obj;
    DLListNode *prev, *next;
    // constructor
    DLListNode(T e = T(), DLListNode *p = nullptr, DLListNode *n = nullptr)
        : obj(e), prev(p), next(n) {}
};

// doubly linked list class
template <typename T>
class DLList
{
private:
    DLListNode<T> header, trailer;

public:
    DLList() : header(T()), trailer(T()) // default constructor
    {
        header.next = &trailer;
        trailer.prev = &header;
    }
    DLList(const DLList<T> &dll)
    {
        header.next = &trailer;
        trailer.prev = &header;

        DLListNode<T> *node = dll.first_node();
        while (node != dll.after_last_node())
        {
            insert_last(node->obj);
            node = node->next;
        }
    }; // copy constructor
    DLList(DLList<T> &&dll)
    {
        header.next = dll.header.next;
        trailer.prev = dll.trailer.prev;

        dll.header.next->prev = &header;
        trailer.prev->next = &trailer;

        dll.header.next = &dll.trailer;
        dll.trailer.prev = &dll.header;
    }; // move constructor
    ~DLList()
    {
        DLListNode<T> *prev_node, *node = header.next;
        while (node != &trailer)
        {
            prev_node = node;
            node = node->next;
            delete prev_node;
        }
        header.next = &trailer;
        trailer.prev = &header;
    }; // destructor
    DLList<T> &operator=(const DLList<T> &dll)
    {
        if (this != &dll)
        {
            if (!this->is_empty())
            {
                DLListNode<T> *prev_node, *node = header.next;
                while (node != &trailer)
                {
                    prev_node = node;
                    node = node->next;
                    delete prev_node;
                }
            }
            header.next = &trailer;
            trailer.prev = &header;

            DLListNode<T> *node = dll.first_node();
            while (node != dll.after_last_node())
            {
                insert_last(node->obj);
                node = node->next;
            }
        }
        return *this;
    }; // copy assignment operator
    DLList<T> &operator=(DLList<T> &&dll)
    {
        if (this != &dll)
        {
            if (!this->is_empty())
            {
                DLListNode<T> *prev_node, *node = header.next;
                while (node != &trailer)
                {
                    prev_node = node;
                    node = node->next;
                    delete prev_node;
                }
                header.next = &trailer;
                trailer.prev = &header;
            }
            header.next = dll.header.next;
            trailer.prev = dll.trailer.prev;

            dll.header.next->prev = &header;
            trailer.prev->next = &trailer;

            dll.header.next = &dll.trailer;
            dll.trailer.prev = &dll.header;
        }
        return *this;
    }; // move assignment operator
    // return the pointer to the first node
    DLListNode<T> *first_node() const { return header.next; }
    // return the pointer to the trailer
    const DLListNode<T> *after_last_node() const { return &trailer; }
    // return if the list is empty
    bool is_empty() const { return header.next == &trailer; }
    T first() const
    {
        if (is_empty())
            throw EmptyDLList("Empty Doubly Linked List!");
        return header.next->obj;
    }; // return the first object
    T last() const
    {
        if (is_empty())
            throw EmptyDLList("Empty Doubly Linked List!");
        return trailer.prev->obj;
    }; // return the last object
    void insert_first(T obj)
    {
        DLListNode<T> *newNode = new DLListNode<T>(obj, &header, header.next);
        header.next->prev = newNode;
        header.next = newNode;
    }; // insert to the first node
    T remove_first()
    {
        if (is_empty())
            throw EmptyDLList("Empty Doubly Linked List! Cannot remove things when list is empty!");
        DLListNode<T> *node = header.next;
        node->next->prev = &header;
        header.next = node->next;
        T obj = node->obj;
        delete node;
        return obj;
    }; // remove the first node
    void insert_last(T obj)
    {
        DLListNode<T> *newNode = new DLListNode<T>(obj, trailer.prev, &trailer);
        trailer.prev->next = newNode;
        trailer.prev = newNode;
    }; // insert to the last node
    T remove_last()
    {
        if (is_empty())
            throw EmptyDLList("Empty Doubly Linked List!");
        DLListNode<T> *node = trailer.prev;
        node->prev->next = &trailer;
        trailer.prev = node->prev;
        T obj = node->obj;
        delete node;
        return obj;
    }; // remove the last node
    void insert_after(DLListNode<T> &p, T obj)
    {
        if (is_empty())
            throw EmptyDLList("Empty Doubly Linked List!");
        DLListNode<T> *nodeToBeInserted = new DLListNode<T>(obj, &p, p.next);
        p.next->prev = nodeToBeInserted;
        p.next = nodeToBeInserted;
    };
    void insert_before(DLListNode<T> &p, T obj)
    {
        if (is_empty())
            throw EmptyDLList("Empty Doubly Linked List!");
        DLListNode<T> *nodeToBeInserted = new DLListNode<T>(obj, p.prev, &p);
        p.prev->next = nodeToBeInserted;
        p.prev = nodeToBeInserted;
    };
    T remove_after(DLListNode<T> &p)
    {
        if (is_empty())
            throw EmptyDLList("Empty Doubly Linked List!");
        if (&p == &trailer)
        {
            throw InvalidOperation("Cannot remove after trailer!");
        }
        DLListNode<T> *temp = p.next;
        temp->next->prev = &p;
        p.next = temp->next;
        T valueHeld = temp->obj;
        delete temp;
        return valueHeld;
    };
    T remove_before(DLListNode<T> &p)
    {
        if (is_empty())
            throw EmptyDLList("Empty Doubly Linked List!");
        if (&p == &header)
        {
            throw InvalidOperation("Cannot remove before header!");
        }
        DLListNode<T> *temp = p.prev;
        temp->prev->next = &p;
        p.prev = temp->prev;
        T valueHeld = temp->obj;
        delete temp;
        return valueHeld;
    };

    // HELPER FUNCTIONS TO TEST FUNCTIONALITY!

    //returns a pointer to the trailer
    DLListNode<T> *theTrailerPointer()
    {
        return &trailer;
    }
};

// output operator
template <typename T>
ostream &operator<<(ostream &out, const DLList<T> &dll)
{
    if (dll.is_empty())
    {
        throw EmptyDLList("Empty Doubly Linked List!");
    }
    DLListNode<T> *node = dll.first_node();
    while (node != dll.after_last_node())
    {
        out << node->obj << " ";
        node = node->next;
    }
    return out;
};
#endif
