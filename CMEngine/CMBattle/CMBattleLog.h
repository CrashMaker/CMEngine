/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleLog.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月02日
*   描    述：
*
================================================================*/

#ifndef CMBATTLELOG_H
#define CMBATTLELOG_H

#include <string>
#include <iostream>

namespace cmengine
{
    class CMBaseSkill;
    class CMSkillTarget;

    class CMBattleLog
    {
    public:
        virtual ~CMBattleLog() {}
    
        // 添加日志
        void PushLog(std::string log);
        // 根据技能释放添加日志
        void PushLogWithSkill(CMBaseSkill* skill);

    private:
        // 有目标的技能打印的战斗日志
        std::string CreateLogWithSkillTarget(CMSkillTarget* target, 
                std::string casterName, std::string skillName);
    };
}

#endif /* CMBATTLELOG_H */
