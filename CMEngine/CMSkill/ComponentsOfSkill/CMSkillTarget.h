/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkillTarget.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月26日
*   描    述：技能组件，单体目标
*
================================================================*/

#ifndef CMSKILLTARGET_H
#define CMSKILLTARGET_H

#include "CMSkillDelegate.h"

namespace cmengine
{
    class CMBaseSprite;

    class CMSkillTarget
    {
    public:
        virtual ~CMSkillTarget() {}
        
        // 获取目标
        const CMBaseSprite* GetTarget() {return target;}

    protected:
        // 执行选取操作
        void Obtain(CMSkillDelegate* delegate, CMBaseSprite* caster)
        {
            target = nullptr;
            if (!delegate) return;

            target = delegate->ObtainTarget(caster);
        }
        
    protected:
        CMBaseSprite* target = nullptr;         // 技能目标
    };
}

#endif /* CMSKILLTARGET_H */
