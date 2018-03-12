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
#include <functional>

namespace cmengine
{
    class CMSprite;
    class CMNormalSkill;
    class CMNormalSkillInterface;
    typedef std::function<void(CMNormalSkillInterface interface)> NormalSkillLogicFun;

    class CMNormalSkillInterface
    {
    public:
        CMNormalSkillInterface(CMSprite* caster_, std::vector<CMSprite*> targetVector_)
            : caster(caster_), targetVector(targetVector_) {}
        
        CMSprite GetCaster();
        std::vector<CMSprite> GetTargetVector();

    private:
        CMSprite* caster;
        std::vector<CMSprite*> targetVector;
    };

    class CMNormalSkill : public CMBaseSkill, public CMSkillCastTarget
    {
    public:
        CMNormalSkill(std::string name, SkillCastTargetType targetType, NormalSkillLogicFun logicFun_) 
            : CMBaseSkill(name), CMSkillCastTarget(targetType), logicFun(logicFun_) {}
        virtual ~CMNormalSkill() {}

        virtual void CastWithTargetVector(CMSprite* caster, std::vector<CMSprite*> targetVector) {
            CMNormalSkillInterface interface = CMNormalSkillInterface(caster, targetVector);
            logicFun(interface);
        }
    private:
        NormalSkillLogicFun logicFun;
    };
}

#endif /* CMNORMALSKILL_H */
