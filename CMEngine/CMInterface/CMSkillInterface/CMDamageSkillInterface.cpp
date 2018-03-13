/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMDamageSkillInterface.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月13日
*   描    述：
*
================================================================*/

#include "CMDamageSkillInterface.h"
#include "../../CMSkill/CMDamageSkill.h"

namespace cmengine
{
    CMDamageSkill CMDamageSkillInterface::GetSkill()
    {
        return *skill;
    }
}

