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

#include "../CMSkill/ComponentsOfSkill/CMSkillTarget.h"

namespace cmengine
{
    class CMBattleScene : public CMSkillTargetDelegate 
    {
    public:
        CMBattleScene();
        virtual ~CMBattleScene() {}
    
    private:
        
    };
}

#endif /* CMBATTLESCENE_H */
