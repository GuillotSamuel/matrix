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
    os << "[";
    for (size_t i = 0; i < matrix.data_matrix.size(); ++i)
    {
        os << "[";
        const auto &row = matrix.data_matrix[i];
        for (size_t j = 0; j < row.size(); ++j)
        {
            os << std::fixed << std::setprecision(1) << row[j];
            if (j < row.size() - 1)
                os << ", ";
        }
        os << "]";
        if (i < matrix.data_matrix.size() - 1)
            os << "\n";
    }
    os << "]";
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

template <typename K>
void Matrix<K>::print_mat() const
{
    std::cout << "[\n";

    for (size_t i = 0; i < this->data_matrix.rows(); ++i) {
        std::cout << " [";

        for (size_t j = 0; j < this->data_matrix.cols(); ++j) {
            std::cout << this->data_matrix.data[i][j];
            if (j < this->data_matrix.cols() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
    std::cout << "]\n";
}

template <typename K>
Matrix<K> Matrix<K>::mul_mat(const Matrix<K> &mat) {
    if (this->numCols() != mat.numRows())
        throw std::invalid_argument("Matrix dimensions are not compatible with each other for multiplication.");

    std::vector<std::vector<K>> result(this->numRows(), std::vector<K>(mat.numCols(), 0));

    for (size_t i = 0; i < this->numRows(); i++) {
        for (size_t j = 0; j < mat.numCols(); j++) {
            for (size_t k = 0; k < this->numCols(); k++) {
                result[i][j] += this->data_matrix[i][k] * mat.data_matrix[k][j];
            }
        }
    }

    return Matrix(result);
}

template <typename K>
Vector<K> Matrix<K>::mul_vec(const Vector<K> &vec) {
    if (this->numCols() != vec.data_vector.size())
        throw std::invalid_argument("Matrix dimensions are not compatible with vector dimensions for multiplication.");

    std::vector<K> result(this->numRows(), 0);

    for (size_t i = 0; i < this->numRows(); i++) {
        for (size_t j = 0; j < this->numCols(); j++) {
            result[i] += this->data_matrix[i][j] * vec.data_vector[j];
        }
    }

    return Vector<K>({result});
}

template <typename K>
K Matrix<K>::trace()
{
    if (numRows() != numCols())
        throw std::invalid_argument("Matrix is not a square. The trace is not defined.");

    K result = K();

    for (size_t i = 0; i < numRows(); ++i)
    {
        result += data_matrix[i][i];
    }

    return result;
}

template <typename K>
Matrix<K> Matrix<K>::transpose()
{
    std::vector<std::vector<K>> transposed_data(this->numCols(), std::vector<K>(this->numRows()));

    for (size_t i = 0; i < this->numRows(); ++i) {
        for (size_t j = 0; j < this->numCols(); ++j) {
            transposed_data[j][i] = this->data_matrix[i][j];
        }
    }

    return Matrix<K>(transposed_data);
}
