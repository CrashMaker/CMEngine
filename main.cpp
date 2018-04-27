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

    CMHeroSprite hero_1 = CMInstantiateSource<CMHeroSprite>::InstantiateHero(1);
    hero_1.SetLevel(8);
    
    CMHeroSprite hero_2 = CMInstantiateSource<CMHeroSprite>::InstantiateHero(2);
    hero_2.SetLevel(10);

    vector<CMBaseSprite*> firstTeam = {&hero_1};
    vector<CMBaseSprite*> secondTeam = {&hero_2};
    CMBattleScene battleScene = CMBattleScene(firstTeam, secondTeam);
    
    CMHitSkill skill = CMInstantiateSource<CMHitSkill>::InstantiateSkill(1);
    skill.caster = &hero_1;
    skill.delegate = &battleScene;
    skill.Cast();

    hero_2.PrintAttribute();

    return 0;
}
    
