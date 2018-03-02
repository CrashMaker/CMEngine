/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSexCall.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：可以使用如下格式进行战斗：(施法者)+(技能编号)>>(目标)
*
================================================================*/

#ifndef CMSEXCALL_H
#define CMSEXCALL_H

#include "../CMSprite/CMSprite.h"
#include "../CMSkill/CMSkill.h"
#include "../CMBattle/CMAttack.h"
#include "../CMSourceManager/CMSourceManager.h"

namespace cmengine
{
    class CMSexCall
    {
    private:
        CMSprite &sp;
        CMSkill sk; 

    public:
        CMSexCall(CMSprite &sp_, CMSkill sk_) : sp(sp_), sk(sk_) {}

        void operator>>(CMSprite &sp_); 
    };

    CMSexCall operator+(CMSprite &sp_, MapKey key);
}


#endif /* CMSEXCALL_H */
