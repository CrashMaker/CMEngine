/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：HeroSource.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月20日
*   描    述：
*
================================================================*/

#ifndef HEROSOURCE_H
#define HEROSOURCE_H

#include "../CMEngine/CMEngine.h"

// 需要实现的函数
cmengine::CreateHeroFunMap cmengine::GetHeroSourceForCMEngine();

// 英雄列表
cmengine::HeroSprite Warrior();
cmengine::HeroSprite Mage();

#endif /* HEROSOURCE_H */
