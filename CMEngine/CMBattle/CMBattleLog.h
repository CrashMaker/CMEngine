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
#include <iostream>

namespace cmengine
{
    class CMBattleLog
    {
    public:
        virtual ~CMBattleLog() {}
    
        void PushLog(std::string log)
        {
            std::cout << "战斗日志：" << log << std::endl;
        }
    private:
        
    };
}

#endif /* CMBATTLELOG_H */
