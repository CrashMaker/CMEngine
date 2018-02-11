/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SkillList.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月01日
*   描    述：
*
================================================================*/

#include "SkillList.h"

// 加载技能列表
SkillMap LoadSkillListForCMEngine()
{
    using namespace game;

    SkillMap m;

    m.insert(SkillMap::value_type("Cut", Cut()));
    
    return m;
}

namespace game
{
    // 技能列表
    SkillPtr Cut()
    {
        ActionFunc f = [](Sprite &sp){
            int hurtPoint = sp.attack;

            Wave wave = Wave(sp, hurtPoint);

            return wave;
        };
        return SkillPtr(new Skill("Cut", f));
    }
}
