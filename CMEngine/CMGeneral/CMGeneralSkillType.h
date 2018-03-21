/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMGeneralSkillType.h
*   创 建 者：CrashMaker
*   创建日期：2018年03月13日
*   描    述：
*
================================================================*/

#ifndef CMGENERALSKILLTYPE_H
#define CMGENERALSKILLTYPE_H

namespace cmengine
{
    enum SkillAttackType { 
        SkillAttackTypeMelee,        // 近战
        SkillAttackTypeRemote,       // 远程
    };

    enum SkillDamageType {
        SkillDamageTypePhysical,     // 物理伤害
        SkillDamageTypeMagic,        // 魔法伤害
    };
}

#endif /* CMGENERALSKILLTYPE_H */
