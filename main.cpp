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
    h_2.SetLevel(10);
    CMBattleScene battleScene = CMBattleScene({&h_1}, {&h_2});
    
    // 模拟战斗
    CMBaseSprite* hero_1 = battleScene.GetFirstTeam()[0];
    CMBaseSkill* skill_1 = hero_1->GetSkillWithIndex(0);
    skill_1->Cast();
    
    // CMBaseSprite* hero_2 = battleScene.GetSecondTeam()[0];
    // CMBaseSkill* skill_2 = hero_2->GetSkillWithIndex(1);
    // 
    // hero_2->PrintAttribute();

    return 0;
}

