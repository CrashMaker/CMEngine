/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMStateLog.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月26日
*   描    述：
*
================================================================*/

#ifndef CMSTATELOG_H
#define CMSTATELOG_H

#include <iostream>
#include <vector>

namespace cmengine
{
    using std::string;
    using std::vector;

    class CMStateLog
    {
    private:
        vector<string> logVec;

    public:
        CMStateLog(string caster, string target, string skill);

        void Push(string log);
        void Clean();
        void Print();
    };
}

#endif /* CMSTATELOG_H */
