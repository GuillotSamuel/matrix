#include "matrix.hpp"

template <typename K>
Matrix<K>::Matrix(const std::vector<std::vector<K>> &data)
{
    data_matrix = data;
}

template <typename K>
Matrix<K>::Matrix(std::initializer_list<std::initializer_list<K>> init) {
    for (auto& row : init) {
        data_matrix.push_back(std::vector<K>(row));
    }
}

template <typename K>
Matrix<K>::~Matrix() {}

template <typename K>
void Matrix<K>::check_validity(const Matrix<K> &other)
{
    if (data_matrix.size() != other.data_matrix.size() ||
        (data_matrix.size() > 0 && data_matrix[0].size() != other.data_matrix[0].size()))
    {
        throw std::invalid_argument("Matrix dimensions do not match!");
    }
}

template <typename K>
Matrix<K> Matrix<K>::operator+(const Matrix<K> &other)
{
    this->check_validity(other);
    Matrix<K> result(*this);

    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            result.data_matrix[i][j] += other.data_matrix[i][j];
        }
    }

    return result;
}

template <typename K>
Matrix<K> Matrix<K>::operator-(const Matrix<K> &other)
{
    this->check_validity(other);
    Matrix<K> result(*this);

    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            result.data_matrix[i][j] -= other.data_matrix[i][j];
        }
    }

    return result;
}

template <typename K>
Matrix<K> Matrix<K>::operator*(const K &scalar) const
{
    Matrix<K> result(*this);

    for (size_t i = 0; i < data_matrix.size(); i++)
    {
        for (size_t j = 0; j < data_matrix[i].size(); j++)
        {
            result.data_matrix[i][j] *= scalar;
        }
    }

    return result;
}

template <typename K>
Matrix<K> &Matrix<K>::operator+=(const Matrix<K> &other)
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

template <typename K>
Matrix<K> &Matrix<K>::operator-=(const Matrix<K> &other)
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

template <typename K>
Matrix<K> &Matrix<K>::operator*=(const K &scalar)
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

template <typename K>
Matrix<K> &Matrix<K>::add(const Matrix<K> &matrix)
{
    return *this += matrix;
}

template <typename K>
Matrix<K> &Matrix<K>::sub(const Matrix<K> &matrix)
{
    return *this -= matrix;
}

template <typename K>
Matrix<K> &Matrix<K>::scl(const K &scalar)
{
    return *this *= scalar;
}

template <typename V>
Matrix<V> lerp(const Matrix<V>& u, const Matrix<V>& v, V t)
{
    if (u.numRows() != v.numRows() || u.numCols() != v.numCols())
        throw std::invalid_argument("Matrices must be of the same size.");

    std::vector<std::vector<V>> result;
    for (size_t i = 0; i < u.numRows(); ++i) {
        std::vector<V> row;
        for (size_t j = 0; j < u.numCols(); ++j) {
            row.push_back(u.data_matrix[i][j] + t * (v.data_matrix[i][j] - u.data_matrix[i][j]));
        }
        result.push_back(row);
    }

    return Matrix<V>(result);
}
