/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Wave.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月05日
*   描    述：
*
================================================================*/

#include "Wave.h"

namespace cmengine
{
    void Wave::operator>>(Sprite &sp)
    {
        sp.health -= (this->hurtPoint - sp.defence);
        this->caster.health -= 19;
    }
}
