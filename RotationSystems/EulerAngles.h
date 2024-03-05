//
// Created by Arshia Bakhshayesh on 3/4/2024.
//

#pragma once

#include <iostream>

class Quaternion;

class EulerAngles {
public:

    /** The pitch angle (rotation around X-axis). */
    float pitch;

    /** The yaw angle (rotation around Y-axis). */
    float yaw;

    /** The roll angle (rotation around Z-axis). */
    float roll;

    EulerAngles() : pitch(0.0f), yaw(0.0f), roll(0.0f) {};
    EulerAngles(float pitch, float yaw, float roll) : pitch(pitch), yaw(yaw), roll(roll) {};

    /** The binary and compound operators. */
    EulerAngles operator+(const EulerAngles& other) const;
    EulerAngles& operator+=(const EulerAngles& other);
    EulerAngles operator-(const EulerAngles& other) const;
    EulerAngles& operator-=(const EulerAngles& other);

    friend std::ostream& operator<<(std::ostream& os, const EulerAngles& angles);

    /**
     * @brief Converts the Euler angles to a quaternion.
     * @return The quaternion corresponding to the Euler angles.
     */
    Quaternion ToQuaternion();
};


