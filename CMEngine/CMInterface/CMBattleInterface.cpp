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
    void CMBattleInterface::Dead(bool showLog)
    {
        
    }

    void CMBattleInterface::Hurt(int point, bool showLog)
    {

    }

    void CMBattleInterface::Blow(float multiplication, int addition, bool showLog)
    {
        int hurtPoint = 0;
        int resistancePoint = 0;
        
        if (DamageTypePhysical == skill.GetModel().damageType) {
            hurtPoint = caster.GetModel().attack;
            resistancePoint = target.GetModel().defense;
        } else if (DamageTypeMagic == skill.GetModel().damageType) {
            hurtPoint = caster.GetModel().magicAtk;
            resistancePoint = target.GetModel().magicDef;
        }

        hurtPoint *= multiplication;
        hurtPoint += addition;

        int resultPoint = hurtPoint - resistancePoint;
        if (resultPoint < 0) resultPoint = 0;
    }
}
