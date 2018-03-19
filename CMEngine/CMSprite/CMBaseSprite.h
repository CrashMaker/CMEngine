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

namespace cmengine
{
    class CMBaseSprite
    {
    public:
        CMBaseSprite ();
        virtual ~CMBaseSprite () {}
    
        std::string GetName() const {return name;}
    private:
        std::string name;
        int level;
        int healthPoint;
        SpriteStateType stateType;
    };
}

#endif /* CMBASESPRITE_H */
