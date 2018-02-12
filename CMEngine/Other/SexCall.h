/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SexCall.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月12日
*   描    述：可以使用如下格式进行战斗：(施法者)+(技能)>>(目标)
*
================================================================*/

#ifndef SEXCALL_H
#define SEXCALL_H

#include "../Sprite/Sprite.h"
#include "../Skill/Skill.h"
#include "../Battle/Round.h"

namespace cmengine
{
    class SexCall
    {
    private:
        Sprite &sp;
        const Skill &sk; 

    public:
        SexCall(Sprite &sp_, const Skill &sk_) : sp(sp_), sk(sk_) {}

        Round operator>>(Sprite &sp_); 
    };

    SexCall operator+(Sprite &sp_, const Skill &sk_);
}

#endif /* SEXCALL_H */
