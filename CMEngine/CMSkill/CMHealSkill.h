/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMHealSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月03日
*   描    述：
*
================================================================*/

#ifndef CMHEALSKILL_H
#define CMHEALSKILL_H

#include "CMBaseSkill.h"
#include "CMSkillCastTarget.h"

namespace cmengine
{
    class CMHealSkill : public CMBaseSkill, public CMSkillCastTarget
    {
    public:
        CMHealSkill(std::string name_, SkillLogicFun logicFun_, SkillCastTargetType targetType_) 
            : CMBaseSkill(name_, logicFun_), CMSkillCastTarget(targetType_) {}
        virtual ~CMHealSkill() {}
    
        void Cast() 
        {
            Obtain();
            CMBaseSkill::Cast();
        }

    private:
        /* data */
    };
}

#endif /* CMHEALSKILL_H */
