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
                battleStateType = BattleStateTypeBattleNotStart;
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
        void Battle(); 

    private:
        // 给SpriteDelegate赋值
        void SetupSpriteDelegate(std::vector<CMBaseSprite*> team);

    private:
        /* 战斗中的各个阶段 */
        // 战斗开始阶段
        void BattleBegan();
        // 战斗回合阶段
        void BattleRound();
        // 战斗结束阶段
        void BattleEnd();

    private:
        /* 回合中的各个步骤 */
        // 回合开始步骤
        CMBaseSprite* RoundBegan();
        // 回合行动步骤
        void RoundAction(CMBaseSprite* sprite);
        // 回合结束步骤
        void RoundEnd(CMBaseSprite* sprite);
        // 判断战斗结果步骤
        bool RoundJudgeResult();

    private:
        std::vector<CMBaseSprite*> firstTeam;       // 一号队伍
        std::vector<CMBaseSprite*> secondTeam;      // 二号队伍
        CMBattleChoose battleChoose;                // 选择控制
        CMBattleQueue battleQueue;                  // 战斗队列
        CMBattleLog battleLog;                      // 战斗日志
        BattleStateType battleStateType;            // 战斗状态
    };
}

#endif /* CMBATTLESCENE_H */
