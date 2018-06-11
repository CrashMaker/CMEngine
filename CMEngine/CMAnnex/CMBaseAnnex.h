/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBaseAnnex.h
*   创 建 者：CrashMaker
*   创建日期：2018年05月14日
*   描    述：附属于角色的附加属性
*
================================================================*/

#ifndef CMBASEANNEX_H
#define CMBASEANNEX_H

#include <iostream>

namespace cmengine
{
    class CMBaseSprite;

    class CMBaseAnnex
    {
    public:
        CMBaseAnnex(std::string name_) : name(name_) {}
        virtual ~CMBaseAnnex() {}

        std::string GetName() {return name;}
        CMBaseSprite* GetHost() {return host;}
        // 装配到Sprite上
        virtual void equip(CMBaseSprite* sprite) {host = sprite;}

    private:
        std::string name;
        CMBaseSprite* host;     // 宿主
    };
}

#endif /* CMBASEANNEX_H */
