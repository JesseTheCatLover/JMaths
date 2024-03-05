//
// Created by Arshia Bakhshayesh on 3/1/2024.
//

#include "Quaternion.h"
#include "EulerAngles.h"
#include "../Utilities/AngleConverter.h"
#include <cmath>

Quaternion Quaternion::operator*(const Quaternion &q) const
{
    float scalar = w * q.w - Vec3Operator::Dot(v, q.v);
    Vector3D vector = (q.v * w) + (v * q.w) + Vec3Operator::Cross(v, q.v);
    return Quaternion(scalar, vector);
}

Quaternion Quaternion::operator*(float f) const
{
    float scalar = w * f;
    Vector3D vector = v * f;
    return Quaternion(scalar, vector);
}

void Quaternion::operator*=(const Quaternion &q)
{
    (*this) * q;
}

void Quaternion::operator*=(float f)
{
    w *= f; v *= f;
}

void Quaternion::operator+=(const Quaternion &q)
{
    w += q.w; v += q.v;
}

Quaternion Quaternion::operator+(const Quaternion &q) const
{
    float scalar = w + q.w;
    Vector3D vector = v + q.v;
    return Quaternion(scalar, vector);
}

void Quaternion::operator-=(const Quaternion &q)
{
    w -= q.w; v -= q.v;
}

Quaternion Quaternion::operator-(const Quaternion &q) const
{
    float scalar = w - q.w;
    Vector3D vector = v - q.v;
    return Quaternion(scalar, vector);
}

std::ostream &operator<<(std::ostream &os, const Quaternion &q)
{
    os << "(" << q.w << ", " << q.v.x << ", " << q.v.y << ", " << q.v.z << ")";
    return os;
}

Quaternion Quaternion::Conjugate() const
{
    return Quaternion(w, -v);
}

float Quaternion::Magnitude() const
{
    return sqrt((w * w) + Vec3Operator::Dot(v, v));
}

Quaternion Quaternion::Normalize() const
{
    return Quaternion(w / Magnitude(), v / Magnitude());
}

void Quaternion::ToUnitNormQuaternion()
{
    float angle = w * (M_PI / 180.0f);
    v.Normalize();
    w = cosf(angle * 0.5);
    v = v * sinf(angle * 0.5);
}

Quaternion Quaternion::Inverse()
{
    float AbsoluteValue = Magnitude();
    AbsoluteValue *= AbsoluteValue;
    AbsoluteValue = 1 / AbsoluteValue;

    const Quaternion ConjugateQuat = Conjugate();

    float Scalar = ConjugateQuat.w * AbsoluteValue;
    Vector3D Vector = ConjugateQuat.v * AbsoluteValue;

    return Quaternion(Scalar, Vector);
}

EulerAngles Quaternion::ToEulerAngles()
{
    float pitch; float yaw; float roll;

    float test = 2 * (v.x * v.z - w * v.y);

    if (test != 1 && test != -1) // I've learned this from Harold Serrano..
    {

        pitch = atan2(v.y * v.z + w * v.x, 0.5f - (v.x * v.x + v.y * v.y));
        yaw = asin(-2 * (v.x * v.z - w * v.y));
        roll = atan2(v.x * v.y + w * v.z, 0.5 - (v.y * v.y + v.z * v.z));

    } else if (test == 1)
    {
        roll = atan2(v.x * v.y + w * v.z, 0.5f - (v.y * v.y + v.z * v.z));
        yaw = -M_PI / 2.f;
        pitch = -roll + atan2(v.x * v.y - w * v.z, v.x * v.z + w * v.y);

    } else if (test == -1)
    {

        roll = atan2(v.x * v.y + w * v.z, 0.5f - (v.y * v.y + v.z * v.z));
        yaw = M_PI / 2.f;
        pitch = roll + atan2(v.x * v.y - w * v.z, v.x * v.z + w * v.y);
    }

    pitch = AngleConverter::ToDegrees(pitch);
    yaw = AngleConverter::ToDegrees(yaw);
    roll = AngleConverter::ToDegrees(roll);

    EulerAngles euler(pitch, yaw, roll);
    return euler;
}