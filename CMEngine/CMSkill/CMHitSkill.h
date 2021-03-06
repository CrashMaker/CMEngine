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

namespace cmengine
{
    enum struct HitSkillAttackType { 
        HitSkillAttackTypeMelee,        // 近战
        HitSkillAttackTypeRemote,       // 远程
    };

    enum struct HitSkillDamageType {
        HitSkillDamageTypePhysical,     // 物理伤害
        HitSkillDamageTypeMagic,        // 魔法伤害
    };
    
    class CMHitSkill : public CMBaseSkill, public CMSkillTarget
    {
    public:
        CMHitSkill(std::string name_, SkillLogicFun logicFun_, 
                HitSkillAttackType attackType_, HitSkillDamageType damageType_) 
            : CMBaseSkill(name_, logicFun_), attackType(attackType_), damageType(damageType_) {}
        virtual ~CMHitSkill() {}
    
        // 打击类型
        HitSkillAttackType GetAttackType() const {return attackType;}

        // 伤害类型
        HitSkillDamageType GetDamageType() const {return damageType;}

    public:
        float mulReviseValue = 1;       // 乘数修正值
        int addReviseValue = 0;         // 加数修正值

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
            // 打击公式
            int attackPoint = 0;
            int defensePoint = 0;
            if (HitSkillDamageType::HitSkillDamageTypePhysical == damageType) {
                attackPoint = caster->GetCurrentAttribute().GetAttack();
                defensePoint = target->GetCurrentAttribute().GetDefense();
            } else if (HitSkillDamageType::HitSkillDamageTypeMagic == damageType) {
                attackPoint = caster->GetCurrentAttribute().GetMagicAtk();
                defensePoint = target->GetCurrentAttribute().GetMagicDef();
            }
            int point = (attackPoint + addReviseValue - defensePoint) * mulReviseValue;
            target->ObtainDamage(point);
        }

    private:
        HitSkillAttackType attackType;     // 打击类型
        HitSkillDamageType damageType;     // 伤害类型
    };
}

#endif /* CMHITSKILL_H */
