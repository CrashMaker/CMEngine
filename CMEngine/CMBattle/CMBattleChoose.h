/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleChoose.h
*   创 建 者：CrashMaker
*   创建日期：2018年05月07日
*   描    述：
*
================================================================*/

#ifndef CMBATTLECHOOSE_H
#define CMBATTLECHOOSE_H

#include "../CMSprite/CMBaseSprite.h"
#include "../CMSkill/ComponentsOfSkill/CMSkillDelegate.h"
#include <vector>

namespace cmengine
{
    class CMBaseSprite;

    enum BattleChooseTeam {
        BattleChooseTeamOfSelf,           // 自身队伍
        BattleChooseTeamOfAnother,        // 对方队伍
        BattleChooseTeamOfAll             // 双方队伍
    };

    class CMBattleChoose : public CMSkillDelegate
    {
    public:
        CMBattleChoose(std::vector<CMBaseSprite*> firstTeam_, std::vector<CMBaseSprite*> secondTeam_) 
            : firstTeam(firstTeam_), secondTeam(secondTeam_) {}
        virtual ~CMBattleChoose() {}

        virtual CMBaseSprite* ObtainTarget(CMBaseSprite* caster);
    
        // 选择角色的技能，返回技能编号
        int ChooseSkillIndexFromSprite(CMBaseSprite* sprite);

    private:
        // 根据施法者获取指定的队伍
        std::vector<CMBaseSprite*> GetTeamWithCaster(CMBaseSprite* sprite, BattleChooseTeam chooseTeam);

    private:
        std::vector<CMBaseSprite*> firstTeam;
        std::vector<CMBaseSprite*> secondTeam;
    };
}

#endif /* CMBATTLECHOOSE_H */
