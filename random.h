// random.h
// random
//
// Created by ascetic85 on 2012-11-26
//
// come from Irrlicht game engine

#ifndef DD_RANDOM_H
#define DD_RANDOM_H

namespace DD {
    
static int seed = 0x0f0f0f0f;
int rand()
{
    const int m = 2147483399;
    const int a = 40692;
    const int q = m/a;
    const int r = m%a;
    
    seed = a * (seed%q) - r* (seed/q);
    if (seed<0) seed += m;
    
    return seed;
}

} // DD namespace

#endif // DD_RANDOM_H END