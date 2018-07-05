/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：EquipmentSource.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年06月27日
*   描    述：
*
================================================================*/

#include "EquipmentSource.h"

using namespace cmengine;
using namespace std;

// 需要实现的函数
CreateEquipmentFunMap cmengine::GetEquipSourceForCMEngine()
{
   cmengine::CreateEquipmentFunMap map;

    map = {
        {1, Sword}, 
        {2, Armor}, 
    };

    return map; 
}

// 装备列表
cmengine::Equipment Sword()
{
    CMBasicAttribute attri;
    attri.SetAttack(12);
    CMAttributeAnnex annex;
    annex.SetAttribute(attri);

    Equipment equipment(new CMEquipment("Sword", annex));

    return equipment;
}

cmengine::Equipment Armor()
{
    CMBasicAttribute attri;
    attri.SetDefense(4);
    CMAttributeAnnex annex;
    annex.SetAttribute(attri);

    Equipment equipment(new CMEquipment("Armor", annex));

    return equipment;
}
