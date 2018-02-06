/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Sprite.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年01月31日
*   描    述：
*
================================================================*/

#include "Sprite.h"
#include <iostream>
#include "SkillManager.h"

namespace cmengine
{
    Sprite::Sprite(std::string name_, int attack_, int defence_, int health_)
    {
        name = name_;
        attack = attack_;
        defence = defence_;
        health = health_;
    }
    
    SkillWave Sprite::operator()(string skillKey)
    {
        SkillPtr sk = SkillManager::GetSkillWithKey(skillKey);
        SkillWave wave = sk->wave(*this);

        return wave;
    }
}
