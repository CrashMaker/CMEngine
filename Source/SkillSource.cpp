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

CreateSkillFunMap cmengine::GetSkillSourceForCMEngine()
{
    cmengine::CreateSkillFunMap map;

    map = {
        {1, Cut}, 
        {2, Shot}, 
    };

    return map;
}

// 技能列表
BaseSkill Cut()
{
    auto logicFun = [](CMNormalSkillInterface interface){
        std::cout << "111" << std::endl;
    };
    
    BaseSkill skill(new CMNormalSkill("Cut", SkillCastTargetTypeSelf, logicFun));
    return skill;
}

BaseSkill Shot()
{
    BaseSkill skill(new CMBaseSkill("Shot"));

    return skill;
}
