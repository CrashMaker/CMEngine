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
    SkillMap SkillManager::skMap;
    
    void SkillManager::LoadSkills(const SkillMap &m)
    {
        skMap.erase(skMap.begin(), skMap.end());
        skMap = m;
    }

    void SkillManager::ShowSkills()
    {
        if (skMap.size() <= 0) {
            std::cout << "No skill!" << std::endl;
        }

        for (SkillMap::iterator it = skMap.begin(); it != skMap.end(); ++it) {
            SkillPtr sk = it->second;
            std::cout << it->first << " " << sk->name << std::endl;
        }
    }

    SkillPtr SkillManager::GetSkillWithKey(string key)
    {
        if (key.empty()) {
            std::cout << "Please enter a valid key!" << std::endl;
            return nullptr;
        }

        SkillMap::iterator it = skMap.find(key);
        
        if (it != skMap.end()) {
            return it->second;
        } else {
            std::cout << "No skill with this key: " << key << std::endl;
            return nullptr;
        }
    }
}
