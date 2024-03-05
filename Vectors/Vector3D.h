//
// Created by Arshia Bakhshayesh on 3/1/2024.
//

#pragma once

#include <ostream>

class Quaternion;

class Vector3D
{
public:

    /** Initializing a vector with default values, or the precise coordinates if provided. */
    Vector3D(): x(0), y(0), z(0) {};
    Vector3D(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {};

    /** The addition operations, both binary and compound. */
    Vector3D operator+(const Vector3D& vec) const;
    Vector3D operator+(float f) const;
    Vector3D& operator+=(const Vector3D& vec);
    Vector3D& operator+=(float f);

    /** The subtraction operations, both binary and compound. */
    Vector3D operator-(const Vector3D& vec) const;
    Vector3D operator-(float f) const;
    Vector3D& operator-=(const Vector3D& vec);
    Vector3D& operator-=(float f);

    /** The division operations, both binary and compound. */
    Vector3D operator/(const Vector3D& vec) const;
    Vector3D operator/(float f) const;
    Vector3D& operator/=(const Vector3D& vec);
    Vector3D& operator/=(float f);

    /** The multiplication operations, both binary and compound. */
    Vector3D operator*(float f) const;
    Vector3D& operator*=(float f);

    /** Unary negation operator returns a new Vector3D with negated component. */
    Vector3D operator-() const;

    /** Overloaded stream insertion operator for Vector3D. */
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec);

    /** The sacred coordinates of the vector. */
    float x, y, z;

    /**
    * @brief Augments the vector by scaling its components.
    * @param scale The factor by which the vector is to be scaled.
    */
    void ScalarMultiplication(float scale);

    /** Returns the vector's magnitude. */
    float Magnitude() const;

    /** Normalizes the vector, making it a unit vector. */
    void Normalize();

    /**
     * @brief Rotates the vector around a specified axis.
     * @param angle The angle of rotation.
     * @param axis The axis around which the rotation occurs.
     * @return The rotated vector.
     */
    Vector3D RotateAroundAxis(float angle, const Vector3D& axis);

    /** Rotate the vector around x-axis. */
    Vector3D RotateX(float angle);

    /** Rotate the vector around y-axis. */
    Vector3D RotateY(float angle);

    /** Rotate the vector around z-axis. */
    Vector3D RotateZ(float angle);
};

/**
 * @brief A namespace containing operations related to 3D vectors.
 */
namespace Vec3Operator
{
    /**
     * @brief Calculates and returns the dot product of two vectors.
     * @param vec1 The first vector.
     * @param vec2 The second vector.
     * @return The dot product of the two vectors.
     */
    float Dot(const Vector3D& vec1, const Vector3D& vec2);

    /**
     * @brief Calculates and returns the cross product of two vectors.
     * @param vec1 The first vector.
     * @param vec2 The second vector.
     * @return The cross product of the two vectors.
     */
    Vector3D Cross(const Vector3D& vec1, const Vector3D& vec2);
}