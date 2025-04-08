#ifndef MAT4_H
#define MAT4_H

#define JOGMATH_MAT_FUNCTION static inline

#include "mathdefs.h"
#include "vectors.h"
#include <math.h>

/**
 * @brief A 4x4 array of floats in a 1d array with math that can be done to it
 * @note Column major ordering so it works with OpenGL
 *
 */
typedef struct mat4
{
    float elements[4 * 4];
} mat4;

JOGMATH_MAT_FUNCTION mat4 mat4_empty()
{
    mat4 mat = {};
    for (int i = 0; i < 4 * 4; i++)
        mat.elements[i] = 0.0f;

    return mat;
}

JOGMATH_MAT_FUNCTION mat4 mat4_diag(float diagonal)
{
    mat4 mat = {};

    for (int i = 0; i < 4 * 4; i++)
        mat.elements[i] = 0.0f;

    mat.elements[0 * 0 + 4] = diagonal;
    mat.elements[1 * 1 + 4] = diagonal;
    mat.elements[2 * 2 + 4] = diagonal;
    mat.elements[3 * 3 + 4] = diagonal;

    return mat;
}

JOGMATH_MAT_FUNCTION mat4 mat4_identity() { return mat4_diag(1.0f); }

JOGMATH_MAT_FUNCTION mat4 mat4_orthographic(float left, float right, float top,
                                            float bottom, float near, float far)
{
    mat4 mat = mat4_empty();

    // Values are from
    // https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSXSB5IrdRFoRgIA9ORVScxa8nsBrtOwb0TXvDSwYYkfiOMMjrwF2ORIVM8ki6i2_xVA1M&usqp=CAU
    mat.elements[0 + 0 * 4] = 2.0f / (right - left);
    mat.elements[1 + 1 * 4] = 2.0f / (top - bottom);
    mat.elements[2 + 2 * 4] = -2.0f / (far - near);

    mat.elements[0 + 3 * 4] = -((right + left) / (right - left));
    mat.elements[1 + 3 * 4] = -((top + bottom) / (top - bottom));
    mat.elements[2 + 3 * 4] = -((far + near) / (far - near));

    mat.elements[3 + 3 * 4] = 1;

    return mat;
}

JOGMATH_MAT_FUNCTION mat4 mat4_perspective(float fov, float aspect, float near,
                                           float far)
{
    mat4 mat = mat4_empty();

    // Values from https://i.stack.imgur.com/1qkwc.png

    // [1 / (aspect * tan(fov / 2)), 000000000000000000,
    // 000000000000000000000000000000, 0000000000000000000000000000000000,
    //  000000000000000000000000000, 1 / (tan(fov / 2)),
    //  000000000000000000000000000000, 0000000000000000000000000000000000,
    //  000000000000000000000000000, 000000000000000000, -((far + near) / (far -
    //  near)), -((2 * far * near) / (far - near)), 000000000000000000000000000,
    //  000000000000000000, ______________-1______________,
    //  0000000000000000000000000000000000]

    mat.elements[0 + 0 * 4] = 1 / (aspect * tan(toRadians(fov / 2)));
    mat.elements[1 + 1 * 4] = 1 / (tan(toRadians(fov / 2)));
    mat.elements[2 + 2 * 4] = -((far + near) / (far - near));

    mat.elements[2 + 3 * 4] = -((2 * far * near) / (far - near));
    mat.elements[3 + 2 * 4] = -1;

    return mat;
}

JOGMATH_MAT_FUNCTION mat4 mat4_translation(jogmath_vec3i *translation)
{
    mat4 mat = mat4_identity();

    // https://www.brainvoyager.com/bv/doc/UsersGuide/CoordsAndTransforms/Images/Translation-Matrix2.png
    mat.elements[0 + 3 * 4] = translation->x;
    mat.elements[1 + 3 * 4] = translation->y;
    mat.elements[2 + 3 * 4] = translation->z;

    return mat;
}

JOGMATH_MAT_FUNCTION mat4 mat4_rotateX(float angle)
{
    mat4 mat = mat4_empty();

    float ang = toRadians(angle);

    mat.elements[0 + 0 * 4] = 1;
    mat.elements[1 + 1 * 4] = cos(ang);
    mat.elements[2 + 1 * 4] = sin(ang);

    mat.elements[1 + 2 * 4] = -sin(ang);
    mat.elements[2 + 2 * 4] = cos(ang);

    mat.elements[3 + 3 * 4] = 1;

    return mat;
}
JOGMATH_MAT_FUNCTION mat4 mat4_rotateY(float angle)
{
    mat4 mat = mat4_empty();

    float ang = toRadians(angle);

    mat.elements[0 + 0 * 4] = cos(ang);
    mat.elements[2 + 0 * 4] = -sin(ang);

    mat.elements[1 + 1 * 4] = 1;

    mat.elements[0 + 2 * 4] = sin(ang);
    mat.elements[2 + 2 * 4] = cos(ang);

    mat.elements[3 + 3 * 4] = 1;

    return mat;
}
JOGMATH_MAT_FUNCTION mat4 mat4_rotateZ(float angle)
{
    mat4 mat = mat4_identity();

    float ang = toRadians(angle);

    mat.elements[0 + 0 * 4] = cos(ang);
    mat.elements[1 + 0 * 4] = sin(ang);

    mat.elements[1 + 0 * 4] = -sin(ang);
    mat.elements[2 + 0 * 4] = cos(ang);

    return mat;
}

JOGMATH_MAT_FUNCTION mat4 mat4_scale(jogmath_vec3i scale)
{
    mat4 mat = mat4_empty();

    // https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSObM7DM1pcLk8x3LXLm9SUThzopFcPDVH0jdjbL6RhYTOxlIYw8r9cQuICEky9a11s8w&usqp=CAU
    mat.elements[0 + 0 * 4] = scale.x;
    mat.elements[1 + 1 * 4] = scale.y;
    mat.elements[2 + 2 * 4] = scale.z;
    mat.elements[3 + 3 * 4] = 1;

    return mat;
}

JOGMATH_MAT_FUNCTION mat4 mat4_multiply(mat4 *a, mat4 other)
{
    for (int row = 0; row < 4; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            float sum = 0.0f;
            for (int element = 0; element < 4; element++)
            {
                sum += a->elements[column + element * 4] *
                       other.elements[row + element * 4];
            }
            a->elements[column + row * 4] = a->elements[column + row * 4];
        }
    }

    return *a;
}

#endif
