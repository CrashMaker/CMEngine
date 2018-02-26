/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleInterface.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月24日
*   描    述：
*
================================================================*/

#include "CMBattleInterface.h"

#include <string>
#include <sstream>

namespace cmengine
{
    void CMBattleInterface::Dead(CMSprite &sp, CMStateLog &stateLog)
    {
        sp.model.health = 0;

        std::string log = sp.model.name + "已死亡";
        stateLog.Push(log);
    }

    void CMBattleInterface::Hurt(CMSprite &sp, int point, CMStateLog &stateLog)
    {
        sp.model.health -= point;

        std::stringstream ss;
        ss << point;
        std::string log = sp.model.name + "受到 " + ss.str() + " 点伤害";
        stateLog.Push(log);

        if (sp.model.health <= 0) {
            CMBattleInterface::Dead(sp, stateLog);
        }
    }

    void CMBattleInterface::PhysicalBlow(CMSprite &sp, int point, CMStateLog &stateLog)
    {
        int p = point - sp.model.defense;

        if (p < 0) {
            p = 0;
        }

        CMBattleInterface::Hurt(sp, p, stateLog);
    }
}
