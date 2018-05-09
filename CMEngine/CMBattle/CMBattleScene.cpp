/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleScene.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年04月27日
*   描    述：
*
================================================================*/

#include "CMBattleScene.h"
#include "../CMSourceManager/CMInstantiateSource.h"
#include "../CMSkill/ComponentsOfSkill/CMSkillTarget.h"

#include <iostream>

namespace cmengine
{
    // 给SpriteDelegate赋值
    void CMBattleScene::SetupSpriteDelegate(std::vector<CMBaseSprite*> team)
    {
        for (CMBaseSprite* sprite : team) {
            sprite->delegate = this;
        }
    }

    // 判断战斗结果
    bool CMBattleScene::JudgeBattleResult()
    {
        // 一号队伍是否全部死亡
        bool firstTeamAllDead = true;
        for (int i=0; i<(int)firstTeam.size(); i++) {
            CMBaseSprite* sprite = firstTeam[i];
            if (sprite->GetStateType() == SpriteStateTypeLife) {
                firstTeamAllDead = false;
                break;
            }
        } 

        // 一号队伍是否全部死亡
        bool secondTeamAllDead = true;
        for (int i=0; i<(int)secondTeam.size(); i++) {
            CMBaseSprite* sprite = secondTeam[i];
            if (sprite->GetStateType() == SpriteStateTypeLife) {
                secondTeamAllDead = false;
                break;
            }
        } 

        // 判断结果
        if (!firstTeamAllDead && secondTeamAllDead) {
            // 一号队伍胜利，战斗结束
            SaveBattleLog("一号队伍胜利");
            battleStateType = BattleStateTypeFirstTeamWin;
            return false;
        } else if (firstTeamAllDead && !secondTeamAllDead) {
            // 二号队伍胜利，战斗结束
            SaveBattleLog("二号队伍胜利");
            battleStateType = BattleStateTypeSecondTeamWin;
            return false;
        } else if (firstTeamAllDead && secondTeamAllDead) {
            // 平局，战斗结束
            SaveBattleLog("平局");
            battleStateType = BattleStateTypeDraw;
            return false;
        } else {
            // 未分胜负，战斗继续
            battleStateType = BattleStateTypeBattleing;
            return true;
        }
    }

    /* ==========战斗阶段控制========== */

    // 战斗开始
    void CMBattleScene::Start(CMBattleLog* battleLog_)
    {
        battleLog = battleLog_;
        battleStateType = BattleStateTypeBattleing;
        SaveBattleLog("战斗开始");

        bool action = true;
        while(action) {
            ActionStage(firstTeam[0]);
            // 判断战斗结果
            action = JudgeBattleResult();
        }

        SaveBattleLog("战斗结束");
    }

    // 行动阶段
    void CMBattleScene::ActionStage(CMBaseSprite* sprite)
    {
        int skillIndex = battleChoose.ChooseSkillIndexFromSprite(sprite);
        BaseSkill sk = CMInstantiateSource::InstantiateSkill(skillIndex);
        CMBaseSkill* skill = sk.get();
        skill->caster = sprite;
        skill->delegate = this;
        skill->Cast();
    }

    /* ==========实现的协议CMSpriteDelegate========== */

    // 角色受到伤害
    void CMBattleScene::SpriteHasDamage(CMBaseSprite* sprite, int point)
    {
        std::string log = sprite->GetName() + "受到" + std::to_string(point) + "点伤害";
        SaveBattleLog(log);
    }

    // 角色受到治疗
    void CMBattleScene::SpriteHasHeal(CMBaseSprite* sprite, int point)
    {
        std::string log = sprite->GetName() + "恢复" + std::to_string(point) + "点生命值";
        SaveBattleLog(log);
    }

    // 角色状态改变
    void CMBattleScene::SpriteHasStateTypeChange(CMBaseSprite* sprite, int stateType)
    {
        SpriteStateType type = (SpriteStateType)stateType;

        std::string log;
        if (SpriteStateTypeLife == type) {
            log = sprite->GetName() + "复活";
        } else if (SpriteStateTypeDead == type) {
            log = sprite->GetName() + "死亡";
        }
        SaveBattleLog(log);
    }

    /* ==========实现的协议CMSkillDelegate========== */
    
    // 选取目标
    CMBaseSprite* CMBattleScene::SkillObtainTarget(CMBaseSprite* caster)
    {
        return battleChoose.ObtainTarget(caster);
    }

    void CMBattleScene::SkillHasCast(CMBaseSkill* skill)
    {
        std::string log = skill->caster->GetName() + "使用技能" + skill->GetName();
        SaveBattleLog(log);
    }

    void CMBattleScene::SkillHasCastWithTarget(CMBaseSkill* skill, CMSkillTarget* target)
    {
        std::string log = skill->caster->GetName() 
            + "对" + target->GetTarget()->GetName()
            + "使用技能" + skill->GetName();
        SaveBattleLog(log);
    }
}
