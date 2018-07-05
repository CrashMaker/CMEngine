/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMHeroSprite.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月20日
*   描    述：
*
================================================================*/

#ifndef CMHEROSPRITE_H
#define CMHEROSPRITE_H

#include "CMBaseSprite.h"

namespace cmengine
{
    class CMEquipment;

    class CMHeroSprite : public CMBaseSprite
    {
    public:
        CMHeroSprite (std::string name, CMGrowthRateAttribute growthRate) 
            : CMBaseSprite(name, growthRate) {}
        virtual ~CMHeroSprite () {}

        // 装备
        void Equip(const CMEquipment& eq);
    
    private:
        /* data */
    };
}

#endif /* CMHEROSPRITE_H */
