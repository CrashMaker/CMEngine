/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleNote.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月02日
*   描    述：
*
================================================================*/

#ifndef CMBATTLENOTE_H
#define CMBATTLENOTE_H

#include <vector>

#include "CMBattleLog.h"

namespace cmengine
{
    class CMBattleNote
    {
    private:
        std::vector<CMBattleLog> logVector;
    public:
        void Push(const CMBattleLog &log);
    };
}

#endif /* CMBATTLENOTE_H */
