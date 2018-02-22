#include <iostream>

#include "CMEngine/CMEngine.h"
#include "Source/SkillSource.h"

int main()
{
    using namespace cmengine;
    LoadSkillSourceForCMEngine();    

    Sprite sp_1 = Sprite("战士", 100, 200, 300);
    Sprite sp_2 = Sprite("猎人", 111, 222, 333);
    Skill skill = Skill("Cut");
    
    Attack attack = sp_1+skill>>sp_2;
    Round round = Round(attack);
    round.action();

    return 0;
}
