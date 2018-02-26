/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkillModel.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSKILLMODEL_H
#define CMSKILLMODEL_H

#include <string>
#include <functional>

#include "../CMSprite/CMSprite.h"
#include "../CMStateLog/CMStateLog.h"

namespace cmengine
{
    using std::string;
    using std::function;
    class CMSkill;

    struct CMSkillModel
    {
        string name;            
        function<void(CMSprite &caster, 
                      CMSprite &target, 
                      CMSkill &skill, 
                      CMStateLog &stateLog)> logicFun;
    };
}

#endif /* CMSKILLMODEL_H */
