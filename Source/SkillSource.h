/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SkillSource.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月22日
*   描    述：
*
================================================================*/

#ifndef SKILLSOURCE_H
#define SKILLSOURCE_H

#include "../CMEngine/CMEngine.h"

using cmengine::SkillMap;
using cmengine::CMSkillModel;
using cmengine::CMSpriteModel;

// 需要实现的函数
SkillMap cmengine::LoadSkillSourceForCMEngine();

// 技能列表
void Cut(CMSkillModel &model);

#endif /* SKILLSOURCE_H */
