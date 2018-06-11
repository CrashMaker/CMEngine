/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMGeneralFunction.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年06月11日
*   描    述：
*
================================================================*/

#include "CMGeneralFunction.h"

namespace cmengine
{
    // 控制数值的区间
    float CMGeneralFunction::GetRangeOfValue(float num, float minNum, float maxNum)
    {
        if (num < minNum) {
            return minNum;
        } else if (num > maxNum) {
            return maxNum;
        } else {
            return num;
        }
    }
}
