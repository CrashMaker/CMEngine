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

    void CMBattleInterface::PhysicalBlow(CMSprite &caster, CMSprite &target, CMStateLog &stateLog)
    {
        int point = caster.model.attack - target.model.defense;

        if (point < 0) {
            point = 0;
        }

        std::stringstream ss;
        ss << point;
        std::string log = caster.model.name + "造成 " + ss.str() + " 点物理伤害";
        stateLog.Push(log);

        CMBattleInterface::Hurt(target, point, stateLog);
    }
}
