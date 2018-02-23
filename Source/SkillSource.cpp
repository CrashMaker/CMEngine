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

#include <iostream>

SkillMap cmengine::LoadSkillSourceForCMEngine()
{
    SkillMap map;

    map = {
        {1, Cut}, 
    };

    return map;
}

// 技能列表
void Cut(CMSkillModel &model)
{
    model.name = "I am Cut";
    model.logicFun = [](const CMSpriteModel &caster, const CMSpriteModel &target){
        std::cout << caster.name << " " << target.name << std::endl;
    };
}
