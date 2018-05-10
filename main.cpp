#include "CMEngine/CMEngine.h"
#include <iostream>
#include <string>

using namespace std;
using namespace cmengine;

int main()
{
    CMEngineRun();

    CMHeroSprite h_1 = CMInstantiateSourceTemplate<CMHeroSprite>::InstantiateHero(1);
    h_1.SetLevel(10);
    CMHeroSprite h_2 = CMInstantiateSourceTemplate<CMHeroSprite>::InstantiateHero(2);
    h_2.SetLevel(8);

    CMBattleLog battleLog;
    CMBattleScene battleScene = CMBattleScene({&h_1}, {&h_2});
    battleScene.Start(&battleLog);
    
    return 0;
}

