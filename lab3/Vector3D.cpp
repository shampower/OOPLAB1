#include "Vector3D.h"

#include <cmath>

#include <stdexcept>


namespace {
    const double EPS = 1e-9;
}

int Vector3D::createdCount = 0;

Vector3D::Vector3D() : x(0), y(0), z(0), lengthCalls(0) {
    ++createdCount;
}

Vector3D::Vector3D(double value) : x(value), y(value), z(value), lengthCalls(0) {
    ++createdCount;
}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z), lengthCalls(0) {
    ++createdCount;
}

Vector3D::Vector3D(const Vector3D& other)
    : x(other.x), y(other.y), z(other.z), lengthCalls(0) {
    ++createdCount;
}

Vector3D::~Vector3D() {
    std::cout << "  [деструктор] уничтожен вектор " << *this << '\n';
}

std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
    out << '(' << v.x << ", " << v.y << ", " << v.z << ')';
    return out;
}

double Vector3D::length() const {
    ++lengthCalls;
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
}

double Vector3D::getX() const { return x; }
double Vector3D::getY() const { return y; }
double Vector3D::getZ() const { return z; }

int Vector3D::getLengthCalls() const {
    return lengthCalls;
}

int Vector3D::getCreatedCount() {
    return createdCount;
}

Vector3D& Vector3D::operator++() {
    x *= 1.01;
    y *= 1.01;
    z *= 1.01;
    return *this;
}

Vector3D Vector3D::operator++(int) {
    Vector3D old(*this);
    ++(*this);
    return old;
}

Vector3D& Vector3D::operator--() {
    x *= 0.99;
    y *= 0.99;
    z *= 0.99;
    return *this;
}

Vector3D Vector3D::operator--(int) {
    Vector3D old(*this);
    --(*this);
    return old;
}


Vector3D& Vector3D::operator+=(const Vector3D& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3D& Vector3D::operator*=(double k) {
    x *= k;
    y *= k;
    z *= k;
    return *this;
}

Vector3D& Vector3D::operator/=(double k) {
    if (k == 0.0) {
        throw std::invalid_argument("деление вектора на ноль");
    }
    x /= k;
    y /= k;
    z /= k;
    return *this;
}


Vector3D operator+(Vector3D lhs, const Vector3D& rhs) {
    lhs += rhs;
    return lhs;
}

Vector3D operator-(Vector3D lhs, const Vector3D& rhs) {
    lhs -= rhs;
    return lhs;
}

Vector3D operator*(Vector3D lhs, double k) {
    lhs *= k;
    return lhs;
}

Vector3D operator*(double k, Vector3D rhs) {
    rhs *= k;
    return rhs;
}

Vector3D operator/(Vector3D lhs, double k) {
    lhs /= k;
    return lhs;
}


bool operator<(const Vector3D& a, const Vector3D& b) {
    return a.length() < b.length() - EPS;
}

bool operator>(const Vector3D& a, const Vector3D& b) {
    return b < a;
}

bool operator<=(const Vector3D& a, const Vector3D& b) {
    return !(b < a);
}

bool operator>=(const Vector3D& a, const Vector3D& b) {
    return !(a < b);
}

bool operator==(const Vector3D& a, const Vector3D& b) {
    return std::fabs(a.length() - b.length()) <= EPS;
}

bool operator!=(const Vector3D& a, const Vector3D& b) {
    return !(a == b);
}