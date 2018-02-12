/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Round.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月12日
*   描    述：
*
================================================================*/

#include "Round.h"

#include <iostream>

namespace cmengine
{
    void Round::action()
    {
        std::cout << caster.name << std::endl;
        std::cout << skill.name << std::endl;
        std::cout << target.name << std::endl;
    }
}
