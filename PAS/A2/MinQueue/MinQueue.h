#ifndef MINQUEUE_H
#define MINQUEUE_H
#include <iostream>
#include <stdexcept>
#include "TemplatedDLList.h"
using namespace std;
template <typename T>
class MinQueue
{
private:
    DLList<T> queue;
    int size = 0;

public:
    //inserting an element in the end of the link list, enqueuing to the last place
    void enqueue(T a)
    {
        queue.insert_last(a);
        size++;
    };
    // removing the first element, dequeuing first element
    void dequeue()
    {
        queue.remove_first();
        size--;
    };
    // return if true empty, false otherwise
    bool is_empty()
    {
        return queue.is_empty();
    };
    //returns the size of the Queue
    int sizeMQ()
    {
        return size;
    };
    //returns the minimum element in the Queue
    T min()
    {
        DLListNode<T> *node = queue.first_node();
        T minimum = node->obj;
        while (node != queue.after_last_node())
        {
            if (node->obj < minimum)
            {
                minimum = node->obj;
            }
            node = node->next;
        }
        return minimum;
    }
    // helper function to print out our MinQueue
    void printMQ()
    {
        cout << queue << endl;
    };
};
#endif