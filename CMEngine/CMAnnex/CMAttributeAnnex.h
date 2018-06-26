/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMAttributeAnnex.h
*   创 建 者：CrashMaker
*   创建日期：2018年06月26日
*   描    述：直接影响基础属性
*
================================================================*/

#ifndef CMATTRIBUTEANNEX_H
#define CMATTRIBUTEANNEX_H

#include "CMBaseAnnex.h"
#include "../CMAttribute/CMBasicAttribute.h"

namespace cmengine
{
    class CMAttributeAnnex : public CMBaseAnnex
    {
    public:
        CMAttributeAnnex(std::string name_) : CMBaseAnnex(name_) {}
        virtual ~CMAttributeAnnex() {}
    
        CMBasicAttribute GetAttribute() {return attribute;}

        void SetAttribute(const CMBasicAttribute& attri) {attribute = attri;}

    private:
        CMBasicAttribute attribute;
    };
}

#endif /* CMATTRIBUTEANNEX_H */
