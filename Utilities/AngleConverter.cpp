//
// Created by Arshia Bakhshayesh on 3/5/2024.
//

#include "AngleConverter.h"
#include <cmath>

float AngleConverter::ToRadians(float degrees)
{
    return degrees * (M_PI / 180.0);
}

float AngleConverter::ToDegrees(float radians)
{
    return radians * (180.0 / M_PI);
}
