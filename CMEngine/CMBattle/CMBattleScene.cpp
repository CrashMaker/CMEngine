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
#include "../CMSkill/CMHealSkill.h"
#include "../CMSkill/CMHitSkill.h"

#include <iostream>

namespace cmengine
{
    /* ==========私有函数========== */
    
    // 给SpriteDelegate赋值
    void CMBattleScene::SetupSpriteDelegate(std::vector<CMBaseSprite*> team)
    {
        for (CMBaseSprite* sprite : team) {
            sprite->delegate = this;
        }
    }

    /* ==========公有函数========== */

    // 战斗开始
    void CMBattleScene::Battle()
    {
        BattleBegan();
        BattleRound();
        BattleEnd();
    }

    /* ==========战斗中的各个阶段========== */
    
    // 战斗开始阶段
    void CMBattleScene::BattleBegan()
    {
        battleStateType = BattleStateType::BattleStateTypeBattleing;
        battleLog.PushLog("战斗开始");
    }

    // 战斗回合阶段
    void CMBattleScene::BattleRound()
    {
        bool action = true;
        while(action) {
            CMBaseSprite* sprite = RoundBegan();
            RoundAction(sprite);
            RoundEnd(sprite);
            action = RoundJudgeResult();
        }
    }

    // 战斗结束阶段
    void CMBattleScene::BattleEnd()
    {
        battleLog.PushLog("战斗结束");
    }

    /* ==========回合中的各个步骤========== */

    // 回合开始步骤
    CMBaseSprite* CMBattleScene::RoundBegan()
    {
        CMBaseSprite* sprite = battleQueue.GetActionSprite();
        battleLog.PushLog(sprite->GetName() + "的回合开始");
        return sprite;
    }

    // 回合行动步骤
    void CMBattleScene::RoundAction(CMBaseSprite* sprite)
    {   
        int skillIndex = battleChoose.ChooseSkillIndexFromSprite(sprite);
        BaseSkill sk = CMInstantiateSource::InstantiateSkill(skillIndex);
        CMBaseSkill* skill = sk.get();
        skill->caster = sprite;
        skill->delegate = this;
        skill->Cast();
    }

    // 回合结束步骤
    void CMBattleScene::RoundEnd(CMBaseSprite* sprite)
    {
        battleLog.PushLog(sprite->GetName() + "的回合结束");
    }
    
    // 判断战斗结果步骤
    bool CMBattleScene::RoundJudgeResult()
    {
        // 一号队伍是否全部死亡
        bool firstTeamAllDead = true;
        for (int i=0; i<(int)firstTeam.size(); i++) {
            CMBaseSprite* sprite = firstTeam[i];
            if (sprite->GetStateType() == SpriteStateType::SpriteStateTypeLife) {
                firstTeamAllDead = false;
                break;
            }
        } 

        // 一号队伍是否全部死亡
        bool secondTeamAllDead = true;
        for (int i=0; i<(int)secondTeam.size(); i++) {
            CMBaseSprite* sprite = secondTeam[i];
            if (sprite->GetStateType() == SpriteStateType::SpriteStateTypeLife) {
                secondTeamAllDead = false;
                break;
            }
        } 

        // 判断结果
        if (!firstTeamAllDead && secondTeamAllDead) {
            // 一号队伍胜利，战斗结束
            battleLog.PushLog("一号队伍胜利");
            battleStateType = BattleStateType::BattleStateTypeFirstTeamWin;
            return false;
        } else if (firstTeamAllDead && !secondTeamAllDead) {
            // 二号队伍胜利，战斗结束
            battleLog.PushLog("二号队伍胜利");
            battleStateType = BattleStateType::BattleStateTypeSecondTeamWin;
            return false;
        } else if (firstTeamAllDead && secondTeamAllDead) {
            // 平局，战斗结束
            battleLog.PushLog("平局");
            battleStateType = BattleStateType::BattleStateTypeDraw;
            return false;
        } else {
            // 未分胜负，战斗继续
            battleStateType = BattleStateType::BattleStateTypeBattleing;
            return true;
        }
    }

    /* ==========实现的协议CMSpriteDelegate========== */

    // 角色受到伤害
    void CMBattleScene::SpriteHasDamage(CMBaseSprite* sprite, int point)
    {
        std::string log = sprite->GetName() + "受到" + std::to_string(point) + "点伤害";
        battleLog.PushLog(log);
    }

    // 角色受到治疗
    void CMBattleScene::SpriteHasHeal(CMBaseSprite* sprite, int point)
    {
        std::string log = sprite->GetName() + "恢复" + std::to_string(point) + "点生命值";
        battleLog.PushLog(log);
    }

    // 角色状态改变
    void CMBattleScene::SpriteHasStateTypeChange(CMBaseSprite* sprite)
    {
        battleLog.PushLogWithSpriteStateTypeChange(sprite);
    }

    /* ==========实现的协议CMSkillDelegate========== */
    
    // 单体选择目标
    CMBaseSprite* CMBattleScene::SkillObtainTarget(CMBaseSprite* caster)
    {
        return battleChoose.ObtainTarget(caster);
    }

    // 技能正式释放前预备阶段
    void CMBattleScene::SkillPrepareCast(CMBaseSkill* skill)
    {
        skill->GetName();
    }

    // 技能准备被施放
    void CMBattleScene::SkillWillCast(CMBaseSkill* skill)
    {
        battleLog.PushLogWithSkillCast(skill); 
    }

    // 技能已经被施放
    void CMBattleScene::SkillHasCast(CMBaseSkill* skill)
    {
        skill->GetName();
    }
}
