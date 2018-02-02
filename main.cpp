#include <iostream>
#include "Source/SkillList.h"
#include "CMEngine/SkillManager.h"
#include "CMEngine/Skill.h"

int main()
{
    using namespace cmengine;

    SkillManager::loadSkills(loadSkillListForCMEngine());
    SkillManager::showSkills();
    
    return 0;
}

