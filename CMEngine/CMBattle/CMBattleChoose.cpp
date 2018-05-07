/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleChoose.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年05月07日
*   描    述：
*
================================================================*/

#include "CMBattleChoose.h"

namespace cmengine
{
    // 选择角色的技能，返回技能编号
    int CMBattleChoose::ChooseSkillIndexFromSprite(CMBaseSprite* sprite)
    {
        return sprite->GetSkillList()[0];
    }

    /* ==========实现的协议========== */

    // 选取目标
    CMBaseSprite* CMBattleChoose::ObtainTarget()
    {
        return secondTeam[0];
    }
}
