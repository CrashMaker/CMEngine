/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMStateLog.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月26日
*   描    述：
*
================================================================*/

#include "CMStateLog.h"
#include <iostream>

namespace cmengine
{
    CMStateLog::CMStateLog(string caster, string target, string skill)
    {
        string log = caster + " 对 " + target + " 施放技能 " + skill;
        logVec.push_back(log);
    }

    void CMStateLog::Push(string log)
    {
        logVec.push_back(log);
    }
    
    void CMStateLog::Clean()
    {
        logVec.clear();
    }

    void CMStateLog::Print()
    {
        vector<string>::iterator it;
        for (it = logVec.begin(); it != logVec.end(); it++) {
            std::cout << *it << std::endl;
        } 
    }
}
