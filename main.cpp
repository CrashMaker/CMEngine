#include <iostream>

#include "CMEngine/CMEngine.h"
#include "Source/SkillList.h"

int main()
{
    using namespace cmengine;

    SkillManager::LoadSkills(LoadSkillListForCMEngine());
    SkillManager::ShowSkills();

    Sprite sp_1 = Sprite("战士", 33, 30, 300);
    Sprite sp_2 = Sprite("野猪", 20, 20, 100);

    std::cout << sp_1.health << "\t" <<sp_2.health << std::endl;
    sp_1("Cut")>>sp_2;
    std::cout << sp_1.health << "\t" <<sp_2.health << std::endl;

    return 0;
}
