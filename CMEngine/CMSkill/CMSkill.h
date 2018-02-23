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

#include <string>

namespace cmengine
{
    using std::string;
    
    class CMSkill
    {
    private:
        string name;

    public:
        CMSkill(string name_) : name(name_) {} 

    };
}

#endif /* CMSKILL_H */
