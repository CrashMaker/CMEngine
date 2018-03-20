/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SpriteSource.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月20日
*   描    述：
*
================================================================*/

#ifndef SPRITESOURCE_H
#define SPRITESOURCE_H

#include "../CMEngine/CMEngine.h"

// 需要实现的函数
cmengine::CreateSpriteFunMap cmengine::GetSpriteSourceForCMEngine();

// 怪物列表
cmengine::BaseSprite Dog();
cmengine::BaseSprite Pig();

#endif /* SPRITESOURCE_H */
