/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月07日
*   描    述：基础技能类，所有技能类都必须继承这个类
*
================================================================*/

#ifndef CMBASESKILL_H
#define CMBASESKILL_H

#include "ComponentsOfSkill/CMSkillDelegate.h"
#include "../CMSprite/CMBaseSprite.h"

#include <string>
#include <functional>

namespace cmengine
{
    class CMBaseSkill;
    typedef std::function<void(CMBaseSkill* skill)> SkillLogicFun;
    
    class CMBaseSkill
    {
    public:
        CMBaseSkill(std::string name_, SkillLogicFun logicFun_) 
            : name(name_), logicFun(logicFun_) {}
        virtual ~CMBaseSkill () {}
    
        // 获取技能名称
        std::string GetName() const {return name;}
        // 执行
        void Cast() {
            if (delegate) delegate->SkillPrepareCast(this);
            Prepare();
            if (delegate) delegate->SkillWillCast(this);
            CastLogic(); 
            if (delegate) delegate->SkillHasCast(this);
        }

    public:
        CMBaseSprite* caster = nullptr;             // 施法者
        CMSkillDelegate* delegate = nullptr;        // 协议对象

    protected:
        // 执行技能逻辑前的准备工作
        virtual void Prepare() {}
        // 执行技能逻辑
        virtual void CastLogic() {
            logicFun(this);
        }

    protected:
        std::string name;           // 技能名称
        SkillLogicFun logicFun;     // 技能逻辑
    };
}

#endif /* CMBASESKILL_H */
