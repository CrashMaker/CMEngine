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

namespace cmengine
{
    void CMBaseSprite::SetLevel(int lv)
    {
        if (lv < SpriteMinLevel) {
            level = SpriteMinLevel;
        } else if (lv > SpriteMaxLevel) {
            level = SpriteMaxLevel;
        } else {
            level = lv;
        }

        SetupInnateAttribute();
    }

    void CMBaseSprite::SetHealthPoint(int hp)
    {
        // 当角色为life状态时，生命值才可以被改变
        if (SpriteStateTypeLife == stateType) {
            if (hp < 0) {
                healthPoint = 0;
            } else if (hp > currentAttribute.GetHealth()) {
                healthPoint = currentAttribute.GetHealth();
            } else {
                healthPoint = hp;
            }

            // 当生命值为0时，角色进入Dead状态
            if (0 == healthPoint) {
                stateType = SpriteStateTypeDead;
            }
        }
    }

    void CMBaseSprite::SetupInnateAttribute()
    {
        // 重置属性
        innateAttribute.Reset();
        // 设置攻击力
        int attack = innateAttribute.GetAttack() +  growthRate.GetAttackGrow() * level * SpriteGrowthRatioAttack;
        innateAttribute.SetAttack(attack);
        // 设置防御力
        int defense = innateAttribute.GetDefense() +  growthRate.GetDefenseGrow() * level * SpriteGrowthRatioDefense;
        innateAttribute.SetDefense(defense);
        // 设置魔法攻击力
        int magicAtk = innateAttribute.GetMagicAtk() +  growthRate.GetMagicAtkGrow() * level * SpriteGrowthRatioMagicAtk;
        innateAttribute.SetMagicAtk(magicAtk);
        // 设置魔法防御力
        int magicDef = innateAttribute.GetMagicDef() +  growthRate.GetMagicDefGrow() * level * SpriteGrowthRatioMagicDef;
        innateAttribute.SetMagicDef(magicDef);
        // 设置生命值
        int health = innateAttribute.GetHealth() +  growthRate.GetHealthGrow() * level * SpriteGrowthRatioHealth;
        innateAttribute.SetHealth(health);
        // 设置速度
        int speed = innateAttribute.GetSpeed() +  growthRate.GetSpeedGrow() * level * SpriteGrowthRatioSpeed;
        innateAttribute.SetSpeed(speed);

        SetupCurrentAttribute();
    }

    void CMBaseSprite::SetupCurrentAttribute()
    {
        currentAttribute = innateAttribute;

        // 恢复生命值
        SetHealthPoint(currentAttribute.GetHealth());
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
        cout << "speed:" << currentAttribute.GetSpeed() << endl << endl;
    }
}
