#include <iostream>
#include "Vectors/Vector3D.h"
#include "RotationSystems/Quaternion.h"
#include "RotationSystems/EulerAngles.h"

int main()
{
    Vector3D Vec1(23, -2, 7);
    Vector3D Vec2(-23, 2, -7);

    Vec2 -= Vec1;
    std::cout << "Coordinates: " << Vec2;

    Vec2 = Vec2.RotateZ(90.f);
    std::cout << ", Rotated around z-axis: " << Vec2 << std::endl;

    Vector3D Vec3{1, 2, 1};
    Vector3D Vec4{2, 1, 3};
    std::cout << "First Vector: " << Vec3 << ", Second Vector: " << Vec4 << ": "
    << "Dot product: " << Vec3Operator::Dot(Vec3, Vec4) << std::endl;

    Vector3D Vec5{-1, 1, 3};
    Vector3D Vec6{2, -1, 3};
    Vector3D Vec7{ Vec3Operator::Cross(Vec5, Vec6) };
    std::cout << "First Vector: " << Vec5 << ", Second Vector: " << Vec6 << ": Cross product: " << Vec7 << std::endl;


    Vector3D v(10, 10, 10);
    Vector3D axis(1, 0, 0);

    Vector3D RotatedVector = v.RotateAroundAxis(90, axis);
    std::cout << "Vector: " << v << ", Axis: " << axis << ", Rotated Vector: " << RotatedVector << std::endl;

    EulerAngles EA1(50, 10, 0);
    std::cout << "EulerAngles: " << EA1 << ", Quaternion: " << EA1.ToQuaternion() << std::endl;

    Quaternion q1(EA1.ToQuaternion());
    std::cout << "Quaternion: " << q1 << ", EulerAngles: " << q1.ToEulerAngles() << std::endl;

    return 0;
}
