/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSprite.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSPRITE_H
#define CMSPRITE_H

#include <string>

namespace cmengine
{
    using std::string;
    
    class CMSprite
    {
    private:
        string name;

    public:
        CMSprite(string name_) : name(name_) {} 

    };
}

#endif /* CMSPRITE_H */
