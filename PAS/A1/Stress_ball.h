#ifndef STRESS_BALL_H
#define STRESS_BALL_H

#include <iostream>

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
    Stress_ball();
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes s);
    Stress_ball_colors get_color() const; 
    Stress_ball_sizes get_size() const;
    bool operator==(const Stress_ball &sb) const;
};

std::ostream& operator<<(std::ostream &o, const Stress_ball &sb);

#endif