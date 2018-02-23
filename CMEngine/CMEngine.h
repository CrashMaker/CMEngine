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

#include "CMSprite/CMSprite.h"
#include "CMSkill/CMSkill.h"
#include "CMBattle/CMRound.h"
#include "CMOther/CMSexCall.h"
#include "CMBattle/CMAttack.h"
#include "CMSourceManager/CMSourceManager.h"

namespace cmengine
{
    inline void CMEngineRun()
    {
        CMSourceManager::LoadSkill();
    }
}

#endif /* CMENGINE_H */
