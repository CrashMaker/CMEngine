/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseSprite.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月19日
*   描    述：
*
================================================================*/

#ifndef CMBASESPRITE_H
#define CMBASESPRITE_H

#include "../CMGeneral/CMGeneralSpriteType.h"
#include "ComponentsOfSprite/CMBaseAttributeOfSprite.h"
#include "ComponentsOfSprite/CMGrowthRateOfSprite.h"
#include <string>

#define MaxLevel      99      // 最高等级
#define MinLevel      1       // 最低等级

namespace cmengine
{
    class CMBaseSprite
    {
    public:
        CMBaseSprite (std::string name_, CMGrowthRateOfSprite growthRate_) 
            : name(name_), growthRate(growthRate_) 
        {
            stateType = SpriteStateTypeLife;
            SetLevel(MinLevel);
        }
        virtual ~CMBaseSprite () {}
    
        // 姓名
        std::string GetName() const {return name;}

        // 等级
        int GetLevel() const {return level;}
        void SetLevel(int lv);

        // 获得治疗
        void ObtainHeal(int point);

        // 受到伤害
        void ObtainDamage(int point);

        // 打印状态
        void PrintAttribute() const;

    private:
        void SetHealthPoint(int hp);
        void SetupInnateAttribute();
        void SetupCurrentAttribute();

    private:
        std::string name;
        CMGrowthRateOfSprite growthRate;

        // 固有属性，只会因为等级变化而改变。
        CMBaseAttributeOfSprite innateAttribute;
        // 当前属性，会随着固有属性、装备或附加状态而改变。
        CMBaseAttributeOfSprite currentAttribute;
        // 等级
        int level;
        // 当前生命值，无法高于最大生命值，当为0时，角色进入死亡状态。
        int healthPoint;
        // 角色状态
        SpriteStateType stateType;
    };
}

#endif /* CMBASESPRITE_H */
