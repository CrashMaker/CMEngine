/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSpriteModel.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSPRITEMODEL_H
#define CMSPRITEMODEL_H

#include <string>

namespace cmengine
{
    struct CMSpriteModel
    {
        std::string name;
        int attack;
        int defense;
        int magicAtk;
        int magicDef;
        int health;
        int speed;
    };
}

#endif /* CMSPRITEMODEL_H */
