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
#include <iostream>
#include <memory>

namespace cmengine
{
    template <class T>
    class CMInstantiateSource
    {
    public:
        static T InstantiateSkill(MapKey key);
        static T InstantiateSprite(MapKey key);
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
    T CMInstantiateSource<T>::InstantiateSprite(MapKey key)
    {
        CreateSpriteFun f = CMSourceManager::GetCreateSpriteFunWithKey(key);
        BaseSprite s = f();
        CMBaseSprite* sprite = &*s;
        
        if (typeid(T) == typeid(*sprite)) {
            return *((T*)sprite);
        } else {
            std::cout << "Instantiate sprite error!" << std::endl;
            throw 0;
        }
    }

}

#endif /* CMINSTANTIATESOURCE_H */
