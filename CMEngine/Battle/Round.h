/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：Round.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月12日
*   描    述：战斗回合，分五个阶段依次进行——回合开始，战斗阶段，
*             回合结束。
*
================================================================*/

#ifndef ROUND_H
#define ROUND_H

#include "Attack.h"

namespace cmengine
{
    class Round
    {
    private:
        Attack &attack;
        
        void Begin();
        void Battle();
        void Finish();
    public:
        Round(Attack &attack_) : attack(attack_) {}

        void action();
    };
}

#endif /* ROUND_H */
