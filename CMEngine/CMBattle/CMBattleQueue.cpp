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
#include "../CMGeneral/CMGeneralRandom.h"

namespace cmengine
{
    // 获取行动角色
    CMBaseSprite* CMBattleQueue::GetActionSprite()
    {
        if ((int)spriteQueue.size() <= 0) {
            SortQueue();
        }

        CMBaseSprite* sprite = spriteQueue.front();
        spriteQueue.erase(spriteQueue.begin());

        return sprite;
    }

    /*==========私有方法==========*/

    // 队列排序
    void CMBattleQueue::SortQueue()
    {
        spriteQueue.clear();
        spriteQueue = battleTeam;
        int maxIndex = 0;

        // 根据角色的速度(Speed)排序，如果相同则随机决定顺序
        for (int i=0; i<(int)spriteQueue.size()-1; i++) {
            maxIndex = i;
            for (int j=i+1; j<(int)spriteQueue.size(); j++) {
                int speed_i = battleTeam[i]->GetCurrentAttribute().GetSpeed();
                int speed_j = battleTeam[j]->GetCurrentAttribute().GetSpeed();
                if (speed_j > speed_i) {
                    maxIndex = j;
                } else if (speed_j == speed_i) {
                    if(CMGeneralRandom::ReturnTrueWithRandom()) {
                        maxIndex = j;
                    }
                }
            } 
            // 交换元素
            std::swap(spriteQueue[i], spriteQueue[maxIndex]);
        } 
    }
}
