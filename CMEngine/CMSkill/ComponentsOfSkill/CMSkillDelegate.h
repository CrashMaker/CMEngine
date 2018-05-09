/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkillDelegate.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月27日
*   描    述：技能协议类，需要战斗场景来实现方法
*
================================================================*/

#ifndef CMSKILLDELEGATE_H
#define CMSKILLDELEGATE_H

namespace cmengine
{
    class CMBaseSprite;
    class CMSkillTarget;
    class CMBaseSkill;

    class CMSkillDelegate
    {
    public:
        // 单体选择目标
        virtual CMBaseSprite* ObtainTarget(CMBaseSprite* caster) = 0;
        // 技能施放
        virtual void SkillHasCast(CMBaseSkill* skill) = 0;
        // 技能施放，有目标 
        virtual void SkillHasCastWithTarget(CMBaseSkill* skill, CMSkillTarget* target) = 0;
    };
}

#endif /* CMSKILLDELEGATE_H */
