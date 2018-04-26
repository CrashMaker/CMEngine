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
        {1, Heal}, 
    };

    return map;
}

// 技能列表
BaseSkill Heal()
{
    auto logicFun = [](CMBaseSkill* skill) {
        std::cout << skill->GetName() << std::endl;
    };

    BaseSkill skill(new CMHealSkill("Heal", logicFun));

    return skill;
}
