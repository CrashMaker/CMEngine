/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSpriteDelegate.h
*   创 建 者：CrashMaker
*   创建日期：2018年05月08日
*   描    述：
*
================================================================*/

#ifndef CMSPRITEDELEGATE_H
#define CMSPRITEDELEGATE_H

namespace cmengine
{
    class CMBaseSprite;

    class CMSpriteDelegate
    {
    public:
        // 角色受到伤害
        virtual void SpriteHasDamage(CMBaseSprite* sprite, int point) = 0;
        // 角色受到治疗
        virtual void SpriteHasHeal(CMBaseSprite* sprite, int point) = 0;
        // 角色状态改变
        virtual void SpriteHasStateTypeChange(CMBaseSprite* sprite) = 0;
    };
}

#endif /* CMSPRITEDELEGATE_H */
