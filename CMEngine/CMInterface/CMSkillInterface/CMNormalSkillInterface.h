/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMNormalSkillInterface.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月12日
*   描    述：
*
================================================================*/

#ifndef CMNORMALSKILLINTERFACE_H
#define CMNORMALSKILLINTERFACE_H

#include "CMBaseSkillInterface.h"

namespace cmengine
{
    class CMNormalSkill;

    class CMNormalSkillInterface : public CMBaseSkillInterface
    {
    public:
        CMNormalSkillInterface(CMBaseSprite* caster_, std::vector<CMBaseSprite*> targetVector_, CMNormalSkill *skill_)
            : CMBaseSkillInterface(caster_, targetVector_), skill(skill_) {}
        virtual ~CMNormalSkillInterface () {}
        
        const CMNormalSkill* GetSkill();
    private:
        CMNormalSkill* skill;
    };
}

#endif /* CMNORMALSKILLINTERFACE_H */
