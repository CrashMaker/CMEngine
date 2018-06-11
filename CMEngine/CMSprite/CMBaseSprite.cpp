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
#include <iostream>

#define MaxPoint     9999       // 伤害和治疗的最高数值
#define MinPoint     0          // 伤害和治疗的最低数值

namespace cmengine
{
    void CMBaseSprite::SetLevel(int lv)
    {
        if (lv < MinLevel) {
            level = MinLevel;
        } else if (lv > MaxLevel) {
            level = MaxLevel;
        } else {
            level = lv;
        }

        SetupInnateAttribute();
    }

    void CMBaseSprite::SetHealthPoint(int hp)
    {
        // 当角色为life状态时，生命值才可以被改变
        if (SpriteStateType::SpriteStateTypeLife == stateType) {
            if (hp < 0) {
                healthPoint = 0;
            } else if (hp > currentAttribute.GetHealth()) {
                healthPoint = currentAttribute.GetHealth();
            } else {
                healthPoint = hp;
            }

            // 当生命值为0时，角色进入Dead状态
            if (0 == healthPoint) {
                SetupStateType(SpriteStateType::SpriteStateTypeDead);
            }
        }
    }

    void CMBaseSprite::SetupInnateAttribute()
    {
        // 重置属性
        innateAttribute.Reset();
        // 设置攻击力
        int attack = innateAttribute.GetAttack() + growthRate.GetAttackWithLevel(level);
        innateAttribute.SetAttack(attack);
        // 设置防御力
        int defense = innateAttribute.GetDefense() + growthRate.GetDefenseWithLevel(level);
        innateAttribute.SetDefense(defense);
        // 设置魔法攻击力
        int magicAtk = innateAttribute.GetMagicAtk() + growthRate.GetMagicAtkWithLevel(level);
        innateAttribute.SetMagicAtk(magicAtk);
        // 设置魔法防御力
        int magicDef = innateAttribute.GetMagicDef() + growthRate.GetMagicDefWithLevel(level);
        innateAttribute.SetMagicDef(magicDef);
        // 设置生命值
        int health = innateAttribute.GetHealth() + growthRate.GetHealthWithLevel(level);
        innateAttribute.SetHealth(health);
        // 设置魔法值
        int mana = innateAttribute.GetMana() + growthRate.GetManaWithLevel(level);
        innateAttribute.SetMana(mana);
        // 设置速度
        int speed = innateAttribute.GetSpeed() + growthRate.GetSpeedWithLevel(level);
        innateAttribute.SetSpeed(speed);

        SetupCurrentAttribute();
    }

    void CMBaseSprite::SetupCurrentAttribute()
    {
        currentAttribute = innateAttribute;

        // 恢复生命值
        SetHealthPoint(currentAttribute.GetHealth());
    }

    // 获得治疗
    void CMBaseSprite::ObtainHeal(int point)
    {
        if (MinPoint > point) {
            point = MinPoint;
        } else if (MaxPoint < point) {
            point = MaxPoint;
        }

        if (delegate) {
            delegate->SpriteHasHeal(this, point);
        }
        
        int hp = healthPoint + point;
        SetHealthPoint(hp);
    }

    // 受到伤害
    void CMBaseSprite::ObtainDamage(int point)
    {
        if (MinPoint > point) {
            point = MinPoint;
        } else if (MaxPoint < point) {
            point = MaxPoint;
        }

        if (delegate) {
            delegate->SpriteHasDamage(this, point);
        }

        int hp = healthPoint - point;
        SetHealthPoint(hp);
    }

    // 设置角色状态
    void CMBaseSprite::SetupStateType(SpriteStateType stateType_)
    {
        stateType = stateType_;
        if (delegate) {
            delegate->SpriteHasStateTypeChange(this);
        }
    }

    // 打印状态
    void CMBaseSprite::PrintAttribute() const
    {
        using namespace std;

        cout << "name:" << name << endl;
        cout << "level:" << level << endl;
        cout << "HP:" << healthPoint << endl << endl;
        cout << "attack:" << currentAttribute.GetAttack() << endl;
        cout << "defense:" << currentAttribute.GetDefense() << endl;
        cout << "magicAtk:" << currentAttribute.GetMagicAtk() << endl;
        cout << "magicDef:" << currentAttribute.GetMagicDef() << endl;
        cout << "health:" << currentAttribute.GetHealth() << endl;
        cout << "mana:" << currentAttribute.GetMana() << endl;
        cout << "speed:" << currentAttribute.GetSpeed() << endl << endl;
    }
}
