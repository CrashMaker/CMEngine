/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SkillWave.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月05日
*   描    述：
*
================================================================*/

#include "SkillWave.h"

namespace cmengine
{
    void SkillWave::operator>>(Sprite &sp)
    {
        sp.health -= (this->hurtPoint - sp.defence);
    }
}
