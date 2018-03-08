/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月07日
*   描    述：基础技能类，所有技能类都必须继承这个类
*
================================================================*/

#ifndef CMBASESKILL_H
#define CMBASESKILL_H

#include <string>

namespace cmengine
{
    class CMBaseSkill
    {
    public:
        explicit CMBaseSkill (std::string name_) : name(name_) {}
        virtual ~CMBaseSkill () {}
    
        std::string GetName() const {return name;}
    private:
        std::string name;
    };
}

#endif /* CMBASESKILL_H */
