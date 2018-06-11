/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBasicAttribute.h
*   创 建 者：CrashMaker
*   创建日期：2018年06月11日
*   描    述：角色基本的属性
*
================================================================*/

#ifndef CMBASICATTRIBUTE_H
#define CMBASICATTRIBUTE_H

#include "../CMGeneral/CMGeneralFunction.h"

#define MaxAttack     999     // 最高攻击力
#define MaxDefense    999     // 最高防御力
#define MaxMagicAtk   999     // 最高魔法攻击力
#define MaxMagicDef   999     // 最高魔法防御力
#define MaxHealth     9999    // 最高生命值
#define MaxMana       9999    // 最高魔法值
#define MaxSpeed      999     // 最高速度

#define MinAttribute        0       // 最小属性值
#define DefaultAttribute    1       // 默认属性值

namespace cmengine
{
    class CMBasicAttribute
    {
    public:
        CMBasicAttribute() {
            SetupDefaultValue();
        }
        virtual ~CMBasicAttribute() {}

        // 恢复成默认属性值
        void Reset() {
            SetupDefaultValue();
        }
    
        int GetAttack() const {return attack;}
        int GetDefense() const {return defense;}
        int GetMagicAtk() const {return magicAtk;}
        int GetMagicDef() const {return magicDef;}
        int GetHealth() const {return health;}
        int GetMana() const {return mana;}
        int GetSpeed() const {return speed;}
        
        void SetAttack(int atk) {attack = CMGeneralFunction::GetRangeOfValue(atk, MinAttribute, MaxAttack);}
        void SetDefense(int def) {defense = CMGeneralFunction::GetRangeOfValue(def, MinAttribute, MaxDefense);}
        void SetMagicAtk(int mAtk) {magicAtk = CMGeneralFunction::GetRangeOfValue(mAtk, MinAttribute, MaxMagicAtk);}
        void SetMagicDef(int mDef) {magicDef = CMGeneralFunction::GetRangeOfValue(mDef, MinAttribute, MaxMagicDef);}
        void SetHealth(int hl) {health = CMGeneralFunction::GetRangeOfValue(hl, MinAttribute, MaxHealth);}
        void SetMana(int ma) {mana = CMGeneralFunction::GetRangeOfValue(ma, MinAttribute, MaxMana);}
        void SetSpeed(int sp) {speed = CMGeneralFunction::GetRangeOfValue(sp, MinAttribute, MaxSpeed);}

    private:
        void SetupDefaultValue() {
            SetAttack(DefaultAttribute);
            SetDefense(DefaultAttribute);
            SetMagicAtk(DefaultAttribute);
            SetMagicDef(DefaultAttribute);
            SetHealth(DefaultAttribute);
            SetMana(DefaultAttribute);
            SetSpeed(DefaultAttribute);
        }

    private:
        int attack;
        int defense;
        int magicAtk;
        int magicDef;
        int health;
        int mana;
        int speed;
    };
}

#endif /* CMBASICATTRIBUTE_H */
