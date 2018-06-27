/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMEquipment.h
*   创 建 者：CrashMaker
*   创建日期：2018年06月26日
*   描    述：
*
================================================================*/

#include "../CMAnnex/CMAttributeAnnex.h"

namespace cmengine
{
    class CMEquipment
    {
    public:
        CMEquipment(std::string name_, CMAttributeAnnex annex) : name(name_), attributeAnnex(annex) {}
        virtual ~CMEquipment() {}

        CMAttributeAnnex GetAttributeAnnex() {return attributeAnnex;}
    
    private:
        std::string name;
        CMAttributeAnnex attributeAnnex;
    };
}
