//
// Created by szymo on 17/12/2022.
//

#include "../lib/Plane.h"
#include "../lib/Line.h"

Plane::Plane(float a, float b, float c, float d) : a(a), b(b), c(c), d(d) {
    normal = Vector3(a, b, c);
}

Line Plane::IntersectionLineWithPlane(Plane plane) {
    Line result;

    result.direction = Vector3::cross(normal, plane.normal);
    float directionLength = std::pow(result.direction.length(), 2);

    if (directionLength == 0.f) {
        throw NoIntersectionException();
    }

    float value = (plane.b * d - b * plane.d) / (b * plane.c - plane.b * c);

    result.point.x = 0;
    result.point.y = (-c * value - d) / b;
    result.point.z = value;

    return result;
}

float Plane::CalcAngleWithPlane(Plane plane) {
    return Vector3::calcAngle(normal, plane.normal);
}

std::string Plane::toString() {
    return std::string("[" + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "]");
}
