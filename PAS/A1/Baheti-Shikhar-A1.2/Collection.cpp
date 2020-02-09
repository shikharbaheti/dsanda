#include "Stress_ball.h"
#include "Collection.h"
#include <iostream>
#include <string>

using namespace std;

void Collection::resize() //resize function
{
    if (capacity == 0)
    {
        capacity = capacity + 1;
        array = new Stress_ball[capacity];
    }
    else
    {
        capacity = capacity * 2;
        Stress_ball *newArray = new Stress_ball[capacity];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
};

Collection::Collection(Collection &&other) //move constructor
{
    this->array = other.array;
    this->size = other.size;
    this->capacity = other.capacity;
    other.array = nullptr;
    other.size = 0;
    other.capacity = 0;
};

Collection &Collection::operator=(Collection &&other) //move assignment
{
    if (this != &other)
    {
        // if (array == nullptr)
        // {
        //     delete[] this->array;
        // }
        // this->array = nullptr;
        // this->size = 0;
        // this->capacity = 0;

        this->array = other.array;
        this->size = other.size;
        this->capacity = other.capacity;

        // delete[] other.array;
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

Collection::Collection(int c) //constructor with one argument
{
    size = 0;
    capacity = c;
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
        resize();
    }
    else if (array == nullptr)
    {
        array = new Stress_ball[capacity];
    }
    this->array[this->size] = sb;
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
    // this->capacity = 0;
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
        if (array[i].get_size() == s)
        {
            sameSizeBalls++;
        }
    }

    return sameSizeBalls;
};

Stress_ball Collection::remove_any_item()
{
    int randomSB = (rand() % this->size);
    Stress_ball item = this->array[randomSB];

    for (int i = randomSB; i < this->size; i++) //might have an issue with swapping on the border.
    {
        swap(array[i], array[i + 1]);
    }
    this->size = this->size - 1;
    return item;
};

void Collection::remove_this_item(const Stress_ball &sb)
{
    int indexOfItem = 0;
    for (int i = 0; i < this->size; i++)
    {
        if ((this->array[i].get_color() == sb.get_color()) && (this->array[i].get_size() == sb.get_size()))
        {
            indexOfItem = i;
        }
    }

    for (int i = indexOfItem; i < this->size; i++) //might have an issue with swapping on the border.
    {
        swap(array[i], array[i + 1]);
    }
    this->size = this->size - 1;
};

int Collection::total_items(Stress_ball_colors t) const //total items of this color
{
    int sameColorBalls = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (array[i].get_color() == t)
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

    if (this->array == nullptr)
    {
        cout << "The array is empty." << endl;
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

Stress_ball_colors convertColor(const std::string &str)
{
    if (str == "red")
        return Stress_ball_colors::red;
    else if (str == "blue")
        return Stress_ball_colors::blue;
    else if (str == "yellow")
        return Stress_ball_colors::yellow;
    else if (str == "green")
        return Stress_ball_colors::green;
};

Stress_ball_sizes convertSize(const std::string &str)
{
    if (str == "small")
        return Stress_ball_sizes::small;
    else if (str == "medium")
        return Stress_ball_sizes::medium;
    else if (str == "large")
        return Stress_ball_sizes::large;
};

istream &operator>>(istream &is, Collection &c) //HOW TO REMOVE EMPTY LINES??
{
    while (is.good())
    {
        string COLOR;
        string SIZE;
        is >> COLOR >> SIZE;
        Stress_ball_colors colour = convertColor(COLOR);
        Stress_ball_sizes size = convertSize(SIZE);
        Stress_ball insertItem(colour, size);
        c.insert_item(insertItem);
    }
    return is;
};
ostream &operator<<(ostream &os, const Collection &c)
{
    for (int i = 0; i < c.total_items(); i++)
    {
        os << c[i];
    }
    return os;
};

Collection make_union(const Collection &c1, const Collection &c2)
{
    Collection c3;

    for (int i = 0; i < c1.total_items(); i++)
    {
        c3.insert_item(c1[i]);
    }

    for (int k = 0; k < c2.total_items(); k++)
    {
        c3.insert_item(c2[k]);
    }
    return c3;
};

void swap(Collection &c1, Collection &c2)
{
    Collection swapper1(move(c1)); //swapper contains all elements in C1
    Collection swapper2(move(c2));

    c2 = move(swapper1);
    c1 = move(swapper2);
};

void sort_by_size(Collection &c, Sort_choice sort)
{
    switch (sort)
    {
    case Sort_choice::bubble_sort:
        cout << "SORTING THROUGH BUBBLE SORT" << endl;
        for (int k = 1; k < c.total_items(); k++)
        {
            bool cont = false;
            for (int j = 0; j < c.total_items() - k; j++)
                if (c[j + 1].get_size() < c[j].get_size())
                {
                    Stress_ball tmp = c[j]; // swap A[j] and A[j+1]
                    c[j] = c[j + 1];
                    c[j + 1] = tmp;
                    cont = true;
                }
            if (!cont)
                break; // stop sorting
        }
        break;
    case Sort_choice::insertion_sort:
        cout << "SORTING THROUGH INSERTION SORT" << endl;
        for (int k = 1; k < c.total_items(); k++)
        {
            Stress_ball tmp = c[k];
            int j = k;
            for (; j > 0 && tmp.get_size() < c[j - 1].get_size(); j--)
                c[j] = c[j - 1];
            c[j] = tmp;
        }
        break;
    case Sort_choice::selection_sort:
        cout << "SORTING THROUGH SELECTION SORT" << endl;
        for (int k = 0; k < c.total_items() - 1; k++)
        {
            int index = k;
            for (int i = k + 1; i < c.total_items(); i++)
                if (c[i].get_size() < c[index].get_size())
                    index = i;
            Stress_ball tmp = c[k]; // swap A[k] and A[index]
            c[k] = c[index];
            c[index] = tmp;
        }
        break;
    }
};