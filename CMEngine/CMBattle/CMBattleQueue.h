/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleQueue.h
*   创 建 者：CrashMaker
*   创建日期：2018年05月09日
*   描    述：获取战斗队列
*
================================================================*/

#ifndef CMBATTLEQUEUE_H
#define CMBATTLEQUEUE_H

#include <vector>

namespace cmengine
{
    class CMBaseSprite;

    class CMBattleQueue
    {
    public:
        CMBattleQueue(std::vector<CMBaseSprite*> firstTeam_, std::vector<CMBaseSprite*> secondTeam_) 
            : firstTeam(firstTeam_), secondTeam(secondTeam_) {
            battleTeam.insert(battleTeam.end(), firstTeam.begin(), firstTeam.end());
            battleTeam.insert(battleTeam.end(), secondTeam.begin(), secondTeam.end()); 
        }
        virtual ~CMBattleQueue() {}
    
        // 获取行动角色
        CMBaseSprite* GetActionSprite();

    private:
        // 队列排序
        void SortQueue();

    private:
        std::vector<CMBaseSprite*> firstTeam;
        std::vector<CMBaseSprite*> secondTeam;
        std::vector<CMBaseSprite*> battleTeam;
    };
}

#endif /* CMBATTLEQUEUE_H */
