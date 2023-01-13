#pragma once

//typedef Vector3<double> vector3;
template<typename T>

class Vector3
{
public:
    T x;
    T y;
    T z;

    constexpr Vector3<T>(T X = 0, T Y = 0,T Z=0 ) noexcept : x(X), y(Y),z(Z)
    {

    }
    void setX(const T& X) {
        this->x = X;
    }
    void setY(const T& Y) {
        this->y = Y;
    }
    void setZ(const T& Z) {
        this->z = Z;
    }
    T getX() const {
        return this->x;
    }
    T getY() const {
        return this->y;
    }
    T getZ() const {
        return this->z;
    }
    void setXYZ(const T& X, const T& Y, const T& Z) {
        this->x = X;
        this->y = Y;
        this->z = Z;
    }
    void getXYZ(T& X, T& Y, T& Z) {
        X = this->x;
        Y = this->y;
        Z = this->z;
    }

    constexpr Vector3<T>& operator+=(const Vector3<T>& other) noexcept
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    constexpr Vector3<T>& operator/=(T t) noexcept
    {
        x /= t;
        y /= t;
        return *this;
    }
};
template<typename T>
constexpr Vector3<T> operator+(Vector3<T> lhs, const Vector3<T>& rhs) noexcept
{
    lhs += rhs;
    return lhs;
}

template<typename T>
constexpr Vector3<T> operator/(Vector3<T> vec, T t) noexcept
{
    vec /= t;
    return vec;
}