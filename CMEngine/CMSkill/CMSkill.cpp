/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkill.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#include "CMSkill.h"
#include "../CMInterface/CMBattleInterface.h"

namespace cmengine
{
    CMSkill::CMSkill(CreateSkillFun f)
    {
        f(model);
    }

    void CMSkill::Cast(CMSprite &caster, CMSprite &target, CMBattleNote &note) const
    {
        CMBattleInterface interface = CMBattleInterface(caster, target, *this, note);
        model.logicFun(interface);
    }
}
