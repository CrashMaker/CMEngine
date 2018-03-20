/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkillCastTarget.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月09日
*   描    述：技能类需要继承此类来实现选取目标施放的功能
*
================================================================*/

#ifndef CMSKILLCASTTARGET_H
#define CMSKILLCASTTARGET_H

#include "../CMGeneral/CMGeneralSkillType.h"
#include <vector>

namespace cmengine
{
    class CMBaseSprite;

    class CMSkillCastTargetDelegate
    {
    public:
        virtual CMBaseSprite* GetTarget() = 0;
        virtual std::vector<CMBaseSprite*> GetTargetVector() = 0;
    };
    
    class CMSkillCastTarget
    {
    public:
        CMSkillCastTarget(SkillCastTargetType targetType_) : targetType(targetType_) {}
        virtual ~CMSkillCastTarget() {}

        // 目标的提供类需要继承CMSkillCastTargetDelegate，并对此变量赋值
        CMSkillCastTargetDelegate* delegate = nullptr;

        // 根据目标类型选取目标施放
        void Cast(CMBaseSprite* caster);
        // 对自身施放
        void CastWithSelf(CMBaseSprite* caster);
        // 对单个目标施放
        void CastWithTarget(CMBaseSprite* caster, CMBaseSprite* target);
        // 对多个目标施放
        virtual void CastWithTargetVector(CMBaseSprite* caster, std::vector<CMBaseSprite*> targetVector) = 0;
    private:
        SkillCastTargetType targetType;         // 目标类型
    };
}

#endif /* CMSKILLCASTTARGET_H */
