/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSkillModel.h
*   创 建 者：CrashMaker
*   创建日期：2018年02月23日
*   描    述：
*
================================================================*/

#ifndef CMSKILLMODEL_H
#define CMSKILLMODEL_H

#include <string>
#include <functional>

namespace cmengine
{
    using std::string;
    using std::function;
    class CMSkill;
    class CMBattleInterface;

    enum AttackType { 
        AttackTypeMelee,        // 近战
        AttackTypeRemote,       // 远程
    };

    enum DamageType {
        DamageTypePhysical,     // 物理伤害
        DamageTypeMagic,        // 魔法伤害
    };

    struct CMSkillModel
    {
        string name;            
        AttackType attackType;
        DamageType damageType;

        function<void(const CMBattleInterface &interface)> logicFun;
    };
}

#endif /* CMSKILLMODEL_H */
