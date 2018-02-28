/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleInterface.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月24日
*   描    述：
*
================================================================*/

#ifndef CMBATTLEINTERFACE_H
#define CMBATTLEINTERFACE_H

#include "../CMSprite/CMSprite.h"
#include "../CMSkill/CMSkill.h"

namespace cmengine
{
    class CMBattleInterface
    {
    private:
        CMSprite &caster;
        CMSprite &target;
        CMSkill &skill;

    public:
        CMBattleInterface(CMSprite &caster_, CMSprite &target_, CMSkill &skill_) : 
            caster(caster_), target(target_), skill(skill_) {}

        void Dead(bool showLog = true);
        void Hurt(int point, bool showLog = true);

        /* 对目标打击造成伤害，伤害由施放者的属性决定，伤害类型
         * 由技能的伤害类型决定，入参可以对伤害数值进行调整。
         *
         * multiplication : 伤害的相乘系数
         * addition : 伤害的相加系数
         * showLog : 是否打印日志 */
        void Blow(float multiplication = 1, int addition = 0, bool showLog = true);
    };
}

#endif /* CMBATTLEINTERFACE_H */
