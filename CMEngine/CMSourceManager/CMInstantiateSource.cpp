/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMInstantiateSource.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年05月03日
*   描    述：
*
================================================================*/

#include "CMInstantiateSource.h"

namespace cmengine
{
    BaseSkill CMInstantiateSource::InstantiateSkill(MapKey key)
    {
        CreateSkillFun f = CMSourceManager::GetCreateSkillFunWithKey(key);
        return f();
    }

    HeroSprite CMInstantiateSource::InstantiateHero(MapKey key)
    {
        CreateHeroFun f = CMSourceManager::GetCreateHeroFunWithKey(key);
        return f();
    }

    Equipment CMInstantiateSource::InstantiateEquipment(MapKey key)
    {
        CreateEquipmentFun f = CMSourceManager::GetCreateEquipmentFunWithKey(key);

        return f();
    }
}
