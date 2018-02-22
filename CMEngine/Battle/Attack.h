/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Attack.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月22日
*   描    述：进攻阶段，分为进攻准备，进攻开始，进攻结束
*
================================================================*/

#ifndef ATTACK_H
#define ATTACK_H

#include "../Sprite/Sprite.h"
#include "../Skill/Skill.h"

namespace cmengine
{
    class Attack
    {
        private:
            Sprite &caster;
            Sprite &target;
            const Skill &skill;

        public:
            Attack(Sprite &caster_, Sprite &target_, const Skill &skill_) : 
                caster(caster_), target(target_), skill(skill_) {}

            void action();
    };
}

#endif /* ATTACK_H */
