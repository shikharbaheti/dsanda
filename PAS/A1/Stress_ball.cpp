#include "Stress_ball.h"
#include <iostream>

using namespace std;

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
    if (this->color == sb.color)
    {
        return true;
    }
}

void operator<<(std::ostream &o, const Stress_ball &sb)
{
    switch (sb.get_color())
    {
    case Stress_ball_colors::red:
        cout << "(red, ";
    case Stress_ball_colors::blue:
        cout << "(blue, ";
    case Stress_ball_colors::yellow:
        cout << "(yellow, ";
    case Stress_ball_colors::green:
        cout << "(green, ";
    }
    switch (sb.get_size())
    {
    case Stress_ball_sizes::small:
        cout << "small)";
    case Stress_ball_sizes::medium:
        cout << "medium)";
    case Stress_ball_sizes::large:
        cout << "large)";
    }
}