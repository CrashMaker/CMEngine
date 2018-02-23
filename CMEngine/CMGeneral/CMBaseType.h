/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseType.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMBASETYPE_H
#define CMBASETYPE_H

#include <map>
#include <functional>

#include "../CMModel/CMSkillModel.h"

namespace cmengine
{
    typedef int MapKey;

    typedef std::function<void(CMSkillModel &model)> SkillFun;
    typedef std::map<MapKey, SkillFun> SkillMap;
}

#endif /* CMBASETYPE_H */
