/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleQueue.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年05月09日
*   描    述：
*
================================================================*/

#include "CMBattleQueue.h"
#include "../CMSprite/CMBaseSprite.h"

namespace cmengine
{
    // 获取行动角色
    CMBaseSprite* CMBattleQueue::GetActionSprite()
    {
        return nullptr;
    }

    /*==========私有方法==========*/

    // 队列排序
    void CMBattleQueue::SortQueue()
    {
        // 根据角色的速度(Speed)排序，如果相同则随机决定顺序
         
    }
}
