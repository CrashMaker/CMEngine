/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMAttack.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：一次进攻，分为进攻准备，进攻开始，进攻结束
*
================================================================*/

#ifndef CMATTACK_H
#define CMATTACK_H

#include "../CMSprite/CMSprite.h"
#include "../CMLog/CMBattleNote.h"

namespace cmengine
{
    class CMAttack
    {
    private:
    public:
        void action();
    };
}

#endif /* CMATTACK_H */
