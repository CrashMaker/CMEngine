/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SkillManager.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月02日
*   描    述：
*
================================================================*/

#include "SkillManager.h"
#include <iostream>

namespace cmengine
{
    std::map<int, Skill> SkillManager::skillMap;
    
    void SkillManager::loadSkills(const std::vector<Skill> &v)
    {
        skillMap.erase(skillMap.begin(), skillMap.end());

        for (int i = 0; i < (int)v.size(); ++i) {
            skillMap.insert(std::make_pair(i, v[i]));
        }
    }

    void SkillManager::showSkills()
    {
        if (skillMap.size() <= 0) {
            std::cout << "No skill!" << std::endl;
        }

        std::map<int, Skill>::iterator it;
        for (it = skillMap.begin(); it != skillMap.end(); ++it) {
            Skill sk = it->second;
            std::cout << it->first <<" " << sk.name << std::endl;
        }
    }
}
