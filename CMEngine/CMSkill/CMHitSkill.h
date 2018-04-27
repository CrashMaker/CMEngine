/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMHitSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月26日
*   描    述：单体打击技能
*
================================================================*/

#ifndef CMHITSKILL_H
#define CMHITSKILL_H

#include "CMBaseSkill.h"
#include "ComponentsOfSkill/CMSkillTarget.h"
#include "../CMSprite/CMBaseSprite.h"
#include "../CMGeneral/CMGeneralSkillType.h"

namespace cmengine
{
    class CMHitSkill : public CMBaseSkill, public CMSkillTarget
    {
    public:
        CMHitSkill(std::string name_, SkillLogicFun logicFun_, 
                SkillAttackType attackType_, SkillDamageType damageType_) 
            : CMBaseSkill(name_, logicFun_), attackType(attackType_), damageType(damageType_) {}
        virtual ~CMHitSkill() {}
    
        void Cast() 
        {
            Obtain(delegate);
            if (target) {
                CMBaseSkill::Cast();
                // 打击公式
                int attackPoint = 0;
                int defensePoint = 0;
                if (SkillDamageTypePhysical == damageType) {
                    attackPoint = caster->GetCurrentAttribute().GetAttack();
                    defensePoint = target->GetCurrentAttribute().GetDefense();
                } else if (SkillDamageTypeMagic == damageType) {
                    attackPoint = caster->GetCurrentAttribute().GetMagicAtk();
                    defensePoint = target->GetCurrentAttribute().GetMagicDef();
                }
                int point = (attackPoint + addReviseValue - defensePoint) * mulReviseValue;
                target->ObtainDamage(point);
            }
        }

    public:
        float mulReviseValue = 1;     // 乘数修正值
        int addReviseValue = 0;     // 加数修正值

    private:
        SkillAttackType attackType;     // 打击类型
        SkillDamageType damageType;     // 伤害类型
    };
}

#endif /* CMHITSKILL_H */
