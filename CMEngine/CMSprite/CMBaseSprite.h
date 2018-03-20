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
#include <string>

namespace cmengine
{
    // 角色成长率，建议攻击、防御、生命以2:1:3的比例成长
    struct CMSpriteGrowthRate
    {
        float attackGrowthRate;
        float defenseGrowthRate;
        float magicAtkGrowthRate;
        float magicDefGrowthRate;
        float healthGrowthRate;
        float speedGrowthRate;

         CMSpriteGrowthRate() 
            : attackGrowthRate(0), defenseGrowthRate(0), magicAtkGrowthRate(0),
              magicDefGrowthRate(0), healthGrowthRate(0), speedGrowthRate(0) {}
    };
    
    // 角色基础属性, 默认都为1
    struct CMSpriteBaseAttribute
    {
        int attack;
        int defense;
        int magicAtk;
        int magicDef;
        int health;
        int speed;

        CMSpriteBaseAttribute() 
            : attack(1), defense(1), magicAtk(1),
              magicDef(1), health(1), speed(1) {}

        void Reset() 
        {
            attack = 1;
            defense = 1;
            magicAtk = 1;
            magicDef = 1;
            health = 1;
            speed = 1;
        }
    };

    class CMBaseSprite
    {
    public:
        CMBaseSprite (std::string name_, CMSpriteGrowthRate growthRate_) 
            : name(name_), growthRate(growthRate_) 
        {
            stateType = SpriteStateTypeLife;
            SetLevel(1);
        }
        virtual ~CMBaseSprite () {}
    
        std::string GetName() const {return name;}
        int GetLevel() const {return level;}

        void SetLevel(int lv);
        void SetupInnateAttribute();
        void SetupCurrentAttribute();
    private:
        std::string name;
        CMSpriteGrowthRate growthRate;

        // 固有属性，只会因为等级变化而改变。
        CMSpriteBaseAttribute innateAttribute;
        // 当前属性，会随着固有属性、装备或附加状态而改变。
        CMSpriteBaseAttribute currentAttribute;
        // 等级
        int level;
        // 当前生命值，无法高于最大生命值，当为0时，角色进入死亡状态。
        int healthPoint;
        // 角色状态
        SpriteStateType stateType;
    };
}

#endif /* CMBASESPRITE_H */
