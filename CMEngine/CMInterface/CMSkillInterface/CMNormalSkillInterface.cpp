/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMNormalSkillInterface.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月12日
*   描    述：
*
================================================================*/

#include "CMNormalSkillInterface.h"
#include "../../CMSkill/CMNormalSkill.h"

namespace cmengine
{
    const CMNormalSkill* CMNormalSkillInterface::GetSkill()
    {
        return skill;
    }
}
