#include "Stress_ball.h"
#include <iostream>

Stress_ball_colors Stress_ball::get_color() const
{
    return color;
}

Stress_ball_sizes Stress_ball::get_size() const
{
    return size;
}
Stress_ball::Stress_ball()
{
    size = static_cast<Stress_ball_sizes>(rand() % 3);
    color = static_cast<Stress_ball_colors>(rand() % 4);
}
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s)
{
    size = s;
    color = c;
}
bool Stress_ball::operator==(const Stress_ball &sb) const
{
    if ((this->color == sb.color) && (this->size == sb.size))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream &operator<<(std::ostream &o, const Stress_ball &sb)
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
}