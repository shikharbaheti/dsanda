#ifndef STRESS_BALL_H
#define STRESS_BALL_H
#include "Collection.h"
#include <iostream>
using namespace std;
enum class Stress_ball_colors
{
    red,
    blue,
    yellow,
    green
};

enum class Stress_ball_sizes
{
    small,
    medium,
    large
};

class Stress_ball
{

    Stress_ball_sizes size;
    Stress_ball_colors color;

public:
    Stress_ball()
    {
        size = static_cast<Stress_ball_sizes>(rand() % 3);
        color = static_cast<Stress_ball_colors>(rand() % 4);
    };
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes s)
    {
        size = s;
        color = c;
    };
    Stress_ball_colors get_color() const
    {
        return color;
    };
    Stress_ball_sizes get_size() const
    {
        return size;
    };
    bool operator==(const Stress_ball &sb) const
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

Stress_ball_colors convertColorSB(const std::string &str);
Stress_ball_sizes convertSizeSB(const std::string &str);
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;
istream &operator>>(istream &is, CollectionSB &c);
ostream &operator<<(ostream &o, const Stress_ball &sb);

#endif