/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SkillWave.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月05日
*   描    述：
*
================================================================*/

#ifndef SKILLWAVE_H
#define SKILLWAVE_H

#include "Sprite.h"

namespace cmengine
{
    class Sprite;

    class SkillWave
    {
    private:
        

    public:
        Sprite &caster;
        const int hurtPoint;

        SkillWave(Sprite &caster_, int hurtPoint_) : caster(caster_), hurtPoint(hurtPoint_) {}

        void operator>>(Sprite &sp);
    };
}
#endif /* SKILLWAVE_H */
