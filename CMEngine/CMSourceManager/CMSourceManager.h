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

#include "../CMGeneral/CMBaseType.h"

namespace cmengine
{
    class CMSourceManager
    {
    private:
        static SkillMap skillMap; 
    public:
        static void LoadSkill();
    };
}

#endif /* CMSOURCEMANAGER_H */
