/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseSkillInterface.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月13日
*   描    述：
*
================================================================*/

#ifndef CMBASESKILLINTERFACE_H
#define CMBASESKILLINTERFACE_H

#include <vector>
#include "../../CMSprite/CMBaseSprite.h"

namespace cmengine
{
    class CMBaseSkillInterface
    {
    public:
        CMBaseSkillInterface(CMBaseSprite* caster_, std::vector<CMBaseSprite*> targetVector_)
            : caster(caster_), targetVector(targetVector_) {}
        virtual ~CMBaseSkillInterface () {}

        const CMBaseSprite* GetCaster();
        std::vector<const CMBaseSprite*> GetTargetVector();

    private:
        CMBaseSprite* caster;
        std::vector<CMBaseSprite*> targetVector;
    };
}

#endif /* CMBASESKILLINTERFACE_H */
