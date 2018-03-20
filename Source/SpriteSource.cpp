/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：SpriteSource.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月20日
*   描    述：
*
================================================================*/

#include "SpriteSource.h"

using namespace cmengine;
using namespace std;

CreateSpriteFunMap cmengine::GetSpriteSourceForCMEngine()
{
    cmengine::CreateSpriteFunMap map;

    map = {
        {1, Dog}, 
        {2, Pig}, 
    };

    return map;
}

// 怪物列表
BaseSprite Dog()
{
    CMSpriteGrowthRate growthRate;
    growthRate.attackGrowthRate = 0.8;
    growthRate.defenseGrowthRate = 0.4;
    growthRate.magicAtkGrowthRate = 0.8;
    growthRate.magicDefGrowthRate = 0.4;
    growthRate.healthGrowthRate = 1.2;
    growthRate.speedGrowthRate = 0.4;
    
    BaseSprite sprite(new CMMonsterSprite("Dog", growthRate));
    return sprite;
}

BaseSprite Pig()
{
    CMSpriteGrowthRate growthRate;
    growthRate.attackGrowthRate = 2;
    growthRate.defenseGrowthRate = 2;
    growthRate.magicAtkGrowthRate = 2;
    growthRate.magicDefGrowthRate = 2;
    growthRate.healthGrowthRate = 2;
    growthRate.speedGrowthRate = 2;
    
    BaseSprite sprite(new CMMonsterSprite("Pig", growthRate));

    return sprite;
}
