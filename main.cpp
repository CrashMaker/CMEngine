#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <memory>

#include "CMEngine/CMEngine.h"

using namespace std;
using namespace cmengine;

class TestClass : public CMSkillTargetDelegate
{
public:
    TestClass(CMBaseSprite* hero_1_, CMBaseSprite* hero_2_)
        : hero_1(hero_1_), hero_2(hero_2_) {}
    
    virtual CMBaseSprite* ObtainTarget();
    
    void Run();
private:
    CMBaseSprite* hero_1;
    CMBaseSprite* hero_2;
};

CMBaseSprite* TestClass::ObtainTarget()
{
    return hero_2;
}

void TestClass::Run()
{
    CMHitSkill skill = CMInstantiateSource<CMHitSkill>::InstantiateSkill(1);
    skill.delegate = this;
    skill.Cast();
}

int main()
{
    // default_random_engine e(time(0));
    // uniform_int_distribution<unsigned> u(1, 2);
    // for(int i=0; i<10; ++i)
    //     cout<<u(e)<<endl;
    // return 0;

    CMEngineRun();

    CMHeroSprite hero_1 = CMInstantiateSource<CMHeroSprite>::InstantiateHero(1);
    hero_1.SetLevel(5);
    
    CMHeroSprite hero_2 = CMInstantiateSource<CMHeroSprite>::InstantiateHero(2);
    hero_2.SetLevel(9);

    hero_2.PrintAttribute();
    TestClass test(&hero_1, &hero_2);
    hero_2.PrintAttribute();
    test.Run();
    hero_2.PrintAttribute();

    return 0;
}
    
