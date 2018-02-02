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

namespace cmengine
{
    class Sprite
    {
    private:
        std::string name;
        int attack;
        int defence;   
        int health;

    public:
        Sprite(std::string name_, int attack_, int defence_, int health_);
        // virtual ~Sprite();

        void operator()(long skillID);
    };
}

#endif /* SPRITE_H */
