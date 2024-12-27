#pragma once

#include "utils.hpp"

template <typename K>
class Matrix {
    private:
        std::vector<std::vector<K>> data_matrix;

    public:
        Matrix(const std::vector<std::vector<K>> &data);
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

        void check_validity(const Matrix<K> &other);
};

#include "matrix.tpp"
