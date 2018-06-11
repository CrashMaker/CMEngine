/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSpriteBaseAttribute.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月26日
*   描    述：
*
================================================================*/

#ifndef CMSPRITEBASEATTRIBUTE_H
#define CMSPRITEBASEATTRIBUTE_H

#define MaxAttack     999     // 最高攻击力
#define MaxDefense    999     // 最高防御力
#define MaxMagicAtk   999     // 最高魔法攻击力
#define MaxMagicDef   999     // 最高魔法防御力
#define MaxHealth     9999    // 最高生命值
#define MaxMana       9999    // 最高魔法值
#define MaxSpeed      999     // 最高速度

#define MinAttribute  0       // 最小值 

namespace cmengine
{
    class CMSpriteBaseAttribute
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
            mana = 1;
            speed = 1;
        }

        int GetAttack() const {return attack;}
        int GetDefense() const {return defense;}
        int GetMagicAtk() const {return magicAtk;}
        int GetMagicDef() const {return magicDef;}
        int GetHealth() const {return health;}
        int GetMana() const {return mana;}
        int GetSpeed() const {return speed;}
        
        void SetAttack(int atk) {attack = GetCorrectNum(atk, MaxAttack);}
        void SetDefense(int def) {defense = GetCorrectNum(def, MaxDefense);}
        void SetMagicAtk(int mAtk) {magicAtk = GetCorrectNum(mAtk, MaxMagicAtk);}
        void SetMagicDef(int mDef) {magicDef = GetCorrectNum(mDef, MaxMagicDef);}
        void SetHealth(int hl) {health = GetCorrectNum(hl, MaxHealth);}
        void SetMana(int ma) {mana = GetCorrectNum(ma, MaxMana);}
        void SetSpeed(int sp) {speed = GetCorrectNum(sp, MaxSpeed);}

    private:
        int attack;
        int defense;
        int magicAtk;
        int magicDef;
        int health;
        int mana;
        int speed;

        int GetCorrectNum(int num, int maxNum)
        {
            int result = 0;
            if (num < MinAttribute) {
                result = MinAttribute;
            } else if (num > maxNum) {
                result = maxNum;
            } else {
                result = num;
            }
            return result;
        }
    };
}


#endif /* CMSPRITEBASEATTRIBUTE_H */
