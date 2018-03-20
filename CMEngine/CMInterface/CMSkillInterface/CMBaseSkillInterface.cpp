/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseSkillInterface.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月13日
*   描    述：
*
================================================================*/

#include "CMBaseSkillInterface.h"

namespace cmengine
{
    using namespace std;

    CMSprite CMBaseSkillInterface::GetCaster()
    {
        return *caster;
    }

    vector<CMSprite> CMBaseSkillInterface::GetTargetVector()
    {
        vector<CMSprite> vec;
        for (CMSprite *sp : targetVector) {
            vec.push_back(*sp);
        }
        return vec;
    }
}
