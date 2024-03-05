//
// Created by Arshia Bakhshayesh on 3/4/2024.
//

#include "Vector2D.h"
#include <cmath>

Vector2D Vector2D::operator+(const Vector2D& vec) const
{
    return Vector2D(x + vec.x, y + vec.y);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
    x += vec.x; y += vec.y;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& vec) const
{
    return Vector2D(x - vec.x, y - vec.y);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
    x -= vec.x; y -= vec.y;
    return *this;
}

Vector2D Vector2D::operator*(float f) const
{
    return Vector2D(x * f, y * f);
}

Vector2D& Vector2D::operator*=(float f)
{
    x *= f; y *= f;
    return *this;
}

Vector2D Vector2D::operator/(float f) const
{
    return Vector2D(x / f, y / f);
}

Vector2D& Vector2D::operator/=(float f)
{
    x /= f; y /= f;
    return *this;
}

float Vector2D::Magnitude() const
{
    return sqrt(x * x + y * y);
}

void Vector2D::Normalize()
{
    x /= Magnitude(); y /= Magnitude();
}

std::ostream& operator<<(std::ostream& os, const Vector2D& vec)
{
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}
