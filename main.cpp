#include "CMEngine/CMEngine.h"
#include <iostream>
#include <string>

using namespace std;
using namespace cmengine;

int main()
{
    CMEngineRun();

    CMEquipment e_1 = CMInstantiateSourceTemplate<CMEquipment>::Instantiate(InstantiateType::Equipment, 1);
    CMEquipment e_2 = CMInstantiateSourceTemplate<CMEquipment>::Instantiate(InstantiateType::Equipment, 2);

    CMHeroSprite h_1 = CMInstantiateSourceTemplate<CMHeroSprite>::Instantiate(InstantiateType::Hero, 1);
    h_1.SetLevel(10);
    h_1.Equip(e_1);

    CMHeroSprite h_2 = CMInstantiateSourceTemplate<CMHeroSprite>::Instantiate(InstantiateType::Hero, 2);
    h_2.SetLevel(10);
    h_2.Equip(e_2);

    CMBattleScene battleScene = CMBattleScene({&h_1}, {&h_2});
    battleScene.Battle();

    return 0;
}

