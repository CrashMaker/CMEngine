/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMAttack.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#include "CMAttack.h"

namespace cmengine
{
    void CMAttack::action()
    {
        skill.model.logicFun(caster.model, target.model, skill.model);
    }
}
