#include <iostream>
#include "Source/SkillList.h"
#include "CMEngine/SkillManager.h"
#include "CMEngine/Skill.h"

int main()
{
    using namespace cmengine;

    SkillManager::LoadSkills(LoadSkillListForCMEngine());
    SkillManager::ShowSkills();
    
    SkillPtr sk = SkillManager::GetSkillWithKey("Cut");
    sk->action();
    
    return 0;
}

