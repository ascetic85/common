/*
 * filename : point.h
 * date     : 2012-11-23
 * author   : ascetic85
 *
 * Vector, aka as Point
 */

#ifndef DD_POINT_H
#define DD_POINT_H

namespace DD
{

class Vector2
{
public:
    Vector2(void) {}
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2(const Vector2& v) : x(v.x), y(v.y) {}

    Vector2& operator*=(const Vector2& vec)
    {
        x *= vec.x;
        y *= vec.y;

        return *this;
    }

    Vector2& operator/=(const Vector2& vec)
    {
        x /= vec.x;
        y /= vec.y;

        return *this;
    }

    Vector2& operator+=(const Vector2& vec)
    {
        x += vec.x;
        y += vec.y;

        return *this;
    }

    Vector2& operator-=(const Vector2& vec)
    {
        x -= vec.x;
        y -= vec.y;

        return *this;
    }

    Vector2 operator+(const Vector2& vec) const
    {
        return Vector2(x + vec.x, y + vec.y);
    }

    Vector2 operator-(const Vector2& vec) const
    {
        return Vector2(x - vec.x, y - vec.y);
    }

    Vector2 operator*(const Vector2& vec) const
    {
        return Vector2(x * vec.x, y * vec.y);
    }

	Vector2 operator*(float c) const
    {
        return Vector2(x * c, y * c);
    }

    bool operator==(const Vector2& vec) const
    {
        return ((x == vec.x) && (y == vec.y));
    }

    bool operator!=(const Vector2& vec) const
    {
        return !(operator==(vec));
    }

    Size asSize() const     { return Size(x, y); }

    float x, y;
};

/*!
\brief
 Point class
*/
typedef Vector2  Point;

/*!
\brief
 Class used as a three dimensional vector
*/
class Vector3
{
public:
    Vector3(void) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

    bool operator==(const Vector3& vec) const
    {
        return ((x == vec.x) && (y == vec.y) && (z == vec.z));
    }

    bool operator!=(const Vector3& vec) const
    {
        return !(operator==(vec));
    }

	Vector3 operator*(float c) const
	{
		return Vector3(x * c, y * c, z * c);
	}

	Vector3 operator+(const Vector3& v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

    float x, y, z;
}; // Vector3 end

}   //DD namespace 

#endif // DD_POINT_H END 
