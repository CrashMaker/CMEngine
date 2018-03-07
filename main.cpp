#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <memory>

#include "CMEngine/CMEngine.h"
#include "Source/SkillSource.h"

int main()
{
    using namespace std;
    using namespace cmengine;

    // default_random_engine e(time(0));
    // uniform_int_distribution<unsigned> u(1, 2);
    // for(int i=0; i<10; ++i)
    //     cout<<u(e)<<endl;
    // return 0;

    CMEngineRun();

    CMSpriteModel model_1;
    model_1.name = "战士";
    model_1.attack = 10;
    model_1.defense = 5;
    model_1.health = 30;
    CMSprite sp_1 = CMSprite(model_1);
    
    CMSpriteModel model_2;
    model_2.name = "骑士";
    model_2.attack = 8;
    model_2.defense = 6;
    model_2.health = 40;
    CMSprite sp_2 = CMSprite(model_2);

    // CMBaseSkill *baseSkill = new CMBaseSkill("BaseSkill");
    // CMSkill *skill = baseSkill;

    // auto skill = CMInstantiateSource<CMSkill>::InstantiateSkill(2);
    // std::cout << skill->GetName() << std::endl;

    CMSkill skill("CMSkill", 111);
    CMBaseSkill &baseSkill = skill;

    std::cout << typeid(baseSkill).name() << std::endl;
    return 0;
}
