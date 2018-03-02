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
#include "../CMLog/CMBattleNote.h"

namespace cmengine
{
    class CMSpriteInterface
    {
    private:
        CMSprite &sprite;
        CMBattleNote &note;

    public:
        void Dead();
        void Hurt(unsigned int point);

        CMSpriteInterface(CMSprite &sprite_, CMBattleNote &note_) 
            : sprite(sprite_), note(note_) {}

    };
}

#endif /* CMSPRITEINTERFACE_H */
