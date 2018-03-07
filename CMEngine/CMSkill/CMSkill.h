/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkill.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSKILL_H
#define CMSKILL_H

#include "CMBaseSkill.h"

namespace cmengine
{
    class CMSkill : public CMBaseSkill
    {
    private:

    public:
        int i;
        CMSkill(std::string name, int i_) : CMBaseSkill(name), i(i_) {}
        virtual ~CMSkill() {}
    };
}

#endif /* CMSKILL_H */
