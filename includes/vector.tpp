#include "vector.hpp"

template <typename T>
Vector<T>::Vector(std::vector<T> data): data_vector(std::move(data)) {}

template <typename T>
Vector<T>::~Vector() {}

template <typename T>
void Vector<T>::check_validity(const Vector<T> &other)
{
    if (this->data_vector.empty() || other.data_vector.empty())
        throw std::invalid_argument("Vectors must not be empty");

    if (this->data_vector.size() != other.data_vector.size())
        throw std::invalid_argument("Vectors must have the same size");
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &other)
{
    check_validity(other);

    for (size_t i = 0; i < this->data_vector.size(); i++)
        this->data_vector[i] += other.data_vector[i];

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator-=(const Vector<T> &other)
{
    check_validity(other);

    for (size_t i = 0; i < this->data_vector.size(); i++)
        this->data_vector[i] -= other.data_vector[i];

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator*=(const T &scalar)
{
    for (size_t i = 0; i < this->data_vector.size(); i++)
        this->data_vector[i] *= scalar;

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other)
{
    check_validity(other);

    Vector result(this->data_vector.size());

    for (size_t i = 0; i < this->data_vector.size(); i++)
        result.data_vector[i] = this->data_vector[i] + other.data_vector[i];

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &other)
{
    check_validity(other);

    Vector result(this->data_vector.size());

    for (size_t i = 0; i < this->data_vector.size(); i++)
        result.data_vector[i] = this->data_vector[i] - other.data_vector[i];

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T &scalar) const
{
    Vector<T> result(*this);
    result *= scalar;
    return result;
}

template <typename T>
Vector<T> &Vector<T>::add(const Vector<T> &vector)
{
    return (*this += vector);
}

template <typename T>
Vector<T> &Vector<T>::sub(const Vector<T> &vector)
{
    return (*this -= vector);
}

template <typename T>
Vector<T> &Vector<T>::scl(const T &scalar)
{
    return (*this *= scalar);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vector)
{
    os << "[";
    for (size_t i = 0; i < vector.data_vector.size(); i++)
    {
        os << vector.data_vector[i];
        if (i != vector.data_vector.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
