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

#define SpriteMaxLevel      99      // 最高等级
#define SpriteMinLevel      1       // 最低等级

#define SpriteMaxAttack     999     // 最高攻击力
#define SpriteMaxDefense    999     // 最高防御力
#define SpriteMaxMagicAtk   999     // 最高魔法攻击力
#define SpriteMaxMagicDef   999     // 最高魔法防御力
#define SpriteMaxHealth     9999    // 最高生命
#define SpriteMaxSpeed      999     // 最高速度

// 属性成长率换算比例
#define SpriteGrowthRatioAttack     2
#define SpriteGrowthRatioDefense    1
#define SpriteGrowthRatioMagicAtk   2
#define SpriteGrowthRatioMagicDef   1
#define SpriteGrowthRatioHealth     3
#define SpriteGrowthRatioSpeed      1

// 所有属性值一律不准小于0
#define SpriteMinAttribute 0

namespace cmengine
{
    // 角色成长率
    struct CMSpriteGrowthRate
    {
    public:
        CMSpriteGrowthRate() 
            : attackGrow(0), defenseGrow(0), magicAtkGrow(0),
            magicDefGrow(0), healthGrow(0), speedGrow(0) {}
        CMSpriteGrowthRate(float attackGrow_, float defenseGrow_, float magicAtkGrow_, 
            float magicDefGrow_, float healthGrow_, float speedGrow_) 
            : attackGrow(attackGrow_), defenseGrow(defenseGrow_), magicAtkGrow(magicAtkGrow_),
              magicDefGrow(magicDefGrow_), healthGrow(healthGrow_), speedGrow(speedGrow_) {}

        float GetAttackGrow() {return attackGrow;}
        float GetDefenseGrow() {return defenseGrow;}
        float GetMagicAtkGrow() {return magicAtkGrow;}
        float GetMagicDefGrow() {return magicDefGrow;}
        float GetHealthGrow() {return healthGrow;}
        float GetSpeedGrow() {return speedGrow;}
        
    private:
        float attackGrow;
        float defenseGrow;
        float magicAtkGrow;
        float magicDefGrow;
        float healthGrow;
        float speedGrow;
    };
    
    // 角色基础属性, 默认都为1
    struct CMSpriteBaseAttribute
    {
    public:
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

        int GetAttack() {return attack;}
        int GetDefense() {return defense;}
        int GetMagicAtk() {return magicAtk;}
        int GetMagicDef() {return magicDef;}
        int GetHealth() {return health;}
        int GetSpeed() {return speed;}
        
        void SetAttack(int atk) {attack = GetCorrectNum(atk, SpriteMaxAttack);}
        void SetDefense(int def) {defense = GetCorrectNum(def, SpriteMaxDefense);}
        void SetMagicAtk(int mAtk) {magicAtk = GetCorrectNum(mAtk, SpriteMaxMagicAtk);}
        void SetMagicDef(int mDef) {magicDef = GetCorrectNum(mDef, SpriteMaxMagicDef);}
        void SetHealth(int hl) {health = GetCorrectNum(hl, SpriteMaxHealth);}
        void SetSpeed(int sp) {speed = GetCorrectNum(sp, SpriteMaxSpeed);}

    private:
        int attack;
        int defense;
        int magicAtk;
        int magicDef;
        int health;
        int speed;

        int GetCorrectNum(int num, int maxNum)
        {
            int result = 0;
            if (num < SpriteMinAttribute) {
                result = SpriteMinAttribute;
            } else if (num > maxNum) {
                result = maxNum;
            } else {
                result = num;
            }
            return result;
        }
    };

    class CMBaseSprite
    {
    public:
        CMBaseSprite (std::string name_, CMSpriteGrowthRate growthRate_) 
            : name(name_), growthRate(growthRate_) 
        {
            stateType = SpriteStateTypeLife;
            SetLevel(SpriteMinLevel);
        }
        virtual ~CMBaseSprite () {}
    
        std::string GetName() const {return name;}
        int GetLevel() const {return level;}

        void SetLevel(int lv);
        void SetHealthPoint(int hp);
        void SetupInnateAttribute();
        void SetupCurrentAttribute();

        // 打印状态
        void PrintAttribute();
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
