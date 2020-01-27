#include "Stress_ball.h"
#include "Collection.h"
#include <iostream>

using namespace std;

void Collection::resize(int size, int &capacity, Stress_ball *thingToBeResized) //resize function
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

Collection::Collection(Collection &&other) //move constructor
{
    delete[] this->array;
    this->array = nullptr;
    this->size = 0;
    this->capacity = 0;

    this->array = other.array;
    this->size = other.size;
    this->capacity = other.capacity;

    delete[] other.array;
    other.array = nullptr;
    other.size = 0;
    other.capacity = 0;
};

Collection &Collection::operator=(Collection &&other) //move assignment
{
    if (this != &other)
    {
        delete[] this->array;
        this->array = nullptr;
        this->size = 0;
        this->capacity = 0;

        this->array = other.array;
        this->size = other.size;
        this->capacity = other.capacity;

        delete[] other.array;
        other.array = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
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

Collection &Collection::operator=(const Collection &other) //copy assignment
{
    if (this != &other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        delete[] this->array;
        this->array = new Stress_ball[capacity];
        for (int i = 0; i < other.size; i++)
        {
            this->array[i] = other.array[i];
        }
    }
    return *this;
};

Collection::~Collection() //destructor
{
    size = 0;
    capacity = 0;
    delete[] array;
};

void Collection::insert_item(const Stress_ball &sb) //insert a stress ball
{

    if (this->size == this->capacity)
    {
        resize(this->size, this->capacity, this->array);
    }
    array[this->size] = sb;
    this->size = this->size + 1;
};

bool Collection::contains(const Stress_ball &sb) const
{
    for (int i = 0; i < this->size; i++)
    {
        return this->array[i] == sb;
    }
    return false;
};

void Collection::make_empty() //delete it.
{
    delete[] this->array;
    array = nullptr;
    this->size = 0;
    this->capacity = 0;
};

bool Collection::is_empty() const //if empty
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

int Collection::total_items(Stress_ball_sizes s) const //total items of this size
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

Stress_ball Collection::remove_any_item()
{
    int randomSB = (rand() % this->size);
};

int Collection::total_items(Stress_ball_colors t) const //total items of this color
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

void Collection::print_items() const //literally print all of them.
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
    }
};

Stress_ball &Collection::operator[](int i) //directly access item in the array.
{
    if (i <= (size - 1))
    {
        return array[i];
    }
};
const Stress_ball &Collection::operator[](int i) const //directly access item in the array, but with constant.
{
    if (i <= (size - 1))
    {
        return array[i];
    }
};
