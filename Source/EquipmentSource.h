/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：EquipmentSource.h
*   创 建 者：CrashMaker
*   创建日期：2018年06月27日
*   描    述：
*
================================================================*/

#ifndef EQUIPMENTSOURCE_H
#define EQUIPMENTSOURCE_H


#include "../CMEngine/CMEngine.h"

// 需要实现的函数
cmengine::CreateEquipmentFunMap cmengine::GetEquipSourceForCMEngine();

// 装备列表
cmengine::Equipment Sword();
cmengine::Equipment Armor();

#endif /* EQUIPMENTSOURCE_H */
