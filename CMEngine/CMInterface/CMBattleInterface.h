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
#include "../CMLog/CMBattleNote.h"

namespace cmengine
{
    class CMBattleInterface
    {
    private:
        CMSprite &caster;           // 施法者
        CMSprite &target;           // 目标
        CMBattleNote &note;         // 战斗日志

        // 根据施放者的属性和技能的属性生成伤害
        int MakeAttackPoint() const;

        // 根据目标的属性和技能的属性生成可抵抗的伤害
        int MakeDefensePoint() const;

        // 计算最终伤害数值
        int CreateHurtPoint(int attackPoint, int defensePoint) const;

    public:
        CMBattleInterface(CMSprite &caster_, CMSprite &target_, CMBattleNote &note_) : 
            caster(caster_), target(target_), note(note_) {}

        /* 对目标打击造成伤害，入参可以对伤害数值进行调整。
         *
         * multiplication : 伤害的相乘系数
         * addition : 伤害的相加系数 */
        void Blow(float multiplication = 1, int addition = 0) const;
    };
}

#endif /* CMBATTLEINTERFACE_H */
