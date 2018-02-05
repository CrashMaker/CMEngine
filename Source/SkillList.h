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

#include <map>
#include <memory>
#include <string>
#include "../CMEngine/Skill.h"

using namespace cmengine;

using std::map;
using std::shared_ptr;
using std::string;

typedef shared_ptr<Skill> SkillPtr;
typedef map<string, SkillPtr> SkillMap;

SkillMap LoadSkillListForCMEngine();

namespace game
{
    // 技能列表
    SkillPtr Cut();
    SkillPtr Shot();
}

#endif /* SKILLLIST_H */
