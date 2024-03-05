//
// Created by Arshia Bakhshayesh on 3/1/2024.
//

#include "Vector3D.h"
#include "../RotationSystems/Quaternion.h"
#include <cmath>

Vector3D Vector3D::operator+(const Vector3D &vec) const
{
    return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D Vector3D::operator+(float f) const
{
    return Vector3D(x + f, y + f, z + f);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
    x += vec.x; y += vec.y; z += vec.z;
    return *this;  // Return a reference to the modified object
}

Vector3D &Vector3D::operator+=(float f)
{
    x += f; y += f; z += f;
    return *this;  // Return a reference to the modified object
}

Vector3D Vector3D::operator-(const Vector3D &vec) const
{
    return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D Vector3D::operator-(float f) const
{
    return Vector3D(x - f, y - f, z - f);
}

Vector3D &Vector3D::operator-=(const Vector3D &vec)
{
    x -= vec.x; y -= vec.y; z -= vec.z;
    return *this;  // Return a reference to the modified object
}

Vector3D &Vector3D::operator-=(float f)
{
    x -= f; y -= f; z -= f;
    return *this;  // Return a reference to the modified object
}

Vector3D Vector3D::operator/(const Vector3D &vec) const
{
    return Vector3D(x / vec.x, y / vec.y, z / vec.z);
}

Vector3D Vector3D::operator/(float f) const
{
    return Vector3D(x / f, y / f, z / f);
}

Vector3D& Vector3D::operator/=(const Vector3D& vec)
{
    x /= vec.x; y /= vec.y; z /= vec.z;
    return *this; // Return a reference to the modified object
}

Vector3D& Vector3D::operator/=(float f)
{
    x /= f; y /= f; z /= f;
    return *this; // Return a reference to the modified object
}

Vector3D Vector3D::operator*(float f) const
{
    return Vector3D(x * f, y * f, z * f);
}

Vector3D& Vector3D::operator*=(float f)
{
    x *= f; y *= f; z *= f;
    return *this; // Return a reference to the modified object
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
}

std::ostream &operator<<(std::ostream &os, const Vector3D &vec)
{
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

void Vector3D::ScalarMultiplication(float scale)
{
    x *= scale; y *= scale; z *= scale;
}

float Vector3D::Magnitude() const
{
    double mag = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return mag;
}

void Vector3D::Normalize()
{
    x /= Magnitude(); y /= Magnitude(); z /= Magnitude();
}

Vector3D Vector3D::RotateAroundAxis(float angle, const Vector3D &axis)
{

    // Convert our vector to a pure quaternion
    Quaternion p(0,(*this));

    // Normalize the axis
    Vector3D NormalizedAxis = axis;
    NormalizedAxis.Normalize();

    // Create the real quaternion
    Quaternion q(angle, NormalizedAxis);

    // Convert quaternion to unit norm quaternion
    q.ToUnitNormQuaternion();

    // Get the inverse of the quaternion
    Quaternion qInverse = q.Inverse();

    // Rotate the quaternion
    Quaternion RotatedVector = q * p * qInverse;

    // Return the vector part of the quaternion
    return RotatedVector.v;
}

Vector3D Vector3D::RotateX(float angle)
{
    return RotateAroundAxis(angle, Vector3D(1, 0, 0));
}

Vector3D Vector3D::RotateY(float angle)
{
    return RotateAroundAxis(angle, Vector3D(0, 1, 0));
}

Vector3D Vector3D::RotateZ(float angle)
{
    return RotateAroundAxis(angle, Vector3D(0, 0, 1));
}

float Vec3Operator::Dot(const Vector3D &vec1, const Vector3D &vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

Vector3D Vec3Operator::Cross(const Vector3D &vec1, const Vector3D &vec2)
{
    return Vector3D((vec1.y * vec2.z) - (vec1.z * vec2.y),
                    -((vec1.x * vec2.z) - (vec1.z * vec2.x)),
                    (vec1.x * vec2.y) - (vec1.y * vec2.x));
}



