#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D {
private:
    double x;
    double y;
    double z;
    mutable int lengthCalls;

    static int createdCount;

public:
    Vector3D();
    explicit Vector3D(double value);
    Vector3D(double x, double y, double z);
    Vector3D(const Vector3D& other);
    Vector3D& operator=(const Vector3D& other) = default;
    ~Vector3D();
    
    Vector3D& operator++();
    Vector3D operator++(int);
    Vector3D& operator--();
    
    Vector3D& operator+=(const Vector3D& other);
    Vector3D& operator-=(const Vector3D& other);
    Vector3D& operator*=(double k);
    Vector3D& operator/=(double k);
    
    friend Vector3D operator+(Vector3D lhs, const Vector3D& rhs);
    friend Vector3D operator-(Vector3D lhs, const Vector3D& rhs);
    friend Vector3D operator*(Vector3D lhs, double k);
    
    friend bool operator<(const Vector3D& a, const Vector3D& b);
    friend bool operator>(const Vector3D& a, const Vector3D& b);
    friend bool operator<=(const Vector3D& a, const Vector3D& b);
    friend bool operator>=(const Vector3D& a, const Vector3D& b);
    friend bool operator==(const Vector3D& a, const Vector3D& b);
    friend bool operator!=(const Vector3D& a, const Vector3D& b);
    friend Vector3D operator*(double k, Vector3D rhs);
    friend Vector3D operator/(Vector3D lhs, double k);
    Vector3D operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Vector3D& v);

    double length() const;
    double dot(const Vector3D& other) const;
    double getX() const;
    double getY() const;
    double getZ() const;
    int getLengthCalls() const;
    static int getCreatedCount();
};

#endif