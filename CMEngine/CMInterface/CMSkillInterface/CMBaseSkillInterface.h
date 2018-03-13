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
#include "../../CMSprite/CMSprite.h"

namespace cmengine
{
    class CMBaseSkillInterface
    {
    public:
        CMBaseSkillInterface(CMSprite* caster_, std::vector<CMSprite*> targetVector_)
            : caster(caster_), targetVector(targetVector_) {}
        
        CMSprite GetCaster();
        std::vector<CMSprite> GetTargetVector();

    private:
        CMSprite* caster;
        std::vector<CMSprite*> targetVector;
    };
}

#endif /* CMBASESKILLINTERFACE_H */
