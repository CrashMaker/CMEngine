/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMDamageSkillInterface.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月13日
*   描    述：
*
================================================================*/

#ifndef CMDAMAGESKILLINTERFACE_H
#define CMDAMAGESKILLINTERFACE_H

#include "CMBaseSkillInterface.h"

namespace cmengine
{
    class CMDamageSkill;

    class CMDamageSkillInterface : public CMBaseSkillInterface
    {
    public:
        CMDamageSkillInterface(CMBaseSprite* caster_, std::vector<CMBaseSprite*> targetVector_, CMDamageSkill *skill_)
            : CMBaseSkillInterface(caster_, targetVector_), skill(skill_) {}
        virtual ~CMDamageSkillInterface () {}
    
        const CMDamageSkill* GetSkill();
    private:
        CMDamageSkill* skill;
    };
}

#endif /* CMDAMAGESKILLINTERFACE_H */
