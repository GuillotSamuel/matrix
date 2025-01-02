#include "vector.hpp"

template <typename K>
Vector<K>::Vector(std::vector<K> data): data_vector(std::move(data)) {}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : data_vector(list) {}

template <typename K>
Vector<K>::Vector(size_t size, const K &value) : data_vector(size, value) {}

template <typename K>
Vector<K>::~Vector() {}

template <typename K>
void Vector<K>::check_validity(const Vector<K> &other)
{
    if (this->data_vector.empty() || other.data_vector.empty())
        throw std::invalid_argument("Vectors must not be empty");

    if (this->data_vector.size() != other.data_vector.size())
        throw std::invalid_argument("Vectors must have the same size");
}

template <typename K>
Vector<K> &Vector<K>::operator+=(const Vector<K> &other)
{
    check_validity(other);

    for (size_t i = 0; i < this->data_vector.size(); i++)
        this->data_vector[i] += other.data_vector[i];

    return *this;
}

template <typename K>
Vector<K> &Vector<K>::operator-=(const Vector<K> &other)
{
    check_validity(other);

    for (size_t i = 0; i < this->data_vector.size(); i++)
        this->data_vector[i] -= other.data_vector[i];

    return *this;
}

template <typename K>
Vector<K> &Vector<K>::operator*=(const K &scalar)
{
    for (size_t i = 0; i < this->data_vector.size(); i++)
        this->data_vector[i] *= scalar;

    return *this;
}

template <typename K>
Vector<K> Vector<K>::operator+(const Vector<K> &other)
{
    check_validity(other);

    Vector result(this->data_vector.size());

    for (size_t i = 0; i < this->data_vector.size(); i++)
        result.data_vector[i] = this->data_vector[i] + other.data_vector[i];

    return result;
}

template <typename K>
Vector<K> Vector<K>::operator-(const Vector<K> &other)
{
    check_validity(other);

    Vector result(this->data_vector.size());

    for (size_t i = 0; i < this->data_vector.size(); i++)
        result.data_vector[i] = this->data_vector[i] - other.data_vector[i];

    return result;
}

template <typename K>
Vector<K> Vector<K>::operator*(const K &scalar) const
{
    Vector<K> result(*this);
    result *= scalar;
    return result;
}

template <typename K>
Vector<K> &Vector<K>::add(const Vector<K> &vector)
{
    return (*this += vector);
}

template <typename K>
Vector<K> &Vector<K>::sub(const Vector<K> &vector)
{
    return (*this -= vector);
}

template <typename K>
Vector<K> &Vector<K>::scl(const K &scalar)
{
    return (*this *= scalar);
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const Vector<K> &vector)
{
    os << "[";
    for (size_t i = 0; i < vector.data_vector.size(); i++)
    {
        os << std::fixed << std::setprecision(1) << vector.data_vector[i];
        if (i != vector.data_vector.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

template <typename K>
Vector<K> linear_combination(const std::vector<Vector<K>> &u, const std::vector<K> &coefs)
{
    if (u.size() != coefs.size())
        throw std::invalid_argument("There should be the same number of coefficients and vectors.");

    size_t vector_size = u[0].data_vector.size();
    for (const auto &vec : u)
    {
        if (vec.data_vector.size() != vector_size)
            throw std::invalid_argument("All vectors must have the same size.");
    }

    Vector<K> result(std::vector<K>(vector_size, 0));

    for (size_t i = 0; i < u.size(); i++)
    {
        const auto &vec = u[i];
        K coef = coefs[i];
        
        for (size_t j = 0; j < vector_size; j++)
        {
            result.data_vector[j] += vec.data_vector[j] * coef;
        }
    }

    return result;
}

template <typename V>
Vector<V> lerp(const Vector<V> &u, const Vector<V> &v, V t)
{
    if (u.data_vector.size() != v.data_vector.size())
        throw std::invalid_argument("Vectors must be the same size.");

    std::vector<V> result;
    for (size_t i = 0; i < u.data_vector.size(); i++)
        result.push_back(u.data_vector[i] + t * (v.data_vector[i] - u.data_vector[i]));

    return Vector<V>(result);
}

template <typename K>
K Vector<K>::dot(const Vector<K> &v) const
{
    if (this->data_vector.size() != v.data_vector.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    K result = 0;
    for (size_t i = 0; i < this->data_vector.size(); ++i) {
        result += this->data_vector[i] * v.data_vector[i];
    }

    return result;
}
template <typename K>
K Vector<K>::norm_1() const
{
    K result = 0;

    for (const K &value : this->data_vector)
        result += std::abs(value);

    return result;
}

template <typename K>
K Vector<K>::norm() const
{
    K result = 0;

    for (const K &value : this->data_vector)
        result += value * value;

    return std::sqrt(result);
}

template <typename K>
K Vector<K>::norm_inf() const
{
    K max_value = 0;
    
    for (const K &value : this->data_vector)
        max_value = std::max(max_value, std::abs(value));

    return max_value;
}

template <typename K>
float angle_cos(const Vector<K> &u, const Vector<K> &v)
{
    if (u.data_vector.size() != v.data_vector.size())
        throw std::invalid_argument("Vectors must have the same size.");
    
    float dot_product = 0;
    for (size_t i = 0; i < u.data_vector.size(); i++)
        dot_product += u.data_vector[i] * v.data_vector[i];
    
    float norm_u = u.norm();
    float norm_v = v.norm();

    if (norm_u == 0 || norm_v == 0)
        throw std::invalid_argument("Undefined behavior for zero vectors.");
    
    return (dot_product / (norm_u * norm_v));
}

template <typename K>
Vector<K> cross_product(const Vector<K> &u, const Vector<K> &v)
{
    if (u.data_vector.size() != 3 || v.data_vector.size() != 3)
        throw std::invalid_argument("Vector must contain 3 values only (3D).");
    
    K x = u.data_vector[1] * v.data_vector[2] - u.data_vector[2] * v.data_vector[1];
    K y = u.data_vector[2] * v.data_vector[0] - u.data_vector[0] * v.data_vector[2];
    K z = u.data_vector[0] * v.data_vector[1] - u.data_vector[1] * v.data_vector[0];

    return Vector<K>({x, y, z});
}

template <typename K>
void Vector<K>::print_vec() const
{
    std::cout << "[";
    for (size_t i = 0; i < this->data_vector.size(); ++i) {
        std::cout << this->data_vector.data[i];
        if (i < this->data_vector.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
