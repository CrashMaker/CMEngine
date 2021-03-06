/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMHealSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月03日
*   描    述：单体治疗法术
*
================================================================*/

#ifndef CMHEALSKILL_H
#define CMHEALSKILL_H

#include "CMBaseSkill.h"
#include "ComponentsOfSkill/CMSkillTarget.h"
#include "../CMSprite/CMBaseSprite.h"

namespace cmengine
{
    class CMHealSkill : public CMBaseSkill, public CMSkillTarget
    {
    public:
        CMHealSkill(std::string name_, SkillLogicFun logicFun_) 
            : CMBaseSkill(name_, logicFun_) {}
        virtual ~CMHealSkill() {}
    
    public:
        int healPoint = 0;              // 治疗点数

    private:
        // 执行技能逻辑前的准备工作
        virtual void Prepare()
        {
            Obtain(delegate, caster);
        }
        // 执行技能逻辑
        virtual void CastLogic() 
        {
            CMBaseSkill::CastLogic();
            // 治疗公式
            int point = healPoint;
            target->ObtainHeal(point);
        }
    };
}

#endif /* CMHEALSKILL_H */
