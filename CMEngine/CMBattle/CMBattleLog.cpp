/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleLog.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月02日
*   描    述：
*
================================================================*/

#include "CMBattleLog.h"
#include "../CMSkill/CMHealSkill.h"
#include "../CMSkill/CMHitSkill.h"
#include "../CMSprite/CMBaseSprite.h"

namespace cmengine
{
    /* ==========私有函数========== */
    
    // 有目标的技能打印的战斗日志
    std::string CMBattleLog::CreateLogWithSkillTarget(CMSkillTarget* target, 
            std::string casterName, std::string skillName)
    {
        std::string log = casterName 
            + "对" + target->GetTarget()->GetName()
            + "使用技能" + skillName;

        return log;
    }

    /* ==========公有函数========== */

    // 添加日志
    void CMBattleLog::PushLog(std::string log)
    {
        if (log.size() > 0) {
            std::cout << "战斗日志：" << log << std::endl;
        }
    }

    // 根据技能释放添加日志
    void CMBattleLog::PushLogWithSkillCast(CMBaseSkill* skill)
    {
        std::string log = "";
        
        if (typeid(CMHitSkill) == typeid(*skill)) {
            CMHitSkill* sk = (CMHitSkill*)skill;
            log = CreateLogWithSkillTarget(sk, skill->caster->GetName(), skill->GetName());
        } else if (typeid(CMHealSkill) == typeid(*skill)) {
            CMHealSkill* sk = (CMHealSkill*)skill;
            log = CreateLogWithSkillTarget(sk, skill->caster->GetName(), skill->GetName());
        } else {
            log = skill->caster->GetName() + "使用技能" + skill->GetName();
        }

        PushLog(log);
    }

    // 根据角色状态变化打印日志
    void CMBattleLog::PushLogWithSpriteStateTypeChange(CMBaseSprite* sprite)
    {
        std::string log = "";

        if(SpriteStateTypeLife == sprite->GetStateType()) {
            log = sprite->GetName() + "复活";
        } else if(SpriteStateTypeDead == sprite->GetStateType()) {
            log = sprite->GetName() + "死亡";
        }

        PushLog(log);
    }
}
