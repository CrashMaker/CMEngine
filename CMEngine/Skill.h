/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Skill.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月02日
*   描    述：
*
================================================================*/

#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <functional>
#include <iostream>

namespace cmengine
{
    typedef std::function<void()> SkillActionFunc;

    class Skill
    {
    private:
        

    public:
        const std::string name;
        const SkillActionFunc action;

        Skill() : name(""), action([](){std::cout << "This is a invalid skill!" << std::endl;}) {}
        Skill(std::string name_, SkillActionFunc action_) : name(name_), action(action_) {}
    };

}

#endif /* SKILL_H */
