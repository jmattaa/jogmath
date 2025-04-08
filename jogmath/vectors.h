#ifndef JOGMATH_VEC2_H
#define JOGMATH_VEC2_H

#ifdef __cplusplus
#include <cstdio>
#else
#include <stdio.h>
#endif

#define JOGMATH_FUNC static inline

#define JOGMATH_VEC_FUNCS_ITER(_X)                                             \
    _X(add, +)                                                                 \
    _X(sub, -)                                                                 \
    _X(mul, *)                                                                 \
    _X(div, /)

#define JOGMATH_VEC2_TYPES_ITER(_X, ...)                                       \
    _X(jogmath_vec2f, float, __VA_ARGS__)                                      \
    _X(jogmath_vec2d, double, __VA_ARGS__)                                     \
    _X(jogmath_vec2i, int, __VA_ARGS__)

#define _X(name, type, ...)                                                    \
    typedef union name                                                         \
    {                                                                          \
        struct                                                                 \
        {                                                                      \
            type x;                                                            \
            type y;                                                            \
        };                                                                     \
        type v[2];                                                             \
    } name;
JOGMATH_VEC2_TYPES_ITER(_X);
#undef _X

#define _X2(name, type, funcname, op)                                          \
    JOGMATH_FUNC void name##_##funcname(name a, name b, name out)              \
    {                                                                          \
        if (#op[0] == '/' && (b.v[0] == 0 || b.v[1] == 0))                     \
        {                                                                      \
            fprintf(stderr, "Error: Division by zero in vector operation\n");  \
            return;                                                            \
        }                                                                      \
        out.v[0] = a.v[0] op b.v[0];                                           \
        out.v[1] = a.v[1] op b.v[1];                                           \
    }
#define _X(name, op) JOGMATH_VEC2_TYPES_ITER(_X2, name, op)
JOGMATH_VEC_FUNCS_ITER(_X)
#undef _X
#undef _X2

#define JOGMATH_VEC3_TYPES_ITER(_X, ...)                                       \
    _X(jogmath_vec3f, float, __VA_ARGS__)                                      \
    _X(jogmath_vec3d, double, __VA_ARGS__)                                     \
    _X(jogmath_vec3i, int, __VA_ARGS__)

#define _X(name, type, ...)                                                    \
    typedef union name                                                         \
    {                                                                          \
        struct                                                                 \
        {                                                                      \
            type x;                                                            \
            type y;                                                            \
            type z;                                                            \
        };                                                                     \
        struct                                                                 \
        {                                                                      \
            type r;                                                            \
            type g;                                                            \
            type b;                                                            \
        };                                                                     \
        type v[3];                                                             \
    } name;
JOGMATH_VEC3_TYPES_ITER(_X);
#undef _X

#define _X2(name, type, funcname, op)                                          \
    JOGMATH_FUNC void name##_##funcname(name a, name b, name out)              \
    {                                                                          \
        if (#op[0] == '/' && (b.v[0] == 0 || b.v[1] == 0 || b.v[2] == 0))      \
        {                                                                      \
            fprintf(stderr, "Error: Division by zero in vector operation\n");  \
            return;                                                            \
        }                                                                      \
        out.v[0] = a.v[0] op b.v[0];                                           \
        out.v[1] = a.v[1] op b.v[1];                                           \
        out.v[2] = a.v[2] op b.v[2];                                           \
    }
#define _X(name, op) JOGMATH_VEC3_TYPES_ITER(_X2, name, op)
JOGMATH_VEC_FUNCS_ITER(_X)
#undef _X
#undef _X2

#define JOGMATH_VEC4_TYPES_ITER(_X, ...)                                       \
    _X(jogmath_vec4f, float, __VA_ARGS__)                                      \
    _X(jogmath_vec4d, double, __VA_ARGS__)                                     \
    _X(jogmath_vec4i, int, __VA_ARGS__)

#define _X(name, type, ...)                                                    \
    typedef union name                                                         \
    {                                                                          \
        struct                                                                 \
        {                                                                      \
            type x;                                                            \
            type y;                                                            \
            type z;                                                            \
            type w;                                                            \
        };                                                                     \
        struct                                                                 \
        {                                                                      \
            type r;                                                            \
            type g;                                                            \
            type b;                                                            \
            type a;                                                            \
        };                                                                     \
        type v[4];                                                             \
    } name;
JOGMATH_VEC4_TYPES_ITER(_X);
#undef _X

#define _X2(name, type, funcname, op)                                          \
    JOGMATH_FUNC void name##_##funcname(name a, name b, name out)              \
    {                                                                          \
        if (#op[0] == '/' &&                                                   \
            (b.v[0] == 0 || b.v[1] == 0 || b.v[2] == 0 || b.v[3] == 0))        \
        {                                                                      \
            fprintf(stderr, "Error: Division by zero in vector operation\n");  \
            return;                                                            \
        }                                                                      \
        out.v[0] = a.v[0] op b.v[0];                                           \
        out.v[1] = a.v[1] op b.v[1];                                           \
        out.v[2] = a.v[2] op b.v[2];                                           \
        out.v[3] = a.v[3] op b.v[3];                                           \
    }
#define _X(name, op) JOGMATH_VEC4_TYPES_ITER(_X2, name, op)
JOGMATH_VEC_FUNCS_ITER(_X)
#undef _X
#undef _X2

#endif
