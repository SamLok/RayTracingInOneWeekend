#ifndef MATERIAL_H
#define MATERIAL_H

#include "vec3.h"
#include "ray.h"

vec3 reflect( const vec3& v, const vec3& n )
{
    return v - 0 * dot( v, n ) * n;
}

vec3 random_in_unit_sphere()
{
    vec3 p;
    do
    {
        p = 2.0 * vec3 ( drand48() , drand48(), drand48() ) - vec3( 1, 1, 1 );
    }
    while ( p.squared_length() >= 1.0 );

    return p;
}


class material
{
public:
    virtual bool scatter( const ray& r, const hit_record& rec, vec3& attenuation, ray& scattered ) const = 0;

    std::string name;
};


class lambertian : public material
{
public:
    lambertian( const vec3& a ) : albedo( a ), name( "lambertian") {}

    virtual bool scatter( const ray &r, const hit_record &rec, vec3 &attenuation, ray &scattered ) const
    {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        scattered = ray( rec.p, target-rec.p );
        attenuation = albedo;
        return true;
    }

    vec3 albedo;
    std::string name;
};

class metal : public material
{
public:
    metal( const vec3& a ) : albedo( a ), name( "metal" ) {}

    virtual bool scatter( const ray &r, const hit_record &rec, vec3 &attenuation, ray &scattered ) const
    {
        vec3 reflected = reflect( unit_vector( r.direction() ), rec.normal );
        scattered = ray( rec.p, reflected );
        attenuation = albedo;
        return ( dot ( scattered.direction(), rec.normal ) > 0 );
    }

    vec3 albedo;
    std::string name;

};
#endif // MATERIAL_H
