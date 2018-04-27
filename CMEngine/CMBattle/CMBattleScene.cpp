/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleScene.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年04月27日
*   描    述：
*
================================================================*/

#include "CMBattleScene.h"

namespace cmengine
{
    CMBaseSprite* CMBattleScene::ObtainTarget()
    {
        return secondTeam[0];
    }  
}
