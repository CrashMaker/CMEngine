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
#include <iostream>

// 加载技能列表
std::vector<cmengine::Skill> loadSkillListForCMEngine()
{
    std::vector<cmengine::Skill> v = {
        game::cut(), 
        game::cut()
    };

    return v;
}

namespace game
{
    // 技能列表
    cmengine::Skill cut()
    {
        cmengine::SkillActionFunc f = [](){
            std::cout << "f_cut" << std::endl;
        };
        return cmengine::Skill("cut", f);
    }
}
