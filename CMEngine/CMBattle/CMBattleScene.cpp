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

#include <iostream>

namespace cmengine
{
    /* ==========战斗阶段控制========== */

    // 战斗开始
    void CMBattleScene::Start(CMBattleLog* battleLog_)
    {
        battleLog = battleLog_;

        bool action = true;

        while(action) {
            ActionStage(firstTeam[0]);
            
            CMBaseSprite* sprite = secondTeam[0];
            action = !(sprite->GetStateType() == SpriteStateTypeDead);
        }        

        SaveBattleLog("战斗结束");
    }

    // 行动阶段
    void CMBattleScene::ActionStage(CMBaseSprite* sprite)
    {
        BaseSkill sk = CMInstantiateSource::InstantiateSkill(sprite->skillVec[0]);
        CMBaseSkill* skill = sk.get();
        skill->caster = sprite;
        skill->delegate = this;
        skill->Cast(); 
    }

    /* ==========实现的协议========== */

    // 选取目标
    CMBaseSprite* CMBattleScene::ObtainTarget()
    {
        return secondTeam[0];
    }
}
