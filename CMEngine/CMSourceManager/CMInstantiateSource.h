/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMInstantiateSource.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月07日
*   描    述：
*
================================================================*/

#ifndef CMINSTANTIATESOURCE_H
#define CMINSTANTIATESOURCE_H

#include "CMSourceManager.h"
#include "../CMSkill/CMBaseSkill.h"
#include "../CMSprite/CMBaseSprite.h"
#include "../CMSprite/CMHeroSprite.h"
#include "../CMEquipment/CMEquipment.h"
#include <iostream>
#include <memory>

namespace cmengine
{
    // 一般初始化
    class CMInstantiateSource
    {
    public:
        static BaseSkill InstantiateSkill(MapKey key);
        static HeroSprite InstantiateHero(MapKey key);
        static Equipment InstantiateEquipment(MapKey key);
    };


    // 泛类初始化
    enum struct InstantiateType
    {
        Skill, 
        Hero, 
        Equipment
    };

    template <class T>
    class CMInstantiateSourceTemplate
    {
    public:
        static T Instantiate(InstantiateType type, MapKey key);
    };

    template <class T>
    T CMInstantiateSourceTemplate<T>::Instantiate(InstantiateType type, MapKey key)
    {
        if (InstantiateType::Skill == type) {
            CreateSkillFun f = CMSourceManager::GetCreateSkillFunWithKey(key);
            BaseSkill s = f();
            CMBaseSkill* t = s.get();

            if (typeid(T) == typeid(*t)) {
                return *((T*)t);
            } else {
                std::cout << "Instantiate error!" << std::endl;
                throw 0;
            }
        } else if (InstantiateType::Hero == type) {
            CreateHeroFun f = CMSourceManager::GetCreateHeroFunWithKey(key);
            HeroSprite s = f();
            CMHeroSprite* t = s.get();

            if (typeid(T) == typeid(*t)) {
                return *((T*)t);
            } else {
                std::cout << "Instantiate error!" << std::endl;
                throw 0;
            }
        } else if (InstantiateType::Equipment == type) {
            CreateEquipmentFun f = CMSourceManager::GetCreateEquipmentFunWithKey(key);
            Equipment s = f();
            CMEquipment* t = s.get();

            if (typeid(T) == typeid(*t)) {
                return *((T*)t);
            } else {
                std::cout << "Instantiate error!" << std::endl;
                throw 0;
            }
        } else {
            std::cout << "No InstantiateType!" << std::endl;
            throw 0;
        }
    }
}

#endif /* CMINSTANTIATESOURCE_H */
