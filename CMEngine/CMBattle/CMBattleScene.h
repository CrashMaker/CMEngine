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

#include <vector>

namespace cmengine
{
    class CMBattleScene : public CMSkillDelegate 
    {
    public:
        CMBattleScene(std::vector<CMBaseSprite*> firstTeam_, std::vector<CMBaseSprite*> secondTeam_) 
            : firstTeam(firstTeam_), secondTeam(secondTeam_) {}
        virtual ~CMBattleScene() {}
    
        virtual CMBaseSprite* ObtainTarget();

    private:
        std::vector<CMBaseSprite*> firstTeam;
        std::vector<CMBaseSprite*> secondTeam;
    };
}

#endif /* CMBATTLESCENE_H */
