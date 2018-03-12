/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMNormalSkill.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月12日
*   描    述：
*
================================================================*/

#include "CMNormalSkill.h"
#include "../CMSprite/CMSprite.h"

namespace cmengine
{
    using namespace std;

    CMSprite CMNormalSkillInterface::GetCaster()
    {
        return *caster;
    }

    vector<CMSprite> CMNormalSkillInterface::GetTargetVector()
    {
        vector<CMSprite> vec;
        for (CMSprite *sp : targetVector) {
            vec.push_back(*sp);
        }
        return vec;
    }
}
