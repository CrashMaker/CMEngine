/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSpriteGrowthRate.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月26日
*   描    述：
*
================================================================*/

#ifndef CMSPRITEGROWTHRATE_H
#define CMSPRITEGROWTHRATE_H

// 属性成长率换算比例
#define GrowthRatioAttack     2
#define GrowthRatioDefense    1
#define GrowthRatioMagicAtk   2
#define GrowthRatioMagicDef   1
#define GrowthRatioHealth     3
#define GrowthRatioMana       1
#define GrowthRatioSpeed      1

namespace cmengine
{
    class CMSpriteGrowthRate
    {
    public:
        CMSpriteGrowthRate() 
            : attackGrow(0), defenseGrow(0), magicAtkGrow(0),
            magicDefGrow(0), healthGrow(0), manaGrow(0), speedGrow(0) {}
        CMSpriteGrowthRate(float attackGrow_, float defenseGrow_, float magicAtkGrow_, 
            float magicDefGrow_, float healthGrow_, float manaGrow_, float speedGrow_) 
            : attackGrow(attackGrow_), defenseGrow(defenseGrow_), magicAtkGrow(magicAtkGrow_),
              magicDefGrow(magicDefGrow_), healthGrow(healthGrow_), manaGrow(manaGrow_), speedGrow(speedGrow_) {}

        float GetAttackGrow() const {return attackGrow;}
        float GetDefenseGrow() const {return defenseGrow;}
        float GetMagicAtkGrow() const {return magicAtkGrow;}
        float GetMagicDefGrow() const {return magicDefGrow;}
        float GetHealthGrow() const {return healthGrow;}
        float GetManaGrow() const {return manaGrow;}
        float GetSpeedGrow() const {return speedGrow;}

        int GetAttackWithLevel(int level) {return (level * GrowthRatioAttack * attackGrow);}
        int GetDefenseWithLevel(int level) {return (level * GrowthRatioDefense * defenseGrow);}
        int GetMagicAtkWithLevel(int level) {return (level * GrowthRatioMagicAtk * magicAtkGrow);}
        int GetMagicDefWithLevel(int level) {return (level * GrowthRatioMagicDef * magicDefGrow);}
        int GetHealthWithLevel(int level) {return (level * GrowthRatioHealth * healthGrow);}
        int GetManaWithLevel(int level) {return (level * GrowthRatioMana * manaGrow);}
        int GetSpeedWithLevel(int level) {return (level * GrowthRatioSpeed * speedGrow);}
        
    private:
        float attackGrow;
        float defenseGrow;
        float magicAtkGrow;
        float magicDefGrow;
        float healthGrow;
        float manaGrow;
        float speedGrow;    
    };
}


#endif /* CMSPRITEGROWTHRATE_H */
