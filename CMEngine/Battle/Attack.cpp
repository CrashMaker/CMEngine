/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Attack.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月22日
*   描    述：
*
================================================================*/

#include "Attack.h"

#include <iostream>

namespace cmengine
{
    void Attack::action()
    {
        std::cout << caster.name << skill.name << target.name << std::endl;
    }
}
