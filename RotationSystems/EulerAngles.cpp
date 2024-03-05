//
// Created by Arshia Bakhshayesh on 3/4/2024.
//

#include "EulerAngles.h"
#include "Quaternion.h"
#include "../Utilities/AngleConverter.h"
#include <cmath>

EulerAngles EulerAngles::operator+(const EulerAngles& other) const
{
    return EulerAngles(pitch + other.pitch, yaw + other.yaw, roll + other.roll);
}

EulerAngles& EulerAngles::operator+=(const EulerAngles& other)
{
    pitch += other.pitch; yaw += other.yaw; roll += other.roll;
    return *this;
}

EulerAngles EulerAngles::operator-(const EulerAngles& other) const
{
    return EulerAngles(pitch - other.pitch, yaw - other.yaw, roll - other.roll);
}

EulerAngles& EulerAngles::operator-=(const EulerAngles& other)
{
    pitch -= other.pitch; yaw -= other.yaw; roll -= other.roll;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const EulerAngles& angles)
{
    os << "Pitch: " << angles.pitch << ", Yaw: " << angles.yaw << ", Roll: " << angles.roll;
    return os;
}

Quaternion EulerAngles::ToQuaternion()
{
    // Angles are in radians
    const float lpitch = AngleConverter::ToRadians(pitch) / 2;
    const float lyaw = AngleConverter::ToRadians(yaw) / 2;
    const float lroll = AngleConverter::ToRadians(roll) / 2;

    Quaternion q;
    q.w = cos(lroll) * cos(lyaw) * cos(lpitch) + sin(lroll) * sin(lyaw) * sin(lpitch);
    q.v.x = cos(lroll) * cos(lyaw) * sin(lpitch) - sin(lroll) * sin(lyaw) * cos(lpitch);
    q.v.y = cos(lroll) * sin(lyaw) * cos(lpitch) + sin(lroll) * cos(lyaw) * sin(lpitch);
    q.v.z = sin(lroll) * cos(lyaw) * cos(lpitch) - cos(lroll) * sin(lyaw) * sin(lpitch);

    return q;
}