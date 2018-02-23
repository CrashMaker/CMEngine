/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSourceManager.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#include "CMSourceManager.h"

#include <iostream>

namespace cmengine
{
    SkillMap CMSourceManager::skillMap;

    void CMSourceManager::LoadSkill(const SkillMap &map)
    {
        CMSourceManager::skillMap = map;    
    }

    SkillFun CMSourceManager::GetSkillFunWithKey(int key)
    {
        SkillMap::iterator it;

        it = CMSourceManager::skillMap.find(key);
        if (it != CMSourceManager::skillMap.end()) {
            return it->second;
        }

        return 0;
    }
}
