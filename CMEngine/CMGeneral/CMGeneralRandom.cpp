/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMGeneralRandom.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年05月09日
*   描    述：
*
================================================================*/

#include "CMGeneralRandom.h"
#include <random>

namespace cmengine
{
    // 有0~100的概率返回true，默认概率50
    bool CMGeneralRandom::ReturnTrueWithRandom(int probability)
    {
        std::default_random_engine e(time(0));
        std::uniform_int_distribution<unsigned> u(1, 100);
        int random = u(e);
        if (probability >= random) {
            return true;
        }

        return false;
    }
}
