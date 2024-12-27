#pragma once

#include "utils.hpp"

template <typename K>
class Vector {
    public:
        std::vector<K> data_vector;

        Vector(std::vector<K> data);
        Vector(std::initializer_list<K> list);
        Vector(size_t size, const K &value);
        ~Vector();

        Vector operator+(const Vector &other);
        Vector operator-(const Vector &other);
        Vector operator*(const K &scalar) const;
        Vector &operator+=(const Vector &other);
        Vector &operator-=(const Vector &other);
        Vector &operator*=(const K &scalar);
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Vector<U> &vector);

        Vector &add(const Vector<K> &vector);
        Vector &sub(const Vector<K> &vector);
        Vector &scl(const K &vector);

        void check_validity(const Vector<K> &other);
        Vector linear_combination(const std::vector<Vector<K>> &u, const std::vector<K> &coefs);

        auto begin() { return data_vector.begin(); }
        auto end() { return data_vector.end(); }
        auto begin() const { return data_vector.begin(); }
        auto end() const { return data_vector.end(); }
};

#include "vector.tpp"
