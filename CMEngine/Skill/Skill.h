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

#include <iostream>

namespace cmengine
{
    using namespace std;
    
    class Skill
    {
    private:
        string name;

    public:
        friend class Round;

        Skill(string name_) : name(name_) {} 

    };

}

#endif /* SKILL_H */
