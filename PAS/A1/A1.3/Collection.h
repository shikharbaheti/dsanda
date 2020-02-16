#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <string>
using namespace std;
template <class Obj, typename F1, typename F2>
class Collection
{
    Obj *array; //pointer to dynamically allocated memory
    int size;
    int capacity;
    void resize()
    {
        if (capacity == 0)
        {
            capacity = capacity + 1;
            array = new Obj[capacity];
        }
        else
        {
            capacity = capacity * 2;
            Obj *newArray = new Obj[capacity];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    };

public:
    Collection()
    {
        size = 0;
        capacity = 0;
        array = nullptr;
    };
    Collection(int c)
    {
        size = 0;
        capacity = c;
        array = nullptr;
    };
    Collection(const Collection &other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        delete[] this->array;
        this->array = new Obj[capacity];
        for (int i = 0; i < size; i++)
        {
            this->array[i] = other.array[i];
        }
    };
    Collection &operator=(const Collection &other)
    {
        if (this != &other)
        {
            this->size = other.size;
            this->capacity = other.capacity;
            delete[] this->array;
            this->array = new Obj[capacity];
            for (int i = 0; i < other.size; i++)
            {
                this->array[i] = other.array[i];
            }
        }
        return *this;
    };
    ~Collection()
    {
        size = 0;
        capacity = 0;
        delete[] array;
    };
    void insert_item(const Obj &sb)
    {
        if (this->size == this->capacity)
        {
            resize();
        }
        else if (array == nullptr)
        {
            array = new Obj[capacity];
        }
        this->array[this->size] = sb;
        this->size = this->size + 1;
    };
    bool contains(const Obj &sb) const
    {
        for (int i = 0; i < this->size; i++)
        {
            return this->array[i] == sb;
        }
        return false;
    };
    Obj remove_any_item()
    {
        int randomSB = (rand() % this->size);
        Obj item = this->array[randomSB];

        for (int i = randomSB; i < this->size; i++) //might have an issue with swapping on the border.
        {
            swap(array[i], array[i + 1]);
        }
        this->size = this->size - 1;
        return item;
    };
    void remove_this_item(const Obj &sb)
    {
        int indexOfItem = 0;
        for (int i = 0; i < this->size; i++)
        {
            if ((this->array[i].get_color() == sb.get_color()) && (this->array[i].get_size() == sb.get_size()))
            {
                indexOfItem = i;
            }
        }

        for (int i = indexOfItem; i < this->size; i++)
        {
            swap(array[i], array[i + 1]);
        }
        this->size = this->size - 1;
    };
    void make_empty()
    {
        delete[] this->array;
        array = nullptr;
        this->size = 0;
    };
    bool is_empty() const
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
    int total_items() const
    {
        return this->size;
    };
    int total_items(F2 s) const
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
    int total_items(F1 t) const
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
    void print_items() const
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
    Obj &operator[](int i)
    {
        if (i <= (size - 1))
        {
            return array[i];
        }
    };
    const Obj &operator[](int i) const
    {
        if (i <= (size - 1))
        {
            return array[i];
        }
    };
    Collection(Collection &&other)
    {
        this->array = other.array;
        this->size = other.size;
        this->capacity = other.capacity;
        other.array = nullptr;
        other.size = 0;
        other.capacity = 0;
    };
    Collection &operator=(Collection &&other)
    {
        if (this != &other)
        {

            this->array = other.array;
            this->size = other.size;
            this->capacity = other.capacity;
            other.array = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    };
};

enum class Sort_choice
{
    bubble_sort,
    insertion_sort,
    selection_sort
};
template <class Obj, typename F1, typename F2>
ostream &operator<<(ostream &os, const Collection<Obj, F1, F2> &c)
{
    for (int i = 0; i < c.total_items(); i++)
    {
        os << c[i];
    }
    return os;
};
template <class Obj, typename F1, typename F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2> &c1, const Collection<Obj, F1, F2> &c2)
{
    Collection<Obj, F1, F2> c3;

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
template <class Obj, typename F1, typename F2>
void swap(Collection<Obj, F1, F2> &c1, Collection<Obj, F1, F2> &c2)
{
    Collection<Obj, F1, F2> swapper1(move(c1)); //swapper contains all elements in C1
    Collection<Obj, F1, F2> swapper2(move(c2));

    c2 = move(swapper1);
    c1 = move(swapper2);
};
template <class Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj, F1, F2> &c, Sort_choice sort)
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
                    Obj tmp = c[j]; // swap A[j] and A[j+1]
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
            Obj tmp = c[k];
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
            Obj tmp = c[k]; // swap A[k] and A[index]
            c[k] = c[index];
            c[index] = tmp;
        }
        break;
    }
};
#endif