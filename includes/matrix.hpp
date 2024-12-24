#pragma once

#include "utils.hpp"

template <typename T>
class Matrix {
    private:
        std::vector<std::vector<T>> data_matrix;

    public:
        Matrix(const std::vector<std::vector<T>> &data);
        ~Matrix();

        Matrix operator+(const Matrix &other);
        Matrix operator-(const Matrix &other);
        Matrix operator*(const T &scalar) const;
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix &operator*=(const T &scalar);
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &matrix);

        Matrix &add(const Matrix<T> &matrix);
        Matrix &sub(const Matrix<T> &matrix);
        Matrix &scl(const T &matrix);

        void check_validity(const Matrix<T> &other);
};

#include "matrix.tpp"
