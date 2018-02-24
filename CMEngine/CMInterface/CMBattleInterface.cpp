/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleInterface.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月24日
*   描    述：
*
================================================================*/

#include "CMBattleInterface.h"

#include <iostream>

namespace cmengine
{
    void CMBattleInterface::dead(CMSprite &sp)
    {
        sp.model.health = 0;
        
        std::cout << sp.model.name << "死亡" << std::endl;
    }
}
