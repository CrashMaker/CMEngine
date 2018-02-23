/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSexCall.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#include "CMSexCall.h"

namespace cmengine
{
    CMAttack CMSexCall::operator>>(CMSprite &sp_)
    {
        CMAttack attack = CMAttack(sp, sp_, sk);
        attack.action();

        return attack;
    }

    CMSexCall operator+(CMSprite &sp_, MapKey key)
    {
        CMSkill sk = CMSkill(CMSourceManager::GetCreateSkillFunWithKey(key));
        return CMSexCall(sp_, sk);
    }
}
