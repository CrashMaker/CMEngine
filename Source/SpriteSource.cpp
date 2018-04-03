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
    float attackGrow = 1.0f;
    float defenseGrow = 1.0f;
    float magicAtkGrow = 1.0f;
    float magicDefGrow = 1.0f;
    float healthGrow = 1.0f;
    float speedGrow = 1.0f;
 
    CMGrowthRateOfSprite growthRate(attackGrow, defenseGrow, magicAtkGrow, 
            magicDefGrow, healthGrow, speedGrow);
    BaseSprite sprite(new CMMonsterSprite("Dog", growthRate));
    return sprite;
}

BaseSprite Pig()
{
    float attackGrow = 1.0f;
    float defenseGrow = 1.0f;
    float magicAtkGrow = 1.0f;
    float magicDefGrow = 1.0f;
    float healthGrow = 1.0f;
    float speedGrow = 1.0f;
 
    CMGrowthRateOfSprite growthRate(attackGrow, defenseGrow, magicAtkGrow, 
            magicDefGrow, healthGrow, speedGrow);
    BaseSprite sprite(new CMMonsterSprite("Pig", growthRate));

    return sprite;
}
