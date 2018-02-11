/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SkillList.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月02日
*   描    述：
*
================================================================*/

#ifndef SKILLLIST_H
#define SKILLLIST_H

#include "../CMEngine/CMEngine.h"

using namespace cmengine;

SkillMap LoadSkillListForCMEngine();

namespace game
{
    // 技能列表
    SkillPtr Cut();
}

#endif /* SKILLLIST_H */
