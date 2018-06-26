/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBasicAttribute.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年06月26日
*   描    述：
*
================================================================*/

#include "CMBasicAttribute.h"

namespace cmengine
{
    CMBasicAttribute CMBasicAttribute::operator+(const CMBasicAttribute& attri)
    {
        CMBasicAttribute resultAttri;
        
        resultAttri.SetAttack(GetAttack()+attri.GetAttack());
        resultAttri.SetDefense(GetDefense()+attri.GetDefense());
        resultAttri.SetMagicAtk(GetMagicAtk()+attri.GetMagicAtk());
        resultAttri.SetMagicDef(GetMagicDef()+attri.GetMagicDef());
        resultAttri.SetHealth(GetHealth()+attri.GetHealth());
        resultAttri.SetMana(GetMana()+attri.GetMana());
        resultAttri.SetSpeed(GetSpeed()+attri.GetSpeed());

        return resultAttri;
    }

    CMBasicAttribute CMBasicAttribute::operator-(const CMBasicAttribute& attri)
    {
        CMBasicAttribute resultAttri;

        resultAttri.SetAttack(GetAttack()-attri.GetAttack());
        resultAttri.SetDefense(GetDefense()-attri.GetDefense());
        resultAttri.SetMagicAtk(GetMagicAtk()-attri.GetMagicAtk());
        resultAttri.SetMagicDef(GetMagicDef()-attri.GetMagicDef());
        resultAttri.SetHealth(GetHealth()-attri.GetHealth());
        resultAttri.SetMana(GetMana()-attri.GetMana());
        resultAttri.SetSpeed(GetSpeed()-attri.GetSpeed());

        return resultAttri;
    }
}
