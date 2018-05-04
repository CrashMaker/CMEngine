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
#include "../CMSourceManager/CMInstantiateSource.h"
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

        std::vector<CMBaseSprite*> GetFirstTeam() const {return firstTeam;}
        std::vector<CMBaseSprite*> GetSecondTeam() const {return secondTeam;}

        void SkillCast()
        {
            CMBaseSprite *sp = firstTeam[0]; 
            BaseSkill sk = CMInstantiateSource::InstantiateSkill(sp->skillVec[0]);
            CMBaseSkill* skill = sk.get();
            skill->caster = sp;
            skill->delegate = this;
            skill->Cast();
        }

    private:
        std::vector<CMBaseSprite*> firstTeam;
        std::vector<CMBaseSprite*> secondTeam;
    };
}

#endif /* CMBATTLESCENE_H */
