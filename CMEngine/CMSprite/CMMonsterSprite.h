/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMMonsterSprite.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月20日
*   描    述：
*
================================================================*/

#ifndef CMMONSTERSPRITE_H
#define CMMONSTERSPRITE_H

#include "CMBaseSprite.h"

namespace cmengine
{
    class CMMonsterSprite : public CMBaseSprite
    {
    public:
        CMMonsterSprite (std::string name, CMSpriteGrowthRate growthRate) 
            : CMBaseSprite(name, growthRate) {}
        virtual ~CMMonsterSprite() {}
    
    private:
        /* data */
    };
}

#endif /* CMMONSTERSPRITE_H */
