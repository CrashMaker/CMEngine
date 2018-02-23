#include <iostream>
#include <string>
#include <functional>

#include "CMEngine/CMEngine.h"
#include "Source/SkillSource.h"

using namespace std;

void Cut(string &name, function<void(int power)> &f);
void Hit(int point);

int main()
{
    using namespace cmengine;
    CMEngineRun();
    
    CMSprite sp_1 = CMSprite("战士");
    CMSprite sp_2 = CMSprite("猎人");
    CMSkill cut = CMSkill("Cut");
    
    // Attack attack = Attack(sp_1, sp_2, cut);
    // Round round = Round(attack);
    // round.action();

    sp_1+cut>>sp_2;

    // string name;
    // int power = 123;
    // int health = 1000;
    // function<void(int power)> f;
    // 
    // Cut(name, f);
    // f(power);
    // 
    // std::cout << name << std::endl;

    return 0;
}

void Cut(string &name, function<void(int power)> &f)
{
    name = "I am Cut";
    f = [](int power){
        Hit(power*2);
    };
}

void Hit(int point)
{

}
