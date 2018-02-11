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

#include "Wave.h"

namespace cmengine
{
    typedef std::function<Wave(Sprite &sp)> ActionFunc;

    class Skill
    {
    private:
        

    public:
        const std::string name;
        const ActionFunc wave;

        Skill(std::string name_, ActionFunc wave_) : name(name_), wave(wave_) {}
    };

}

#endif /* SKILL_H */
