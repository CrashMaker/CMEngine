/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：HeroSource.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月20日
*   描    述：
*
================================================================*/

#include "HeroSource.h"

using namespace cmengine;
using namespace std;

// 需要实现的函数
CreateHeroFunMap cmengine::GetHeroSourceForCMEngine()
{
   cmengine::CreateHeroFunMap map;

    map = {
        {1, Warrior}, 
        {2, Mage}, 
    };

    return map; 
}

// 英雄列表
HeroSprite Warrior()
{ 
    CMGrowthRateAttribute growthRate;
    HeroSprite hero(new CMHeroSprite("Warrior", growthRate));

    // 设置技能
    hero->SetSkillList({1, 2});

    return hero;
}

HeroSprite Mage()
{
    CMGrowthRateAttribute growthRate;
    HeroSprite hero(new CMHeroSprite("Mage", growthRate));

    // 设置技能
    hero->SetSkillList({1, 2});

    return hero;
}
