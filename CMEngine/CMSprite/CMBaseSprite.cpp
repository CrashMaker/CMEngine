/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseSprite.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年03月19日
*   描    述：
*
================================================================*/

#include "CMBaseSprite.h"

#define MaxLevel 99         // 最高等级

namespace cmengine
{
    void CMBaseSprite::SetLevel(int lv)
    {
        if (lv <= 0) {
            level = 1;
        } else if (lv > MaxLevel) {
            level = MaxLevel;
        } else {
            level = lv;
        }

        SetupInnateAttribute();
    }

    void CMBaseSprite::SetupInnateAttribute()
    {
        innateAttribute.Reset();
        innateAttribute.attack += (growthRate.attackGrowthRate * level);
        innateAttribute.defense += (growthRate.defenseGrowthRate * level);
        innateAttribute.magicAtk += (growthRate.magicAtkGrowthRate * level);
        innateAttribute.magicDef += (growthRate.magicDefGrowthRate * level);
        innateAttribute.health += (growthRate.healthGrowthRate * level);
        innateAttribute.speed += (growthRate.speedGrowthRate * level);

        SetupCurrentAttribute();
    }

    void CMBaseSprite::SetupCurrentAttribute()
    {
        currentAttribute = innateAttribute;

        // 恢复生命值
        healthPoint = currentAttribute.health;
    }
}
