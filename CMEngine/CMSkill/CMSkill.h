/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSKILL_H
#define CMSKILL_H

#include "../CMGeneral/CMBaseType.h"
#include "../CMModel/CMSkillModel.h"
#include "../CMSprite/CMSprite.h"

namespace cmengine
{
    class CMSkill
    {
    private:
        CMSkillModel model;

    public:
        CMSkill(CreateSkillFun f);

        CMSkillModel GetModel() const {return model;}

        void Cast(CMSprite &caster, CMSprite &target) const;
    };
}

#endif /* CMSKILL_H */
