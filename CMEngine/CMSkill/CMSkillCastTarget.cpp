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

    void CMSkillCastTarget::Cast(CMBaseSprite* caster) 
    {
        if (SkillCastTargetTypeSelf == targetType) {
            vector<CMBaseSprite*> targetVector = {caster};
            CastWithTargetVector(caster, targetVector);
        } else if (SkillCastTargetTypeSingle == targetType) {
            if (!delegate) return;
            vector<CMBaseSprite*> targetVector = { 
                delegate->GetTarget()
            };
            CastWithTargetVector(caster, targetVector);
        } else if (SkillCastTargetTypeMultiple == targetType) {
            if (!delegate) return;
            vector<CMBaseSprite*> targetVector = delegate->GetTargetVector();
            CastWithTargetVector(caster, targetVector);
        }
    }

    void CMSkillCastTarget::CastWithSelf(CMBaseSprite* caster)
    {
        vector<CMBaseSprite*> targetVector = {caster};
        CastWithTargetVector(caster, targetVector);
    }

    void CMSkillCastTarget::CastWithTarget(CMBaseSprite* caster, CMBaseSprite* target)
    {
        vector<CMBaseSprite*> targetVector = {target};
        CastWithTargetVector(caster, targetVector);
    }
}
