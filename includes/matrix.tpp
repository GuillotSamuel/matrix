#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> &data)
{
    data_matrix = data;
}

template <typename T>
Matrix<T>::~Matrix() {}

template <typename T>
void Matrix<T>::check_validity(const Matrix<T> &other)
{
    if (data_matrix.size() != other.data_matrix.size() ||
        (data_matrix.size() > 0 && data_matrix[0].size() != other.data_matrix[0].size()))
    {
        throw std::invalid_argument("Matrix dimensions do not match!");
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other)
{
    this->check_validity(other);
    Matrix<T> result(*this);

    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            result.data_matrix[i][j] += other.data_matrix[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &other)
{
    this->check_validity(other);
    Matrix<T> result(*this);

    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            result.data_matrix[i][j] -= other.data_matrix[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar) const
{
    Matrix<T> result(*this);

    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            result.data_matrix[i][j] *= scalar;
        }
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &other)
{
    this->check_validity(other);

    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            data_matrix[i][j] += other.data_matrix[i][j];
        }
    }

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &other)
{
    this->check_validity(other);

    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            data_matrix[i][j] -= other.data_matrix[i][j];
        }
    }

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{
    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            data_matrix[i][j] *= scalar;
        }
    }

    return *this;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const Matrix<U> &matrix)
{
    for (const auto &row : matrix.data_matrix)
    {
        os << "[";
        size_t row_size = row.size();
        for (size_t i = 0; i < row_size; ++i)
        {
            os << std::fixed << std::setprecision(1) << row[i];
            if (i < row_size - 1)
                os << ", ";
        }
        os << "]" << std::endl;
    }
    return os;
}

template <typename T>
Matrix<T> &Matrix<T>::add(const Matrix<T> &matrix)
{
    return *this += matrix;
}

template <typename T>
Matrix<T> &Matrix<T>::sub(const Matrix<T> &matrix)
{
    return *this -= matrix;
}

template <typename T>
Matrix<T> &Matrix<T>::scl(const T &scalar)
{
    return *this *= scalar;
}
