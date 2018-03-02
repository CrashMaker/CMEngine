/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleNote.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月02日
*   描    述：
*
================================================================*/

#include "CMBattleNote.h"

#include <iostream>

namespace cmengine
{
    void CMBattleNote::Push(const CMBattleLog &log)
    {
        logVector.push_back(log);     
    }
}
