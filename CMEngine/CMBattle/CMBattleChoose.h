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

    class CMBattleChoose : public CMSkillDelegate
    {
    public:
        CMBattleChoose(std::vector<CMBaseSprite*> firstTeam_, std::vector<CMBaseSprite*> secondTeam_) 
            : firstTeam(firstTeam_), secondTeam(secondTeam_) {}
        virtual ~CMBattleChoose() {}

        virtual CMBaseSprite* ObtainTarget();
    
        // 选择角色的技能，返回技能编号
        int ChooseSkillIndexFromSprite(CMBaseSprite* sprite);

    private:
        std::vector<CMBaseSprite*> firstTeam;
        std::vector<CMBaseSprite*> secondTeam;
    };
}

#endif /* CMBATTLECHOOSE_H */
