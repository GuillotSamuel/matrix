#pragma once

#include "utils.hpp"
#include "vector.hpp"

template <typename K>
class Matrix {
    public:
        std::vector<std::vector<K>> data_matrix;

        /* Contructors and destructor */
        Matrix(const std::vector<std::vector<K>> &data);
        Matrix(std::initializer_list<std::initializer_list<K>> init);
        ~Matrix();

        /* Overload operators */
        Matrix operator+(const Matrix &other);
        Matrix operator-(const Matrix &other);
        Matrix operator*(const K &scalar) const;
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix &operator*=(const K &scalar);

        /* Member functions */
        Matrix &add(const Matrix<K> &matrix);
        Matrix &sub(const Matrix<K> &matrix);
        Matrix &scl(const K &matrix);

        /* Interpolation function */
        template <typename V>
        Matrix lerp(const Matrix<V> &u, const Matrix<V> &v, V t);

        /* Matrix operations */
        Matrix<K> mul_mat(const Matrix<K> &mat);
        Vector<K> mul_vec(const Vector<K> &vec);

        /* Utils functions */
        void check_validity(const Matrix<K> &other);

        /* Accessors */
        size_t numRows() const { return data_matrix.size(); }
        size_t numCols() const { return data_matrix.empty() ? 0 : data_matrix[0].size(); }

        /* Output functions */
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &matrix);
        void print_mat() const;
};

#include "matrix.tpp"
