/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMGeneralFunction.h
*   创 建 者：CrashMaker
*   创建日期：2018年06月11日
*   描    述：
*
================================================================*/

#ifndef CMGENERALFUNCTION_H
#define CMGENERALFUNCTION_H

namespace cmengine
{
    class CMGeneralFunction
    {
    public:
        // 控制数值的区间
        static float GetRangeOfValue(float num, float minNum, float maxNum);
    };
}

#endif /* CMGENERALFUNCTION_H */
