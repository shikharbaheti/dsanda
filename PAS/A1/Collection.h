#ifndef COLLECTION_H
#define COLLECTION_H

#include "Stress_ball.h"

#include <iostream>

class Collection
{
    Stress_ball *array;
    int size;
    int capacity;
    void resize(); //resize the array. should double the size of the array and correctly copy elements from the old array to a new array.

public:
    Collection();
    Collection(int s);                              //the one with size
    Collection(const Collection &other);            // copy constructor
    Collection &operator=(const Collection &other); //copy assignment operator
    ~Collection();                                  //destructor
    void insert_item(const Stress_ball &sb);        // insert a stress ball into the collection
    bool contains(const Stress_ball &sb) const;
    Stress_ball remove_any_item();
    void remove_this_item(const Stress_ball &sb);
    void make_empty();
    bool is_empty() const;
    int total_items() const;
    int total_items(Stress_ball_sizes s) const;
    int total_items(Stress_ball_colors t) const;
    void print_items() const;
    Stress_ball &operator[](int i);
    const Stress_ball &operator[](int i) const;
};

#endif