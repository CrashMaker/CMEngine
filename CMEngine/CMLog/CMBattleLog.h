/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleLog.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月02日
*   描    述：
*
================================================================*/

#ifndef CMBATTLELOG_H
#define CMBATTLELOG_H

#include <string>

namespace cmengine
{
    class CMBattleLog
    {
    private:
        std::string log;

    public:
        CMBattleLog(std::string log_) : log(log_) {}

        std::string GetLog() const {return log;}
    };
}

#endif /* CMBATTLELOG_H */
