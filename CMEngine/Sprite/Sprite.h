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

#include <iostream>

namespace cmengine
{
    using namespace std;
    
    class Sprite
    {
    private:
        string name;
        int attack;
        int defence;   
        int health;

    public:
        friend class Attack;

        Sprite(string name_, int attack_, int defence_, int health_) : 
            name(name_), attack(attack_), defence(defence_), health(health_) {}
    };
}

#endif /* SPRITE_H */
