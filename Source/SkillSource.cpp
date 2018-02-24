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

CreateSkillFunMap cmengine::GetSkillSourceForCMEngine()
{
    CreateSkillFunMap map;

    map = {
        {1, Cut}, 
    };

    return map;
}

// 技能列表
void Cut(CMSkillModel &model)
{
    model.name = "Cut";
    model.logicFun = [](CMSprite &caster, 
                        CMSprite &target, 
                        CMSkill &skill) {
        CMBattleInterface::PhysicalBlow(target, caster.GetModel().attack);
    };
}
