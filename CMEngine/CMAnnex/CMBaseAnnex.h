/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseAnnex.h
*   创 建 者：CrashMaker
*   创建日期：2018年05月14日
*   描    述：附属于角色的附加属性
*
================================================================*/

#ifndef CMBASEANNEX_H
#define CMBASEANNEX_H

#include <iostream>

namespace cmengine
{
    class CMBaseSprite;

    class CMBaseAnnex
    {
    public:
        virtual ~CMBaseAnnex() {}

        // 依附，执行逻辑
        virtual void DePend(CMBaseSprite* sp) = 0;

    };
}

#endif /* CMBASEANNEX_H */
