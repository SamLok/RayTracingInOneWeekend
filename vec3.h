#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <iostream>

class vec3
{
public:
    vec3() {}
    vec3( float x, float y, float z ){ v[0] = x; v[1] = y, v[2] = z; }

    inline float x() const { return v[0]; }
    inline float y() const { return v[1]; }
    inline float z() const { return v[2]; }
    inline float r() const { return v[0]; }
    inline float g() const { return v[1]; }
    inline float b() const { return v[2]; }

    inline const vec3& operator+() const { return *this; }
    inline vec3 operator-() const { return vec3( v[0], v[1], v[2] ); }
    inline float operator[]( int i ) const { return v[i]; }
    inline float& operator[]( int i ) { return v[i]; }

    inline vec3& operator+=( const vec3 &vo );
    inline vec3& operator-=( const vec3 &vo );
    inline vec3& operator*=( const vec3 &vo );
    inline vec3& operator/=( const vec3 &vo );
    inline vec3& operator*=( const float o );
    inline vec3& operator/=( const float o );

    inline float length() const
    {
        return sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
    }

    inline float squared_length() const
    {
        return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
    }

    inline void make_unit_vector();


    float v[3];
};

inline std::istream& operator>>( std::istream &is, vec3 &vec )
{
    is >> vec.v[0] >> vec.v[1] >> vec.v[2];
    return is;
}

inline std::ostream& operator<<( std::ostream &os, const vec3 &vec )
{
    os << vec.v[0] << " " << vec.v[1] << " " << vec.v[2];
    return os;
}

inline void vec3::make_unit_vector()
{
    float t = 1.0 / sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
    v[0] *= t;
    v[1] *= t;
    v[2] *= t;
}

inline vec3 operator+( const vec3 &vec1, const vec3 &vec2 )
{
    return vec3( vec1.v[0]+vec2.v[0], vec1.v[1]+vec2.v[1], vec1.v[2]+vec2.v[2] );
}

inline vec3 operator-( const vec3 &vec1, const vec3 &vec2 )
{
    return vec3( vec1.v[0]-vec2.v[0], vec1.v[1]-vec2.v[1], vec1.v[2]-vec2.v[2] );
}

inline vec3 operator*( const vec3 &vec1, const vec3 &vec2 )
{
    return vec3( vec1.v[0]*vec2.v[0], vec1.v[1]*vec2.v[1], vec1.v[2]*vec2.v[2] );
}

inline vec3 operator/( const vec3 &vec1, const vec3 &vec2 )
{
    return vec3( vec1.v[0]/vec2.v[0], vec1.v[1]/vec2.v[1], vec1.v[2]/vec2.v[2] );
}

inline vec3 operator*( const vec3 &vec, const float t )
{
    return vec3( vec.v[0]*t, vec.v[1]*t, vec.v[2]*t );
}

inline vec3 operator/( const vec3 &vec, const float t )
{
    return vec3( vec.v[0]/t, vec.v[1]/t, vec.v[2]/t );
}

inline vec3 operator*( const float t, const vec3 &vec )
{
    return vec3( vec.v[0]*t, vec.v[1]*t, vec.v[2]*t );
}

inline vec3 operator/( const float t, const vec3 &vec )
{
    return vec3( vec.v[0]/t, vec.v[1]/t, vec.v[2]/t );
}

inline float dot( const vec3 &vec1, const vec3 &vec2 )
{
    return vec1.v[0]*vec2.v[0] + vec1.v[1]*vec2.v[1] + vec1.v[2]*vec2.v[2];
}

inline vec3 cross( const vec3 &vec1, const vec3 &vec2 )
{
    return vec3( ( vec1.v[1]*vec2.v[2] - vec1.v[2]*vec2.v[1] ),
                -( vec1.v[0]*vec2.v[2] - vec1.v[2]*vec2.v[0] ),
                 ( vec1.v[0]*vec2.v[1] - vec1.v[1]*vec2.v[0] ) );
}

inline vec3& vec3::operator+=( const vec3 &vec )
{
    v[0] += vec.v[0];
    v[1] += vec.v[1];
    v[2] += vec.v[2];
}

inline vec3& vec3::operator-=( const vec3 &vec )
{
    v[0] -= vec.v[0];
    v[1] -= vec.v[1];
    v[2] -= vec.v[2];
}

inline vec3& vec3::operator*=( const vec3 &vec )
{
    v[0] *= vec.v[0];
    v[1] *= vec.v[1];
    v[2] *= vec.v[2];
}

inline vec3& vec3::operator/=( const vec3 &vec )
{
    v[0] /= vec.v[0];
    v[1] /= vec.v[1];
    v[2] /= vec.v[2];
}

inline vec3& vec3::operator*=( const float t )
{
    v[0] *= t;
    v[1] *= t;
    v[2] *= t;
}

inline vec3& vec3::operator/=( const float t )
{
    v[0] /= t;
    v[1] /= t;
    v[2] /= t;
}

inline vec3 unit_vector( vec3 v )
{
    return v / v.length();
}










#endif // VEC3_H
