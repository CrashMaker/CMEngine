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
    class CMBaseSprite;

    class CMSkillCastTargetDelegate
    {
    public:
        virtual CMBaseSprite* ObtainCaster() = 0;
        virtual CMBaseSprite* ObtainTarget() = 0;
        virtual std::vector<CMBaseSprite*> ObtainTargetVector() = 0;
    };

    enum SkillCastTargetType {
        SkillCastTargetTypeSelf,            // 自身
        SkillCastTargetTypeSingle,          // 单一目标
        SkillCastTargetTypeMultiple,        // 多个目标
    };
    
    class CMSkillCastTarget
    {
    public:
        CMSkillCastTarget(SkillCastTargetType targetType_) : targetType(targetType_) {}
        virtual ~CMSkillCastTarget() {}

        // 目标的提供类需要继承CMSkillCastTargetDelegate，并对此变量赋值
        CMSkillCastTargetDelegate* delegate = nullptr;

        CMBaseSprite* GetCaster() {return caster;}
        CMBaseSprite* GetTarget() {return target;}
        std::vector<CMBaseSprite*> GetTargetVector() {return targetVector;}

    protected:
        // 获取施放者和目标
        void Obtain()
        {
            caster = nullptr;
            target = nullptr;
            targetVector.clear();
            if (!delegate) return;

            if (SkillCastTargetTypeSelf == targetType) {
                caster = delegate->ObtainCaster();
                target = delegate->ObtainCaster();
            } else if (SkillCastTargetTypeSingle == targetType) {
                caster = delegate->ObtainCaster();
                target = delegate->ObtainTarget();
            } else if (SkillCastTargetTypeMultiple == targetType) {
                caster = delegate->ObtainCaster();
                targetVector = delegate->ObtainTargetVector();
            }
        }

    private:
        SkillCastTargetType targetType;         // 目标类型
        CMBaseSprite* caster = nullptr;         // 技能施放者
        CMBaseSprite* target = nullptr;         // 技能目标
        // 技能目标，当targetType == SkillCastTargetTypeMultiple有值;
        std::vector<CMBaseSprite*> targetVector = {};
    };
}

#endif /* CMSKILLCASTTARGET_H */
