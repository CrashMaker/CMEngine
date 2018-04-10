#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <memory>

#include "CMEngine/CMEngine.h"

using namespace std;
using namespace cmengine;

class TestClass : public CMSkillCastTargetDelegate
{
public:
    TestClass(CMBaseSprite* hero_, CMBaseSprite* monster_)
        : hero(hero_), monster(monster_) {}
    
    virtual CMBaseSprite* ObtainCaster();
    virtual CMBaseSprite* ObtainTarget();
    virtual std::vector<CMBaseSprite*> ObtainTargetVector();
    
    void Run();
private:
    CMBaseSprite* hero;
    CMBaseSprite* monster;
};

CMBaseSprite* TestClass::ObtainCaster()
{
    return hero;
}

CMBaseSprite* TestClass::ObtainTarget()
{
    return monster;
}

vector<CMBaseSprite*> TestClass::ObtainTargetVector()
{
    vector<CMBaseSprite*> vec = {
        hero, 
        monster,
    };

    return vec;
}

void TestClass::Run()
{
    CMHealSkill skill = CMInstantiateSource<CMHealSkill>::InstantiateSkill(1);
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

    CMHeroSprite hero = CMInstantiateSource<CMHeroSprite>::InstantiateHero(1);
    hero.SetLevel(5);
    
    CMMonsterSprite monster = CMInstantiateSource<CMMonsterSprite>::InstantiateSprite(1);
    monster.SetLevel(9);

    TestClass test(&hero, &monster);
    test.Run();

    return 0;
}
    
