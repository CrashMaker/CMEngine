/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleInterface.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年02月24日
*   描    述：
*
================================================================*/

#include "CMBattleInterface.h"

#include <sstream>

#include "CMSpriteInterface.h"

namespace cmengine
{
// ================对内函数，不可以打印日志================

//     int CMBattleInterface::MakeAttackPoint() const
//     {
//         int point = 0;
//         
//         if (DamageTypePhysical == skill.GetModel().damageType) {
//             point = caster.GetModel().attack;
//         } else if (DamageTypeMagic == skill.GetModel().damageType) {
//             point = caster.GetModel().magicAtk;
//         }
// 
//         return point;
//     }
// 
//     int CMBattleInterface::MakeDefensePoint() const
//     {
//         int point = 0;
//         
//         if (DamageTypePhysical == skill.GetModel().damageType) {
//             point = target.GetModel().defense;
//         } else if (DamageTypeMagic == skill.GetModel().damageType) {
//             point = target.GetModel().magicDef;
//         }
// 
//         return point;
//     }
// 
//     int CMBattleInterface::CreateHurtPoint(int attackPoint, int defensePoint) const
//     {
//         int point = 0;
// 
//         point = attackPoint = defensePoint;
//         if (point < 0) point = 0;
// 
//         return point;
//     }
// 
// // ================对外接口，可以打印日志==================
// 
//     void CMBattleInterface::Blow(float multiplication, int addition) const
//     {
//         std::string log = caster.GetModel().name 
//                           + "对" 
//                           + target.GetModel().name 
//                           + "使用" 
//                           + skill.GetModel().name;
// 
//         int attackPoint = MakeAttackPoint() * multiplication + addition;
//         int defensePoint = MakeDefensePoint();
//         int resultPoint = CreateHurtPoint(attackPoint, defensePoint);
// 
//         std::stringstream stream;
//         stream << resultPoint;
//         log = log + ", 造成" + stream.str() + "点伤害";
// 
//         stream.str("");
//         stream << defensePoint;
//         log = log + "(" + stream.str() + "点被抵抗)";
// 
//         // 添加Log至战斗记录
//         note.Push(CMBattleLog(log));
// 
//         CMSpriteInterface spriteInterface = CMSpriteInterface(target, note);
//         spriteInterface.Hurt(resultPoint);
//     }
}
