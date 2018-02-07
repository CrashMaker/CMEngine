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

#include <map>
#include <memory>
#include <string>

#include "Skill.h"

namespace cmengine
{
    using std::map;
    using std::shared_ptr;
    using std::string;

    typedef shared_ptr<Skill> SkillPtr;
    typedef map<string, SkillPtr> SkillMap;

    class SkillManager
    {
    private:
        static SkillMap skMap;
    public:
        static void LoadSkills(const SkillMap &m);
        static void ShowSkills();
        static SkillPtr GetSkillWithKey(string key);
    };
}

#endif /* SKILLMANAGER_H */
