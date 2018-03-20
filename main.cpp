#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <memory>

#include "CMEngine/CMEngine.h"

using namespace std;
using namespace cmengine;

class TestClass : CMSkillCastTargetDelegate
{
public:
    // TestClass(const CMSpriteModel& model_1, const CMSpriteModel& model_2, const CMSpriteModel& model_3)
    //     : sp_1(model_1), sp_2(model_2), sp_3(model_3) {}
    // 
    // virtual CMSprite* GetTarget();
    // virtual vector<CMSprite*> GetTargetVector();
    // void Run();
private:
    // CMSprite sp_1;
    // CMSprite sp_2;
    // CMSprite sp_3;
};

// CMSprite* TestClass::GetTarget()
// {
//     return &sp_2;
// }
// 
// vector<CMSprite*> TestClass::GetTargetVector()
// {
//     vector<CMSprite*> vec = {
//         &sp_2, 
//         &sp_3,
//     };
// 
//     return vec;
// }
// 
// void TestClass::Run()
// {
//     CMNormalSkill skill = CMInstantiateSource<CMNormalSkill>::InstantiateSkill(1);
//     skill.delegate = this;
//     skill.Cast(&sp_1);
// }
// 
int main()
{
    // default_random_engine e(time(0));
    // uniform_int_distribution<unsigned> u(1, 2);
    // for(int i=0; i<10; ++i)
    //     cout<<u(e)<<endl;
    // return 0;

    CMEngineRun();

    CMHeroSprite hero = CMInstantiateSource<CMHeroSprite>::InstantiateHero(1);
    std::cout << hero.GetName() << std::endl;

    // CMSpriteModel model_1;
    // model_1.name = "战士";
    // model_1.attack = 20;
    // model_1.defense = 10;
    // model_1.health = 11;
    // 
    // CMSpriteModel model_2;
    // model_2.name = "法师";
    // model_2.attack = 20;
    // model_2.defense = 10;
    // model_2.health = 22;
    // 
    // CMSpriteModel model_3;
    // model_3.name = "猎人";
    // model_3.attack = 20;
    // model_3.defense = 10;
    // model_3.health = 33;
    // 
    // TestClass test(model_1, model_2, model_3);
    // test.Run();

    return 0;
}
    
