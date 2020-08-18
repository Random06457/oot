#ifndef _Z_EFF_SS_ICE_SMOKE_H_
#define _Z_EFF_SS_ICE_SMOKE_H_

#include "ultra64.h"
#include "global.h"

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
} EffectSsIceSmokeInitParams; // size = 0x

#endif
