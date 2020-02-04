#ifndef COLLECTION_H
#define COLLECTION_H
#include "Stress_ball.h"
#include <iostream>
#include <string>

using namespace std;
class Collection
{
    Stress_ball *array; //pointer to dynamically allocated memory
    int size;
    int capacity;
    void resize(); //resize the array. should double the size of the array and correctly copy elements from the old array to a new array.

public:
    Collection();
    Collection(int c);                              //the one with size
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
    Collection(Collection &&other);            // move constructor
    Collection &operator=(Collection &&other); //move assignment

    // HELPER FUNCTIONS
    // int get_capacity()
    // {
    //     return capacity;
    // };
    // int get_size()
    // {
    //     return size;
    // };
};

Stress_ball_colors convertColor(const std::string &str);
Stress_ball_sizes convertSize(const std::string &str);

enum class Sort_choice
{
    bubble_sort,
    insertion_sort,
    selection_sort
};

istream &operator>>(istream &is, Collection &c);
ostream &operator<<(ostream &os, const Collection &c);
Collection make_union(const Collection &c1, const Collection &c2);
void swap(Collection &c1, Collection &c2);
void sort_by_size(Collection &c, Sort_choice sort);

#endif