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

namespace cmengine
{
    void Round::action()
    {
        Begin();
        Battle();
        Finish();
    }

    void Round::Begin()
    {

    }

    void Round::Battle()
    {
        attack.action();
    }

    void Round::Finish()
    {
        
    }
}
