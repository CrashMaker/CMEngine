/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSpriteInterface.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月28日
*   描    述：
*
================================================================*/

#include "CMSpriteInterface.h"

namespace cmengine
{
    void CMSpriteInterface::Dead()
    {
        sprite.model.health = 0;
    }

    void CMSpriteInterface::Hurt(int point)
    {
        sprite.model.health -= point;

        if (sprite.model.health <= 0) {
            Dead();
        }
    }
}
