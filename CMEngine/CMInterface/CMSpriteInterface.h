/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSpriteInterface.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月28日
*   描    述：
*
================================================================*/

#ifndef CMSPRITEINTERFACE_H
#define CMSPRITEINTERFACE_H

#include "../CMSprite/CMSprite.h"

namespace cmengine
{
    class CMSpriteInterface
    {
    private:
        CMSprite &sprite;

    public:
        void Dead(bool showLog = true);
        void Hurt(int point, bool showLog = true);

        CMSpriteInterface(CMSprite &sprite_) : sprite(sprite_) {}

    };
}

#endif /* CMSPRITEINTERFACE_H */
