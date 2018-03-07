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
#include "../CMGeneral/CMBaseType.h"
#include <iostream>

namespace cmengine
{
    CreateSkillFunMap CMSourceManager::skillSource;

    void CMSourceManager::LoadSkill(const CreateSkillFunMap &map)
    {
        CMSourceManager::skillSource = map;    
    }

    CreateSkillFun CMSourceManager::GetCreateSkillFunWithKey(MapKey key)
    {
        CreateSkillFunMap::iterator it;

        it = CMSourceManager::skillSource.find(key);
        if (it != CMSourceManager::skillSource.end()) {
            return it->second;
        } else {
            std::cout << "No CreateSkillFun in map!" << std::endl;
            throw 0;
        }
    }
}
