/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMGeneralTypedef.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月08日
*   描    述：
*
================================================================*/

#ifndef CMGENERALTYPEDEF_H
#define CMGENERALTYPEDEF_H

#include <map>
#include <functional>
#include <memory>

namespace cmengine
{
    class CMBaseSkill;
    
    typedef int MapKey;

    // 用于：创建技能类函数
    typedef std::unique_ptr<CMBaseSkill> BaseSkill;
    typedef std::function<BaseSkill(void)> CreateSkillFun;
    typedef std::map<MapKey, CreateSkillFun> CreateSkillFunMap;
}

#endif /* CMGENERALTYPEDEF_H */
