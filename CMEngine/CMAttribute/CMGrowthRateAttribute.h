/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMGrowthRateAttribute.h
*   创 建 者：CrashMaker
*   创建日期：2018年06月11日
*   描    述：
*
================================================================*/

#ifndef CMGROWTHRATEATTRIBUTE_H
#define CMGROWTHRATEATTRIBUTE_H

#include "../CMGeneral/CMGeneralFunction.h"

// 属性成长率换算比例
#define GrowthRateAttack     2
#define GrowthRateDefense    1
#define GrowthRateMagicAtk   2
#define GrowthRateMagicDef   1
#define GrowthRateHealth     3
#define GrowthRateMana       1
#define GrowthRateSpeed      1

#define MinGrowthRate        0       // 最小成长率
#define MaxGrowthRate        99      // 最大成长率
#define DefaultGrowthRate    1       // 默认成长率

namespace cmengine
{
    class CMGrowthRateAttribute
    {
    public:
        CMGrowthRateAttribute() {
            SetAttackGrow(DefaultGrowthRate);
            SetDefenseGrow(DefaultGrowthRate);
            SetMagicAtkGrow(DefaultGrowthRate);
            SetMagicDefGrow(DefaultGrowthRate);
            SetHealthGrow(DefaultGrowthRate);
            SetManaGrow(DefaultGrowthRate);
            SetSpeedGrow(DefaultGrowthRate);
        }
        virtual ~CMGrowthRateAttribute() {}
    
        float GetAttackGrow() const {return attackGrow;}
        float GetDefenseGrow() const {return defenseGrow;}
        float GetMagicAtkGrow() const {return magicAtkGrow;}
        float GetMagicDefGrow() const {return magicDefGrow;}
        float GetHealthGrow() const {return healthGrow;}
        float GetManaGrow() const {return manaGrow;}
        float GetSpeedGrow() const {return speedGrow;}

        void SetAttackGrow(float atkGrow) {attackGrow = CMGeneralFunction::GetRangeOfValue(atkGrow, MinGrowthRate, MaxGrowthRate);}
        void SetDefenseGrow(float defGrow) {defenseGrow = CMGeneralFunction::GetRangeOfValue(defGrow, MinGrowthRate, MaxGrowthRate);}
        void SetMagicAtkGrow(float mAtkGrow) {magicAtkGrow = CMGeneralFunction::GetRangeOfValue(mAtkGrow, MinGrowthRate, MaxGrowthRate);}
        void SetMagicDefGrow(float mDefGrow) {magicDefGrow = CMGeneralFunction::GetRangeOfValue(mDefGrow, MinGrowthRate, MaxGrowthRate);}
        void SetHealthGrow(float hlGrow) {healthGrow = CMGeneralFunction::GetRangeOfValue(hlGrow, MinGrowthRate, MaxGrowthRate);}
        void SetManaGrow(float maGrow) {manaGrow = CMGeneralFunction::GetRangeOfValue(maGrow, MinGrowthRate, MaxGrowthRate);}
        void SetSpeedGrow(float spGrow) {speedGrow = CMGeneralFunction::GetRangeOfValue(spGrow, MinGrowthRate, MaxGrowthRate);}

        int GetAttackWithLevel(int level) {return (level * GrowthRateAttack * GetAttackGrow());}
        int GetDefenseWithLevel(int level) {return (level * GrowthRateDefense * GetDefenseGrow());}
        int GetMagicAtkWithLevel(int level) {return (level * GrowthRateMagicAtk * GetMagicAtkGrow());}
        int GetMagicDefWithLevel(int level) {return (level * GrowthRateMagicDef * GetMagicDefGrow());}
        int GetHealthWithLevel(int level) {return (level * GrowthRateHealth * GetHealthGrow());}
        int GetManaWithLevel(int level) {return (level * GrowthRateMana * GetManaGrow());}
        int GetSpeedWithLevel(int level) {return (level * GrowthRateSpeed * GetSpeedGrow());}
        
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

#endif /* CMGROWTHRATEATTRIBUTE_H */
