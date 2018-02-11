/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Wave.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月05日
*   描    述：
*
================================================================*/

#ifndef WAVE_H
#define WAVE_H

#include "Sprite.h"

namespace cmengine
{
    class Sprite;

    class Wave
    {
    private:
        

    public:
        Sprite &caster;
        const int hurtPoint;

        Wave(Sprite &caster_, int hurtPoint_) : caster(caster_), hurtPoint(hurtPoint_) {}

        void operator>>(Sprite &sp);
    };
}
#endif /* WAVE_H */
