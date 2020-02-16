#ifndef Jeans_H
#define Jeans_H
#include "Collection.h"
#include <iostream>
using namespace std;
enum class Jeans_colors
{
    white,
    blue,
    brown,
    black
};

enum class Jeans_sizes
{
    tall,
    grande,
    venti
};

class Jeans
{

    Jeans_sizes size;
    Jeans_colors color;

public:
    Jeans()
    {
        size = static_cast<Jeans_sizes>(rand() % 3);
        color = static_cast<Jeans_colors>(rand() % 4);
    };
    Jeans(Jeans_colors c, Jeans_sizes s)
    {
        size = s;
        color = c;
    };
    Jeans_colors get_color() const
    {
        return color;
    };
    Jeans_sizes get_size() const
    {
        return size;
    };
    bool operator==(const Jeans &sb) const
    {
        if ((this->color == sb.color) && (this->size == sb.size))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

Jeans_colors convertColorJN(const std::string &str);
Jeans_sizes convertSizeJN(const std::string &str);
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;
ostream &operator<<(ostream &o, const Jeans &sb);
istream &operator>>(istream &is, CollectionJN &c);

#endif