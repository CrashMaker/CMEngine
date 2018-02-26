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

#include <iostream>

namespace cmengine
{
    void CMBattleInterface::Dead(CMSprite &sp)
    {
        sp.model.health = 0;
    }

    void CMBattleInterface::Hurt(CMSprite &sp, int point)
    {
        sp.model.health -= point;

        if (sp.model.health <= 0) {
            CMBattleInterface::Dead(sp);
        }
    }

    void CMBattleInterface::PhysicalBlow(CMSprite &sp, int point)
    {
        int p = point - sp.model.defense;

        if (p < 0) {
            p = 0;
        }

        CMBattleInterface::Hurt(sp, p);
    }
}
