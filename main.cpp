#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <memory>

#include "CMEngine/CMEngine.h"

using namespace std;
using namespace cmengine;

int main()
{
    // default_random_engine e(time(0));
    // uniform_int_distribution<unsigned> u(1, 2);
    // for(int i=0; i<10; ++i)
    //     cout<<u(e)<<endl;
    // return 0;

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

