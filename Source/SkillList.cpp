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
    m.insert(SkillMap::value_type("Shot", Shot()));
    
    return m;
}

namespace game
{
    // 技能列表
    SkillPtr Cut()
    {
        SkillActionFunc f = [](){
            std::cout << "f_cut" << std::endl;
        };
        return SkillPtr(new Skill("Cut", f));
    }

    SkillPtr Shot()
    {
        SkillActionFunc f = [](){
            std::cout << "f_shot" << std::endl;
        };
        return SkillPtr(new Skill("Shot", f));
    }
}
