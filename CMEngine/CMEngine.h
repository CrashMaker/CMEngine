/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMEngine.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月07日
*   描    述：
*
================================================================*/

#ifndef CMENGINE_H
#define CMENGINE_H

#include "CMSourceManager/CMSourceManager.h"
#include "CMSourceManager/CMInstantiateSource.h"

#include "CMSkill/CMBaseSkill.h"
#include "CMSprite/CMBaseSprite.h"
#include "CMSprite/CMHeroSprite.h"
#include "CMSkill/CMHealSkill.h"

namespace cmengine
{
    // 需要实现的函数
    CreateSkillFunMap GetSkillSourceForCMEngine();
    CreateHeroFunMap GetHeroSourceForCMEngine();

    inline void CMEngineRun()
    {
        CMSourceManager::LoadSkill(GetSkillSourceForCMEngine());
        CMSourceManager::LoadHero(GetHeroSourceForCMEngine());
    }
}

#endif /* CMENGINE_H */
