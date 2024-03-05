//
// Created by Arshia Bakhshayesh on 3/4/2024.
//


#pragma once

#include <ostream>

class Vector3D;

/**
 * @brief A 2D vector class representing a point or direction in a 2D space.
 */
class Vector2D {
public:

    float x, y;

    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& vec) const;
    Vector2D& operator+=(const Vector2D& vec);

    Vector2D operator-(const Vector2D& vec) const;
    Vector2D& operator-=(const Vector2D& vec);

    Vector2D operator*(float f) const;
    Vector2D& operator*=(float f);

    Vector2D operator/(float f) const;
    Vector2D& operator/=(float f);

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);

    /**
     * @brief Computes and returns the magnitude (length) of the vector.
     * @return The magnitude of the vector.
     */
    float Magnitude() const;

    /**
     * @brief Normalizes the vector, making it a unit vector.
     */
    void Normalize();
};



