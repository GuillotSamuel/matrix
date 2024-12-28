#pragma once

template <typename V>
V lerp(V u, V v, V t) {
    return u + t * (v - u);
}
