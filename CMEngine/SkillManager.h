/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SkillManager.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月02日
*   描    述：
*
================================================================*/

#ifndef SKILLMANAGER_H
#define SKILLMANAGER_H

#include <vector>
#include <map>
#include "Skill.h"
#include "../Source/SkillList.h"

namespace cmengine
{
    class SkillManager
    {
    private:
        static std::map<int, Skill> skillMap;
    public:
        static void LoadSkills(const std::vector<Skill> &v);
        static void ShowSkills();
        static Skill GetSkillWithKey(int key);
    };
}

#endif /* SKILLMANAGER_H */
