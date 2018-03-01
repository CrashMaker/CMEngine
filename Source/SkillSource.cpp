/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SkillSource.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月22日
*   描    述：
*
================================================================*/

#include "SkillSource.h"

cmengine::CreateSkillFunMap cmengine::GetSkillSourceForCMEngine()
{
    cmengine::CreateSkillFunMap map;

    map = {
        {1, Cut}, 
    };

    return map;
}

// 技能列表
void Cut(cmengine::CMSkillModel &model)
{
    model.name = "Cut";
    model.attackType = cmengine::AttackTypeMelee;
    model.damageType = cmengine::DamageTypePhysical;

    model.logicFun = [](const cmengine::CMBattleInterface &interface) {
        interface.Blow();
    };
}
