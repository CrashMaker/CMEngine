/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Sprite.h
*   创 建 者：CrashMaker
*   创建日期：2018年01月31日
*   描    述：
*
================================================================*/

#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include "SkillWave.h"

namespace cmengine
{
    class SkillWave;

    using std::string;

    class Sprite
    {
    private:

    public:
        string name;
        int attack;
        int defence;   
        int health;

        Sprite(string name_, int attack_, int defence_, int health_);

        SkillWave operator()(string skillKey);
    };
}

#endif /* SPRITE_H */
