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
    CreateSkillFunMap CMSourceManager::skillSource;
    CreateHeroFunMap CMSourceManager::heroSource;
    CreateEquipmentFunMap CMSourceManager::equipmentSource;

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
            std::cout << "No create skill function in map!" << std::endl;
            throw 0;
        }
    }

    void CMSourceManager::LoadHero(const CreateHeroFunMap &map)
    {
        CMSourceManager::heroSource = map;
    }

    CreateHeroFun CMSourceManager::GetCreateHeroFunWithKey(MapKey key)
    {
        CreateHeroFunMap::iterator it;

        it = CMSourceManager::heroSource.find(key);
        if (it != CMSourceManager::heroSource.end()) {
            return it->second;
        } else {
            std::cout << "No create hero function in map!" << std::endl;
            throw 0;
        }
    }

    void CMSourceManager::LoadEquipment(const CreateEquipmentFunMap &map)
    {
        CMSourceManager::equipmentSource = map;
    }

    CreateEquipmentFun CMSourceManager::GetCreateEquipmentFunWithKey(MapKey key)
    {
        CreateEquipmentFunMap::iterator it;

        it = CMSourceManager::equipmentSource.find(key);
        if (it != CMSourceManager::equipmentSource.end()) {
            return it->second;
        } else {
            std::cout << "No create equipment function in map!" << std::endl;
            throw 0;
        }
    }
}
