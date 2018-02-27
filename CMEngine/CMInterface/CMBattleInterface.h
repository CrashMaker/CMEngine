/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleInterface.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月24日
*   描    述：
*
================================================================*/

#ifndef CMBATTLEINTERFACE_H
#define CMBATTLEINTERFACE_H

#include "../CMSprite/CMSprite.h"
#include "../CMStateLog/CMStateLog.h"

namespace cmengine
{
    class CMBattleInterface
    {
    public:
        static void Dead(CMSprite &sp, CMStateLog &stateLog);
        static void Hurt(CMSprite &sp, int point, CMStateLog &stateLog);
        static void PhysicalBlow(CMSprite &caster, CMSprite &target, CMStateLog &stateLog);
    };
}

#endif /* CMBATTLEINTERFACE_H */
