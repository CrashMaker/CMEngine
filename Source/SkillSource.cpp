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

using namespace cmengine;
using namespace std;

CreateSkillFunMap cmengine::GetSkillSourceForCMEngine()
{
    cmengine::CreateSkillFunMap map;

    map = {
        {1, Hit}, 
        {2, Heal}, 
    };

    return map;
}

// 技能列表
BaseSkill Hit()
{
    auto logicFun = [](CMBaseSkill* sk) {
        CMHitSkill* skill = (CMHitSkill*)sk;
        skill->mulReviseValue = 0.2;
    };

    BaseSkill skill(new CMHitSkill("Hit", logicFun, 
                SkillAttackTypeMelee, SkillDamageTypePhysical));

    return skill;
}

BaseSkill Heal()
{
    auto logicFun = [](CMBaseSkill* sk) {
        CMHealSkill* skill = (CMHealSkill*)sk;
        skill->healPoint = 100;
    };

    BaseSkill skill(new CMHealSkill("Heal", logicFun));

    return skill;
}
