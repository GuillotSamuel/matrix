#pragma once

#include "utils.hpp"

template <typename K>
class Vector {
    public:
        std::vector<K> data_vector;

        /* Contructors and destructor */
        Vector(std::vector<K> data);
        Vector(std::initializer_list<K> list);
        Vector(size_t size, const K &value);
        ~Vector();

        /* Overload operators */
        Vector operator+(const Vector &other);
        Vector operator-(const Vector &other);
        Vector operator*(const K &scalar) const;
        Vector &operator+=(const Vector &other);
        Vector &operator-=(const Vector &other);
        Vector &operator*=(const K &scalar);

        /* Member functions */
        Vector &add(const Vector<K> &vector);
        Vector &sub(const Vector<K> &vector);
        Vector &scl(const K &vector);

        /* Iterators */
        auto begin() { return data_vector.begin(); }
        auto end() { return data_vector.end(); }
        auto begin() const { return data_vector.begin(); }
        auto end() const { return data_vector.end(); }

        Vector linear_combination(const std::vector<Vector<K>> &u, const std::vector<K> &coefs);
        template <typename V>
        Vector lerp(const Vector<V> &u, const Vector<V> &v, V t);
        K dot(const Vector<K> &v) const;

        K norm_1() const;
        K norm() const;
        K norm_inf() const;

        float angle_cos(const Vector<K> &u, const Vector<K> &v);
        Vector cross_product(const Vector<K> &u, const Vector<K> &v);

        /* Utils functions */
        void check_validity(const Vector<K> &other);

        /* Output functions */
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Vector<U> &vector);
        void print_vec() const;
};

#include "vector.tpp"
