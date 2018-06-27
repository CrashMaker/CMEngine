/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMGeneralTypedef.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月08日
*   描    述：
*
================================================================*/

#ifndef CMGENERALTYPEDEF_H
#define CMGENERALTYPEDEF_H

#include <map>
#include <functional>
#include <memory>

namespace cmengine
{
    class CMBaseSkill;
    class CMBaseSprite;
    class CMHeroSprite;
    class CMEquipment;
    
    typedef int MapKey;

    // 用于：创建技能类函数
    typedef std::unique_ptr<CMBaseSkill> BaseSkill;
    typedef std::function<BaseSkill(void)> CreateSkillFun;
    typedef std::map<MapKey, CreateSkillFun> CreateSkillFunMap;

    // 用于：创建怪物类函数
    typedef std::unique_ptr<CMBaseSprite> BaseSprite;
    typedef std::function<BaseSprite(void)> CreateSpriteFun;
    typedef std::map<MapKey, CreateSpriteFun> CreateSpriteFunMap;

    // 用于：创建英雄类函数
    typedef std::unique_ptr<CMHeroSprite> HeroSprite;
    typedef std::function<HeroSprite(void)> CreateHeroFun;
    typedef std::map<MapKey, CreateHeroFun> CreateHeroFunMap;

    // 用于：创建装备类函数
    typedef std::unique_ptr<CMEquipment> Equipment;
    typedef std::function<Equipment(void)> CreateEquipmentFun;
    typedef std::map<MapKey, CreateEquipmentFun> CreateEquipmentFunMap;
}

#endif /* CMGENERALTYPEDEF_H */
