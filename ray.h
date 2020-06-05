#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
public:
    ray() {}
    ray( const vec3 &ori, const vec3 &dir ) { origin_ray=ori; direction_ray=dir; }

    vec3 origin() const { return origin_ray; }
    vec3 direction() const { return direction_ray; }
    vec3 point_at_parameter( float t ) const { return origin_ray + t*direction_ray; }

    vec3 origin_ray;
    vec3 direction_ray;
};

#endif // RAY_H
