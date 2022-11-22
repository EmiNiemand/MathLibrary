//
// Created by masterktos on 22.11.22.
//

#ifndef MATHGRAPH2_VECTOR3_H
#define MATHGRAPH2_VECTOR3_H


#include <iostream>
#include <cmath>

class Vector3 {
private:
    float x, y, z;
public:
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(Vector3 p1, Vector3 p2);
    Vector3(const Vector3 &v);
    ~Vector3();

    void operator+=(const Vector3& v);
    void operator-=(const Vector3& v);
    void operator*=(const float& s);
    void operator/=(const float& s);

    Vector3 operator+(const Vector3& v);
    Vector3 operator-(const Vector3& v);
    Vector3 operator*(const float& s);
    Vector3 operator/(const float& s);

    void add(Vector3 v);
    void sub(Vector3 v);
    void mul(float s);
    void div(float s);

    float length() const;
    void normalize();
    static Vector3 dot(Vector3& v1, Vector3& v2);
    static float dotProduct(Vector3& v1, Vector3& v2);
    static Vector3 cross(Vector3& v1, Vector3& v2);

    static float calcAngle(Vector3& v1, Vector3& v2);

    std::string toString();
};



#endif //MATHGRAPH2_VECTOR3_H
