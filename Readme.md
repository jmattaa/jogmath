# JogMath :running:

A header only math library for c and c++

## Installation

Clone the repo into your include directory of the project

## Usage/Examples

Include the header file in your source

```c
#include <jogmath.h>
```

### Create Vector

---

Create a vector 2

```c
vec2 *v = vec2_create(4, 8);

// You can access the values as x and y
printf("x: %d, y: %d", v->x, v->y); // x: 4, y: 8

// You can also access the values as u and v
printf("u: %d, v: %d", v->u, v->v); // u: 4, v: 8
```

Creating Vector3 is the same process

```c
vec2 *v3 = vec3_create(16, 32, 64);

// You can access the values as x, y, z
v->x // 16
v->y // 32
v->z // 64

// And as r, g, b
v->r // 16
v->g // 32
v->b // 64
```

### Do maths on the vector

---

```c
vec2 *v = vec2_create(2, 4);

vec2_add(v, vec2_create(8, 16));
// v is now
// x: 2 + 8 = 10
// y: 4 + 16 = 20

vec2_mult(v, vec2_create(1, 2));
// v is now
// X: 2 * 1 = 2
// y: 4 * 2 = 8
```

There is also `vec2_mult()` or `ve2_div()` which are used in the same way as `add` and `sub`.

Change the vec2\_ prefix to do math on other vector types. Such as `vec3_add()` or `vec4_mult()`.

### Matricies

---

...
