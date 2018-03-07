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
#include "../CMSkill/CMSkill.h"
#include <iostream>
#include <memory>

namespace cmengine
{
    template <class T>
    class CMInstantiateSource
    {
    public:
        static std::unique_ptr<T> InstantiateSkill(MapKey key);
    };

    template <class T>
    std::unique_ptr<T> CMInstantiateSource<T>::InstantiateSkill(MapKey key)
    {
        CreateSkillFun f = CMSourceManager::GetCreateSkillFunWithKey(key);
        std::unique_ptr<T> t = f();
        
       throw 0; 
        // if (typeid(std::unique_ptr<T>) == typeid(baseSkill)) {
        //     return (std::unique_ptr<T>)baseSkill;
        // } else {
        //     std::cout << "Instantiate Skill error!" << std::endl;
        //     throw 0;
        // }
    }
}

#endif /* CMINSTANTIATESOURCE_H */
