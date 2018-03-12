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

#include <vector>

namespace cmengine
{
    class CMSprite;

    enum SkillCastTargetType {
        SkillCastTargetTypeSelf,            // 自身
        SkillCastTargetTypeSingle,          // 单一目标
        SkillCastTargetTypeMultiple,        // 多个目标
    };

    class CMSkillCastTargetDelegate
    {
    public:
        virtual CMSprite* GetTarget() = 0;
        virtual std::vector<CMSprite*> GetTargetVector() = 0;
    };
    
    class CMSkillCastTarget
    {
    public:
        CMSkillCastTarget(SkillCastTargetType targetType_) : targetType(targetType_) {}
        virtual ~CMSkillCastTarget() {}

        // 根据目标类型选取目标施放
        void Cast(CMSprite* caster);
        // 对自身施放
        void CastWithSelf(CMSprite* caster);
        // 对单个目标施放
        void CastWithTarget(CMSprite* caster, CMSprite* target);
        // 对多个目标施放
        virtual void CastWithTargetVector(CMSprite* caster, std::vector<CMSprite*> targetVector) = 0;
    private:
        CMSkillCastTargetDelegate* delegate = nullptr;
        SkillCastTargetType targetType;         // 目标类型
    };
}

#endif /* CMSKILLCASTTARGET_H */
