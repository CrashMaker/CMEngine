#include <iostream>

#include "CMEngine/CMEngine.h"

int main()
{
    using namespace cmengine;
        
    Sprite sp_1 = Sprite("战士", 100, 200, 300);
    Sprite sp_2 = Sprite("猎人", 111, 222, 333);
    Skill skill = Skill("Cut");
    
    sp_1+skill>>sp_2;
    
    return 0;
}
