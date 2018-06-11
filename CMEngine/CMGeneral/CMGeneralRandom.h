/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMGeneralRandom.h
*   创 建 者：CrashMaker
*   创建日期：2018年05月09日
*   描    述：
*
================================================================*/

#ifndef CMGENERALRANDOM_H
#define CMGENERALRANDOM_H

namespace cmengine
{
    class CMGeneralRandom
    {
    public:
        // 有0~100的概率返回true，默认概率50
        static bool ReturnTrueWithRandom(int probability = 50); 
    };
}

#endif /* CMGENERALRANDOM_H */
