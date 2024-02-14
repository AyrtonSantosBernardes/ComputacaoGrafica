#ifndef ANIMATION_H
#define ANIMATION_H

#include "vec3.h"
#include "rtweekend.h"

class animation {
  public:
    animation(point3 _center, double _radius, double _step) : center(_center), radius(_radius), step(_step) {
        step = degrees_to_radians(step);
    }

    point3 get_position(int frame) {
        double t = frame * step;
        return center + radius * vec3(sin(t), 0, cos(t));
    }

  private:
    point3 center;
    double radius;
    double step;
};

#endif