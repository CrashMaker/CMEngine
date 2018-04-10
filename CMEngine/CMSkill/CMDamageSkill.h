/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMDamageSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月13日
*   描    述：伤害型技能
*
================================================================*/

#ifndef CMDAMAGESKILL_H
#define CMDAMAGESKILL_H

#include "CMBaseSkill.h"
#include "CMSkillCastTarget.h"

namespace cmengine
{
    class CMBaseSprite;

    // class CMDamageSkill : public CMBaseSkill, public CMSkillCastTarget
    // {
    // public:
    //     CMDamageSkill(std::string name, SkillCastTargetType targetType, 
    //             SkillAttackType attackType_, SkillDamageType damageType_, 
    //             NamageSkillInterface logicFun_) 
    //         : CMBaseSkill(name), CMSkillCastTarget(targetType), attackType(attackType_)
    //           , damageType(damageType_), logicFun(logicFun_) {}
    //     virtual ~CMDamageSkill () {}
    // 
    //     virtual void CastWithTargetVector(CMBaseSprite* caster, std::vector<CMBaseSprite*> targetVector) {
    //         CMDamageSkillInterface interface = CMDamageSkillInterface(caster, targetVector, this);
    //         logicFun(interface);
    //     }
    // private:
    //     SkillAttackType attackType;
    //     SkillDamageType damageType;
    //     NamageSkillInterface logicFun;
    // };
}

#endif /* CMDAMAGESKILL_H */
