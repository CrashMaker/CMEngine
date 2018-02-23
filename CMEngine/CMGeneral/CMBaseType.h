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

typedef int key;

typedef std::function<void(int)> SkillFunc;

typedef std::map<key, SkillFunc>SkillMap;

#endif /* CMBASETYPE_H */
