//
// Created by Arshia Bakhshayesh on 3/1/2024.
//

#pragma once

#include "../Vectors/Vector3D.h"

class EulerAngles;

/**
 * @brief A quaternion class representing a rotation in 3D space.
 */
class Quaternion
{
public:

    /** The scalar component of the quaternion. */
    float w;
    /** The vector component of the quaternion. */
    Vector3D v;

    /**
     * @brief Default constructor initializing the quaternion to the identity quaternion.
     */
    Quaternion(): w(0), v(Vector3D(0, 0, 0)) {};

    /**
     * @brief Constructor initializing the quaternion with specified components.
     * @param w The scalar component.
     * @param x The x-component of the vector.
     * @param y The y-component of the vector.
     * @param z The z-component of the vector.
     */
    Quaternion(float w, float x, float y, float z): w(w) { v.x = x; v.y = y; v.z = z; };

    /**
     * @brief Constructor initializing the quaternion from an angle-axis representation.
     * @param angle The rotation angle.
     * @param axis The rotation axis.
     */
    Quaternion(float angle, const Vector3D& axis): w(angle), v(axis) {};

    Quaternion operator*(const Quaternion& q) const;
    Quaternion operator*(float f) const;
    void operator*=(const Quaternion& q);
    void operator*=(float f);
    void operator+=(const Quaternion& q);
    Quaternion operator+(const Quaternion& q) const;
    void operator-=(const Quaternion& q);
    Quaternion operator-(const Quaternion& q) const;

    /** Overloaded stream insertion operator for Quaternion. */
    friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);

    /** Calculates and returns the conjugate of the quaternion. */
    Quaternion Conjugate() const;

    /** Calculates and returns the magnitude (norm) of the quaternion. */
    float Magnitude() const;

    /** Normalizes the quaternion, making it a unit quaternion. */
    Quaternion Normalize() const;

    /** Converts the quaternion to a unit-norm quaternion (special form). */
    void ToUnitNormQuaternion();

    /** Calculates and returns the inverse of the quaternion. */
    Quaternion Inverse();

    /**
     * @brief Converts the quaternion to Euler angles.
     * @return The Euler angles corresponding to the quaternion.
     */
    EulerAngles ToEulerAngles();
};
