/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SexCall.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月12日
*   描    述：
*
================================================================*/

#include "SexCall.h"

namespace cmengine
{
    Round SexCall::operator>>(Sprite &sp_)
    {
        Round round = Round(sp, sp_, sk);
        round.action();
        return round;
    }

    SexCall operator+(Sprite &sp_, const Skill &sk_)
    {
        return SexCall(sp_, sk_); 
    }
}
