#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Vector {
    private:
        std::vector<T> data;

    public:
        Vector(std::vector<T> data);
        ~Vector();

        Vector operator+(const Vector &other);
        Vector operator-(const Vector &other);
        Vector operator*(const Vector &other);
        Vector &operator+=(const Vector &other);
        Vector &operator-=(const Vector &other);
        Vector &operator*=(const Vector &other);
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Vector<U> &vector);

        Vector &add(const Vector<T> &vector);
        Vector &substract(const Vector<T> &vector);
        Vector &scale(const Vector <T> &vector);

        void check_validity(const Vector<T> &other);
};

#include "vector.tpp"
