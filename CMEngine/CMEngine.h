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

#include "CMBattle/CMRound.h"
#include "CMOther/CMSexCall.h"
#include "CMBattle/CMAttack.h"
#include "CMSourceManager/CMSourceManager.h"
#include "CMModel/CMSpriteModel.h"
#include "CMInterface/CMBattleInterface.h"
#include "CMSkill/CMBaseSkill.h"
#include "CMSourceManager/CMInstantiateSource.h"
#include "CMGeneral/CMGeneralTypedef.h"
#include "CMSkill/CMSkillCastTarget.h"
#include "CMGeneral/CMGeneralSkillType.h"
#include "CMSprite/CMBaseSprite.h"
#include "CMGeneral/CMGeneralSpriteType.h"
#include "CMSprite/CMHeroSprite.h"
#include "CMSprite/CMMonsterSprite.h"
#include "CMSkill/CMDamageSkill.h"
#include "CMSkill/CMHealSkill.h"

namespace cmengine
{
    // 需要实现的函数
    CreateSkillFunMap GetSkillSourceForCMEngine();
    CreateSpriteFunMap GetSpriteSourceForCMEngine();
    CreateHeroFunMap GetHeroSourceForCMEngine();

    inline void CMEngineRun()
    {
        CMSourceManager::LoadSkill(GetSkillSourceForCMEngine());
        CMSourceManager::LoadSprite(GetSpriteSourceForCMEngine());
        CMSourceManager::LoadHero(GetHeroSourceForCMEngine());
    }
}

#endif /* CMENGINE_H */
