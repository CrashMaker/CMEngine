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

#include <sstream>

namespace cmengine
{
    void CMSpriteInterface::Dead()
    {
        // 添加Log至战斗记录
        std::string log = sprite.GetModel().name + "死亡";
        note.Push(CMBattleLog(log));
        
        sprite.model.health = 0;
    }

    void CMSpriteInterface::Hurt(unsigned int point)
    {
        // 添加Log至战斗记录
        std::stringstream stream;
        stream << point;
        std::string log = sprite.GetModel().name 
                          + "受到" 
                          + stream.str() 
                          + "点伤害";
        note.Push(CMBattleLog(log));

        sprite.model.health -= point;

        if (sprite.model.health <= 0) {
            Dead();
        }
    }
}
