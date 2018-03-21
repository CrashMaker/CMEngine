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
        {1, Cut}, 
        {2, Shot}, 
    };

    return map;
}

// 技能列表
BaseSkill Cut()
{
    auto logicFun = [](CMBaseSkill* skill) {
        CMNormalSkill* sk = (CMNormalSkill*)skill;
        CMBaseSprite* sp = sk->GetCaster();
        sp->PrintAttribute();
    };
    
    BaseSkill skill(new CMNormalSkill("Cut", logicFun, SkillCastTargetTypeSelf));
    return skill;
}

BaseSkill Shot()
{
    auto logicFun = [](CMBaseSkill* skill) {
        std::cout << skill->GetName() << std::endl;
    };

    BaseSkill skill(new CMBaseSkill("Shot", logicFun));

    return skill;
}
