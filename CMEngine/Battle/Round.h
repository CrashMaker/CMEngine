/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Round.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月12日
*   描    述：战斗回合，分五个阶段依次进行——回合开始，战斗前置，
*             战斗进行，战斗后置，回合结束。
*
================================================================*/

#ifndef ROUND_H
#define ROUND_H

#include "../Sprite/Sprite.h"
#include "../Skill/Skill.h"

namespace cmengine
{
    class Round
    {
    private:
        Sprite &caster;
        Sprite &target;
        const Skill &skill;

    public:
        Round(Sprite &caster_, Sprite &target_, const Skill &skill_) : 
            caster(caster_), target(target_), skill(skill_) {}

        void action();
    };
}

#endif /* ROUND_H */
