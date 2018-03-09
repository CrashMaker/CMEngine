/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkillCastTarget.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月09日
*   描    述：
*
================================================================*/

#include "CMSkillCastTarget.h"

namespace cmengine
{
    using namespace std;

    void CMSkillCastTarget::Cast(CMSprite& caster) 
    {
        if (SkillCastTargetSelf == castTarget) {
            vector<CMSprite&> targetVector = {caster};
            CastWithTargetVector(caster, targetVector);
        } else if (SkillCastTargetSingle == castTarget) {
            if (!delegate) return;
            vector<CMSprite&> targetVector = { 
                delegate->GetTarget()
            };
            CastWithTargetVector(caster, targetVector);
        } else if (SkillCastTargetMultiple == castTarget) {
            if (!delegate) return;
            vector<CMSprite&> targetVector = delegate->GetTargetVector();
            CastWithTargetVector(caster, targetVector);
        }
    }

    void CMSkillCastTarget::CastWithSelf(CMSprite& caster)
    {
        vector<CMSprite&> targetVector = {caster};
        CastWithTargetVector(caster, targetVector);
    }

    void CMSkillCastTarget::CastWithTarget(CMSprite& caster, CMSprite& target)
    {
        vector<CMSprite&> targetVector = {target};
        CastWithTargetVector(caster, targetVector);
    }
}
