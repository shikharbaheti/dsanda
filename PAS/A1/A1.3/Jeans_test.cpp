#include <iostream>
#include "Jeans.h"
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;
using namespace std;

Jeans_colors convertColorJN(const std::string &str)
{
    if (str == "white")
        return Jeans_colors::white;
    else if (str == "blue")
        return Jeans_colors::blue;
    else if (str == "brown")
        return Jeans_colors::brown;
    else if (str == "black")
        return Jeans_colors::black;
};

Jeans_sizes convertSizeJN(const std::string &str)
{
    if (str == "tall")
        return Jeans_sizes::tall;
    else if (str == "grande")
        return Jeans_sizes::grande;
    else if (str == "venti")
        return Jeans_sizes::venti;
};

istream &operator>>(istream &is, CollectionJN &c)
{
    while (is.good())
    {
        string COLOR;
        string SIZE;
        is >> COLOR >> SIZE;
        Jeans_colors colour = convertColorJN(COLOR);
        Jeans_sizes size = convertSizeJN(SIZE);
        Jeans insertItem(colour, size);
        c.insert_item(insertItem);
    }
    return is;
};

ostream &operator<<(ostream &o, const Jeans &sb)
{
    switch (sb.get_color())
    {
    case Jeans_colors::white:
        o << "(white, ";
        break;
    case Jeans_colors::blue:
        o << "(blue, ";
        break;
    case Jeans_colors::brown:
        o << "(brown, ";
        break;
    case Jeans_colors::black:
        o << "(black, ";
        break;
    }
    switch (sb.get_size())
    {
    case Jeans_sizes::tall:
        o << "tall)";
        break;
    case Jeans_sizes::grande:
        o << "grande)";
        break;
    case Jeans_sizes::venti:
        o << "venti)";
        break;
    }
    return o;
};