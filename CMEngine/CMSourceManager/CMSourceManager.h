/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSourceManager.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSOURCEMANAGER_H
#define CMSOURCEMANAGER_H

#include "../CMGeneral/CMGeneralTypedef.h"

namespace cmengine
{
    class CMSourceManager
    {
    public:
        static void LoadSkill(const CreateSkillFunMap &map);
        static CreateSkillFun GetCreateSkillFunWithKey(MapKey key);

        static void LoadHero(const CreateHeroFunMap &map);
        static CreateHeroFun GetCreateHeroFunWithKey(MapKey key);

        static void LoadEquipment(const CreateEquipmentFunMap &map);
        static CreateEquipmentFun GetCreateEquipmentFunWithKey(MapKey key);
    private:
        static CreateSkillFunMap skillSource; 
        static CreateHeroFunMap heroSource;
        static CreateEquipmentFunMap equipmentSource;
    };
}

#endif /* CMSOURCEMANAGER_H */
