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
#include <iostream>
#include <memory>

namespace cmengine
{
    template <class T>
    class CMInstantiateSource
    {
    public:
        static T InstantiateSkill(MapKey key);
        static T InstantiateHero(MapKey key);
    };

    template <class T>
    T CMInstantiateSource<T>::InstantiateSkill(MapKey key)
    {
        CreateSkillFun f = CMSourceManager::GetCreateSkillFunWithKey(key);
        BaseSkill s = f();
        CMBaseSkill* skill = &*s;
        
        if (typeid(T) == typeid(*skill)) {
            return *((T*)skill);
        } else {
            std::cout << "Instantiate skill error!" << std::endl;
            throw 0;
        }
    }

    template <class T>
    T CMInstantiateSource<T>::InstantiateHero(MapKey key)
    {
        CreateHeroFun f = CMSourceManager::GetCreateHeroFunWithKey(key);
        HeroSprite s = f();
        CMHeroSprite* hero = &*s;
        
        if (typeid(T) == typeid(*hero)) {
            return *((T*)hero);
        } else {
            std::cout << "Instantiate hero error!" << std::endl;
            throw 0;
        }
    }
}

#endif /* CMINSTANTIATESOURCE_H */
