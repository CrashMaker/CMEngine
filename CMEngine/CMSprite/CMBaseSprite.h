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

#include "ComponentsOfSprite/CMSpriteGrowthRate.h"
#include "ComponentsOfSprite/CMSpriteBaseAttribute.h"
#include "ComponentsOfSprite/CMSpriteDelegate.h"

#include <string>
#include <vector>

#define MaxLevel      99      // 最高等级
#define MinLevel      1       // 最低等级

namespace cmengine
{
    enum struct SpriteStateType {
        SpriteStateTypeLife,        // 生存 
        SpriteStateTypeDead,        // 死亡
    };
    
    class CMBaseSkill;

    class CMBaseSprite
    {
    public:
        CMBaseSprite (std::string name_, CMSpriteGrowthRate growthRate_) 
            : name(name_), growthRate(growthRate_) 
        {
            stateType = SpriteStateType::SpriteStateTypeLife;
            SetLevel(MinLevel);
        }
        virtual ~CMBaseSprite () {}
    
        // 姓名
        std::string GetName() const {return name;}

        // 等级
        int GetLevel() const {return level;}
        void SetLevel(int lv);

        // 获取固有属性
        CMSpriteBaseAttribute GetInnateAttribute() const {return innateAttribute;}

        // 获取当前属性
        CMSpriteBaseAttribute GetCurrentAttribute() const {return currentAttribute;}

        // 角色状态
        SpriteStateType GetStateType() const {return stateType;}

        // 装配的技能列表
        std::vector<int> GetSkillList() const {return skillList;}
        void SetSkillList(std::vector<int> skillList_) {skillList = skillList_;}

        // 获得治疗
        void ObtainHeal(int point);

        // 受到伤害
        void ObtainDamage(int point);

        // 设置角色状态
        void SetupStateType(SpriteStateType stateType_);

        // 打印状态
        void PrintAttribute() const;

    public:
        CMSpriteDelegate* delegate = nullptr;       // 协议对象

    private:
        void SetHealthPoint(int hp);
        void SetManaPoint(int mp);
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
        // 当前魔法值，无法高于最大魔法
        int manaPoint;
        // 角色状态
        SpriteStateType stateType;
        // 装配的技能列表
        std::vector<int> skillList;
    };
}

#endif /* CMBASESPRITE_H */
