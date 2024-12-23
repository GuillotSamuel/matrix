#include "vector.hpp"


template <typename T>
Vector<T>::Vector(std::vector<T> data): data(std::move(data))
{
}

template <typename T>
Vector<T>::~Vector() {}

template <typename T>
void Vector<T>::check_validity(const Vector<T> &other)
{
    if (this->data.empty() || other.data.empty())
        throw std::invalid_argument("Vectors must not be empty");

    if (this->data.size() != other.data.size())
        throw std::invalid_argument("Vectors must have the same size");
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &other)
{
    check_validity(other);

    for (size_t i = 0; i < this->data.size(); i++)
        this->data[i] += other.data[i];

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator-=(const Vector<T> &other)
{
    check_validity(other);

    for (size_t i = 0; i < this->data.size(); i++)
        this->data[i] -= other.data[i];

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator*=(const Vector<T> &other)
{
    check_validity(other);

    for (size_t i = 0; i < this->data.size(); i++)
        this->data[i] *= other.data[i];

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other)
{
    check_validity(other);

    Vector result(this->data.size());

    for (size_t i = 0; i < this->data.size(); i++)
        result.data[i] = this->data[i] + other.data[i];

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &other)
{
    check_validity(other);

    Vector result(this->data.size());

    for (size_t i = 0; i < this->data.size(); i++)
        result.data[i] = this->data[i] - other.data[i];

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const Vector<T> &other)
{
    check_validity(other);

    Vector result(this->data.size());

    for (size_t i = 0; i < this->data.size(); i++)
        result.data[i] = this->data[i] * other.data[i];

    return result;
}

template <typename T>
Vector<T> &Vector<T>::add(const Vector<T> &vector)
{
    return (*this += vector);
}

template <typename T>
Vector<T> &Vector<T>::substract(const Vector<T> &vector)
{
    return (*this -= vector);
}

template <typename T>
Vector<T> &Vector<T>::scale(const Vector<T> &vector)
{
    return (*this *= vector);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vector)
{
    os << "[";
    for (size_t i = 0; i < vector.data.size(); i++)
    {
        os << vector.data[i];
        if (i != vector.data.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
