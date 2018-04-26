/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkillTarget.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月26日
*   描    述：技能组件，目标单体选择
*
================================================================*/

#ifndef CMSKILLTARGET_H
#define CMSKILLTARGET_H

#include <vector>

namespace cmengine
{
    class CMBaseSprite;

    class CMSkillTargetDelegate
    {
    public:
        virtual CMBaseSprite* ObtainTarget() = 0;
    };

    class CMSkillTarget
    {
    public:
        virtual ~CMSkillTarget() {}
        
        // 获取目标
        const CMBaseSprite* GetTarget() {return target;}

    public:
        // 目标的提供类需要继承CMSkillTargetDelegate，并对此变量赋值
        CMSkillTargetDelegate* delegate = nullptr;

    protected:
        // 执行选取操作
        void Obtain()
        {
            target = nullptr;
            if (!delegate) return;

            target = delegate->ObtainTarget();
        }
        
    protected:
        CMBaseSprite* target = nullptr;         // 技能目标
    };
}

#endif /* CMSKILLTARGET_H */
