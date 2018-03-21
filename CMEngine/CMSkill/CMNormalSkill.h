/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMNormalSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月08日
*   描    述：普通技能，直接改变目标的属性(治疗、削弱、强化等)
*
================================================================*/

#ifndef CMNORMALSKILL_H
#define CMNORMALSKILL_H

#include "CMBaseSkill.h"
#include "CMSkillCastTarget.h"

namespace cmengine
{
    class CMNormalSkill : public CMBaseSkill, public CMSkillCastTarget
    {
    public:
        CMNormalSkill(std::string name_, SkillLogicFun logicFun_, SkillCastTargetType targetType_) 
            : CMBaseSkill(name_, logicFun_), CMSkillCastTarget(targetType_) {}
        virtual ~CMNormalSkill() {}

        void Cast() 
        {
            Obtain();
            CMBaseSkill::Cast();
        }

    private:

    };
}

#endif /* CMNORMALSKILL_H */
