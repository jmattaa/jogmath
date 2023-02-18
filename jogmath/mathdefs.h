#ifndef JOG_MATHDEFS_H
#define JOG_MATHDEFS_H

#define JOG_PI 3.14152653589

static inline float toRadians(float d)
{
    return d * (JOG_PI / 180.0f);
}

#endif // JOG_MATHDEFS_H
