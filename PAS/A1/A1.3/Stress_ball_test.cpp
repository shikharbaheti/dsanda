#include <iostream>
#include "Stress_ball.h"
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;
using namespace std;

Stress_ball_colors convertColorSB(const std::string &str)
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

Stress_ball_sizes convertSizeSB(const std::string &str)
{
    if (str == "small")
        return Stress_ball_sizes::small;
    else if (str == "medium")
        return Stress_ball_sizes::medium;
    else if (str == "large")
        return Stress_ball_sizes::large;
};

istream &operator>>(istream &is, CollectionSB &c)
{
    while (is.good())
    {
        string COLOR;
        string SIZE;
        is >> COLOR >> SIZE;
        Stress_ball_colors colour = convertColorSB(COLOR);
        Stress_ball_sizes size = convertSizeSB(SIZE);
        Stress_ball insertItem(colour, size);
        c.insert_item(insertItem);
    }
    return is;
};

ostream &operator<<(ostream &o, const Stress_ball &sb)
{
    switch (sb.get_color())
    {
    case Stress_ball_colors::red:
        o << "(red, ";
        break;
    case Stress_ball_colors::blue:
        o << "(blue, ";
        break;
    case Stress_ball_colors::yellow:
        o << "(yellow, ";
        break;
    case Stress_ball_colors::green:
        o << "(green, ";
        break;
    }
    switch (sb.get_size())
    {
    case Stress_ball_sizes::small:
        o << "small)";
        break;
    case Stress_ball_sizes::medium:
        o << "medium)";
        break;
    case Stress_ball_sizes::large:
        o << "large)";
        break;
    }
    return o;
};