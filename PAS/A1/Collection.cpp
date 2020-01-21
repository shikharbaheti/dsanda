#include "Stress_ball.h"
#include "Collection.h"
#include <iostream>

void Collection::resize(int size, int &capacity, Stress_ball *thingToBeResized)
{
    capacity = capacity * 2;
    Stress_ball *newArray = new Stress_ball[capacity];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
};

Collection::Collection() //default constructor with no arguments
{
    size = 0;
    capacity = 0;
    array = nullptr;
};

Collection::Collection(int s) //constructor with one argument
{
    size = s;
    capacity = 0;
    array = nullptr;
};

Collection::Collection(const Collection &other) //copy constructor
{
    this->size = other.size;
    this->capacity = other.capacity;
    delete[] this->array;
    this->array = new Stress_ball[capacity];
    for (int i = 0; i < size; i++)
    {
        this->array[i] = other.array[i];
    }
};

Collection &Collection::operator=(const Collection &other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    delete[] this->array;
    this->array = new Stress_ball[capacity];
    for (int i = 0; i < other.size; i++)
    {
        this->array[i] = other.array[i];
    }
    return *this;
};

Collection::~Collection() //destructor
{
    size = 0;
    capacity = 0;
    delete[] array;
};

void Collection::insert_item(const Stress_ball &sb)
{

    if (this->size == this->capacity)
    {
        resize(this->size, this->capacity, this->array);
    }
    array[this->size] = sb;
    this->size = this->size + 1;
};

void Collection::make_empty()
{
    delete[] this->array;
    array = nullptr;
    this->size = 0;
    this->capacity = 0;
};

bool Collection::is_empty() const
{
    if (this->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

int Collection::total_items() const
{
    return this->size;
};

int Collection::total_items(Stress_ball_sizes s) const
{
    int sameSizeBalls = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (array[i].get_size == s)
        {
            sameSizeBalls++;
        }
    }

    return sameSizeBalls;
};

int Collection::total_items(Stress_ball_colors t) const
{
    int sameColorBalls = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (array[i].get_color == t)
        {
            sameColorBalls++;
        }
    }
    return sameColorBalls;
};

void Collection::print_items() const
{
    for (int i = 0; i < size; i++)
    {
        Stress_ball::cout << array[i]; //how do you operate this command?
    }
};

Stress_ball &Collection::operator[](int i){};
const Stress_ball &Collection::operator[](int i) const {};
