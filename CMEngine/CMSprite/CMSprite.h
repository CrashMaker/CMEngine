/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSprite.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSPRITE_H
#define CMSPRITE_H

#include "../CMModel/CMSpriteModel.h"

namespace cmengine
{

    class CMSprite
    {
    private:
        CMSpriteModel model;

        // 基础属性
        // 附加属性
        // 综合属性
        // 现有属性

    public:
        friend class CMSpriteInterface;

        CMSprite(const CMSpriteModel &model_) : model(model_) {}
        CMSpriteModel GetModel() {return model;}
    };
}

#endif /* CMSPRITE_H */
