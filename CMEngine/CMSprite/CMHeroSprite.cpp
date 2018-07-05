/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMHeroSprite.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年06月26日
*   描    述：
*
================================================================*/

#include "CMHeroSprite.h"
#include "../CMEquipment/CMEquipment.h"

namespace cmengine
{
    void CMHeroSprite::Equip(const CMEquipment& eq)
    {
        CMAttributeAnnex attr = eq.GetAttributeAnnex();
        AddAnnex(&attr);
    }
}
