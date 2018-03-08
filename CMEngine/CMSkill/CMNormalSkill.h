/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMNormalSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月08日
*   描    述：有施放者，无目标，无伤害的技能
*
================================================================*/

#ifndef CMNORMALSKILL_H
#define CMNORMALSKILL_H

#include "CMBaseSkill.h"
#include <functional>

namespace cmengine
{
    class CMSprite;
    class CMNormalSkill;
    typedef std::function<void(CMNormalSkill& skill, CMSprite& caster)> NormalSkillLogicFun;

    class CMNormalSkill : public CMBaseSkill
    {
    public:
        CMNormalSkill(std::string name, NormalSkillLogicFun logicFun_) 
            : CMBaseSkill(name), logicFun(logicFun_) {}
        virtual ~CMNormalSkill() {}

        void Cast(CMSprite& caster) {logicFun(*this, caster);} 
    private:
        NormalSkillLogicFun logicFun;
    };
}

#endif /* CMNORMALSKILL_H */
