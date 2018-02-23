/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSourceManager.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSOURCEMANAGER_H
#define CMSOURCEMANAGER_H

#include <map>

namespace cmengine
{
    using std::map;

    class CMSourceManager
    {
    private:
        static map<int, int> skillMap; 
    public:
        static void LoadSkill();
    };
}

#endif /* CMSOURCEMANAGER_H */
