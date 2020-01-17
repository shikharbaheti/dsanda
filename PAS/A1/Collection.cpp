#include "Stress_ball.h"
#include "Collection.h"
#include <iostream>

Collection::Collection() //default constructor with no arguments
{
    size = 0;
    capacity = 0;
    array = nullptr;
};

Collection::Collection(const Collection &other) //copy constructor
{
    size = other.size;
    capacity = other.capacity;

    for (int i = 0; i < size; i++)
    { //copy the array
        array[i] = other.array[i];
    }
};

Collection::Collection(int s) //constructor with one argument
{
    size = s;
    capacity = 0;
    array = nullptr;
};

// Collection operator=(const Collection &other) const
// { //idk about this

// };

Collection::~Collection() //destructor
{
    size = 0;
    capacity = 0;
    delete[] array;
};
