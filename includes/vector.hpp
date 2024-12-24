#pragma once

#include "utils.hpp"

template <typename T>
class Vector {
    private:
        std::vector<T> data_vector;

    public:
        Vector(std::vector<T> data);
        ~Vector();

        Vector operator+(const Vector &other);
        Vector operator-(const Vector &other);
        Vector operator*(const T &scalar) const;
        Vector &operator+=(const Vector &other);
        Vector &operator-=(const Vector &other);
        Vector &operator*=(const T &scalar);
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Vector<U> &vector);

        Vector &add(const Vector<T> &vector);
        Vector &sub(const Vector<T> &vector);
        Vector &scl(const T &vector);

        void check_validity(const Vector<T> &other);
};

#include "vector.tpp"
