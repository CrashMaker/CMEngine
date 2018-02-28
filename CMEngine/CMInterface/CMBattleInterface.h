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

    };
}

#endif /* CMBATTLEINTERFACE_H */
