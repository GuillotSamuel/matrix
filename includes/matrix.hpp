#pragma once

#include "utils.hpp"

template <typename K>
class Matrix {
    public:
        std::vector<std::vector<K>> data_matrix;

        Matrix(const std::vector<std::vector<K>> &data);
        Matrix(std::initializer_list<std::initializer_list<K>> init);
        ~Matrix();

        Matrix operator+(const Matrix &other);
        Matrix operator-(const Matrix &other);
        Matrix operator*(const K &scalar) const;
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix &operator*=(const K &scalar);

        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &matrix);

        Matrix &add(const Matrix<K> &matrix);
        Matrix &sub(const Matrix<K> &matrix);
        Matrix &scl(const K &matrix);

        size_t numRows() const { return data_matrix.size(); }
        size_t numCols() const { return data_matrix.empty() ? 0 : data_matrix[0].size(); }

        void check_validity(const Matrix<K> &other);

        template <typename V>
        Matrix lerp(const Matrix<V> &u, const Matrix<V> &v, V t);
};

#include "matrix.tpp"
