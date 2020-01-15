#ifndef STRESS_BALL_H
#define STRESS_BALL_H

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
    Stress_ball_colors get_color()
    {
        return color;
    };
    Stress_ball_sizes get_size()
    {
        return size;
    };
    bool operator==(const Stress_ball &sb)
    {
      if (this->color == sb.color) {
          return true;
      }
    }
};  

#endif