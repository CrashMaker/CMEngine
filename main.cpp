#include <iostream>
#include "Source/SkillList.h"
#include "CMEngine/SkillManager.h"
#include "CMEngine/Skill.h"

int main()
{
    using namespace cmengine;

    SkillManager::LoadSkills(LoadSkillListForCMEngine());
    SkillManager::ShowSkills();

    Skill sk = SkillManager::GetSkillWithKey(0);
    sk.action();
    
    return 0;
}

