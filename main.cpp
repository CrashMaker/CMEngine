#include "CMEngine/CMEngine.h"
#include <iostream>
#include <string>

using namespace std;
using namespace cmengine;

int main()
{
    CMEngineRun();

    CMHeroSprite h_1 = CMInstantiateSourceTemplate<CMHeroSprite>::Instantiate(InstantiateType::Hero, 1);
    h_1.SetLevel(10);
    CMHeroSprite h_2 = CMInstantiateSourceTemplate<CMHeroSprite>::Instantiate(InstantiateType::Hero, 2);
    h_2.SetLevel(10);

    CMBattleScene battleScene = CMBattleScene({&h_1}, {&h_2});
    battleScene.Battle();
    
    return 0;
}

