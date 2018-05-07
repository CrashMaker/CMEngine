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

#include "../CMSprite/CMBaseSprite.h"
#include "../CMSkill/CMBaseSkill.h"
#include "CMBattleLog.h"
#include <vector>

namespace cmengine
{
    enum BattleStateType {
        BattleStateTypeBattleNotStart,  // 战斗未开始
        BattleStateTypeBattleing,       // 战斗中
        BattleStateTypeFirstTeamWin,    // 一号队伍获胜
        BattleStateTypeSecondTeamWin,   // 二号队伍获胜
        BattleStateTypeDraw             // 平局
    };

    class CMBattleScene : public CMSkillDelegate 
    {
    public:
        CMBattleScene(std::vector<CMBaseSprite*> firstTeam_, std::vector<CMBaseSprite*> secondTeam_) 
            : firstTeam(firstTeam_), secondTeam(secondTeam_) {}
        virtual ~CMBattleScene() {}
    
        virtual CMBaseSprite* ObtainTarget();

        std::vector<CMBaseSprite*> GetFirstTeam() const {return firstTeam;}
        std::vector<CMBaseSprite*> GetSecondTeam() const {return secondTeam;}

        // 战斗开始
        void Start(CMBattleLog* battleLog_ = nullptr); 

    private:
        // 行动阶段
        void ActionStage(CMBaseSprite* sprite);
        // 记录战斗日志
        void SaveBattleLog(std::string log) {if (battleLog) {battleLog->PushLog(log);}}
        // 判断战斗结果
        bool JudgeBattleResult();

    private:
        std::vector<CMBaseSprite*> firstTeam;
        std::vector<CMBaseSprite*> secondTeam;

        // 战斗日志
        CMBattleLog* battleLog = nullptr;
        // 战斗状态
        BattleStateType battleStateType = BattleStateTypeBattleNotStart;
    };
}

#endif /* CMBATTLESCENE_H */
