/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleScene.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月27日
*   描    述：
*
================================================================*/

#ifndef CMBATTLESCENE_H
#define CMBATTLESCENE_H

#include "CMBattleLog.h"
#include "CMBattleChoose.h"
#include "CMBattleQueue.h"
#include "../CMSprite/CMBaseSprite.h"
#include "../CMSkill/CMBaseSkill.h"

namespace cmengine
{
    enum BattleStateType {
        BattleStateTypeBattleNotStart,  // 战斗未开始
        BattleStateTypeBattleing,       // 战斗中
        BattleStateTypeFirstTeamWin,    // 一号队伍获胜
        BattleStateTypeSecondTeamWin,   // 二号队伍获胜
        BattleStateTypeDraw             // 平局
    };

    class CMBattleScene : public CMSpriteDelegate, public CMSkillDelegate
    {
    public:
        CMBattleScene(std::vector<CMBaseSprite*> firstTeam_, std::vector<CMBaseSprite*> secondTeam_) 
            : firstTeam(firstTeam_), secondTeam(secondTeam_), battleChoose(firstTeam_, secondTeam_), 
              battleQueue(firstTeam_, secondTeam_) {
                SetupSpriteDelegate(firstTeam);
                SetupSpriteDelegate(secondTeam);
            }
        virtual ~CMBattleScene() {}

        virtual void SpriteHasDamage(CMBaseSprite* sprite, int point);
        virtual void SpriteHasHeal(CMBaseSprite* sprite, int point);
        virtual void SpriteHasStateTypeChange(CMBaseSprite* sprite, int stateType);

        virtual CMBaseSprite* SkillObtainTarget(CMBaseSprite* caster);
        virtual void SkillPrepareCast(CMBaseSkill* skill);
        virtual void SkillWillCast(CMBaseSkill* skill);
        virtual void SkillHasCast(CMBaseSkill* skill);
    
        // 战斗开始
        void Start(CMBattleLog* battleLog_ = nullptr); 

    private:
        // 给SpriteDelegate赋值
        void SetupSpriteDelegate(std::vector<CMBaseSprite*> team);
        // 行动阶段
        void ActionStage(CMBaseSprite* sprite);
        // 记录战斗日志
        void SaveBattleLog(std::string log) {
            if (battleLog && log.size() > 0) {
                battleLog->PushLog(log);
            }
        }
        // 判断战斗结果
        bool JudgeBattleResult();
        // 有目标的技能打印的战斗日志
        std::string CreateSkillCastLogWithTarget(CMSkillTarget* target, 
                std::string casterName, std::string skillName);
        // 战斗开始
        void BattleBegan();
        // 战斗结束
        void BattleEnd();

    private:
        std::vector<CMBaseSprite*> firstTeam;       // 一号队伍
        std::vector<CMBaseSprite*> secondTeam;      // 二号队伍
        CMBattleChoose battleChoose;                // 选择控制
        CMBattleQueue battleQueue;                  // 战斗队列

        // 战斗日志
        CMBattleLog* battleLog = nullptr;
        // 战斗状态
        BattleStateType battleStateType = BattleStateTypeBattleNotStart;
    };
}

#endif /* CMBATTLESCENE_H */
