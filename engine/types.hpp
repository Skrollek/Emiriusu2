#ifndef EMIRIUSU_TYPES_HPP
#define EMIRIUSU_TYPES_HPP

template<class T>
struct Vec2 {
    T x;
    T y;

    Vec2 (T _x, T _y) : x(_x), y(_y) {}
};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;

#endif