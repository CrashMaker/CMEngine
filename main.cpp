#include <iostream>
#include <string>
#include <random>
#include <ctime>

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

    sp_1+1>>sp_2;
    sp_1+1>>sp_2;
    sp_1+1>>sp_2;
    sp_1+1>>sp_2;
    sp_1+1>>sp_2;
    sp_1+1>>sp_2;
    sp_1+1>>sp_2;
    sp_1+1>>sp_2;
    sp_1+1>>sp_2;
    sp_1+1>>sp_2;

    return 0;
}
