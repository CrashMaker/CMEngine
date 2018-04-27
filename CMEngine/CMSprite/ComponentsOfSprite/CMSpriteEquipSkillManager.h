/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMSpriteEquipSkillManager.h
*   创 建 者：CrashMaker
*   创建日期：2018年04月27日
*   描    述：角色装配的技能管理类
*
================================================================*/

#ifndef CMSPRITEEQUIPSKILLMANAGER_H
#define CMSPRITEEQUIPSKILLMANAGER_H

#include "../../CMSkill/CMBaseSkill.h"
#include <vector>

namespace cmengine
{
    class CMSpriteEquipSkillManager
    {
    public:
        virtual ~CMSpriteEquipSkillManager() {}
    
        // 获取技能列表
        std::vector<CMBaseSkill*> GetSkillVec() const {return skillVec;}

        // 添加一个技能
        void Push(CMBaseSkill* skill, CMBaseSprite* caster, CMSkillDelegate* delegate)
        {
            skill->caster = caster;
            skill->delegate = delegate;
            
            skillVec.push_back(skill);
        }
    private:
        std::vector<CMBaseSkill*> skillVec;
    };
}

#endif /* CMSPRITEEQUIPSKILLMANAGER_H */
