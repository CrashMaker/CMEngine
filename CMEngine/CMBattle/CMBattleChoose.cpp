/*================================================================
*   Copyright (C) 2018 CrashMaker. All rights reserved.
*   
*   文件名称：CMBattleChoose.cpp
*   创 建 者：CrashMaker
*   创建日期：2018年05月07日
*   描    述：
*
================================================================*/

#include "CMBattleChoose.h"
#include "../CMSourceManager/CMInstantiateSource.h"
#include <iostream>

namespace cmengine
{
    // 选择角色的技能，返回技能编号
    int CMBattleChoose::ChooseSkillIndexFromSprite(CMBaseSprite* sprite)
    {
        int result = 0;
        bool action = true;
        do {
            std::cout << "选择技能：";
            for (int i = 0; i < (int)sprite->GetSkillList().size(); ++i) {
                BaseSkill sk = CMInstantiateSource::InstantiateSkill(sprite->GetSkillList()[i]);
                std::cout << i+1 << "." << sk->GetName() << " "; 
            }
            std::cout << std::endl;
            
            std::cin >> result;
            result -= 1;
            if (result >= 0 && result < (int)sprite->GetSkillList().size()) {
                action = false;
            } else {
                std::cout << "输入错误，请重新选择" << std::endl;
            }
        } while(action);
        
        return sprite->GetSkillList()[result];
    }

    /* ==========私有方法========== */

    // 根据施法者获取指定的队伍
    std::vector<CMBaseSprite*> CMBattleChoose::GetTeamWithCaster(CMBaseSprite* sprite, BattleChooseTeam chooseTeam)
    {
        std::vector<CMBaseSprite*> allTeam;
        allTeam.insert(allTeam.end(), firstTeam.begin(), firstTeam.end());
        allTeam.insert(allTeam.end(), secondTeam.begin(), secondTeam.end());
        if (BattleChooseTeamOfAll == chooseTeam) {return allTeam;}

        std::vector<CMBaseSprite*> selfTeam;
        std::vector<CMBaseSprite*> anotherTeam;

        std::vector<CMBaseSprite*>::iterator it_1;
        it_1 = std::find(firstTeam.begin(), firstTeam.end(), sprite);
        if (it_1 != firstTeam.end()) {
            selfTeam = firstTeam;
            anotherTeam = secondTeam;
        }

        std::vector<CMBaseSprite*>::iterator it_2;
        it_2 = std::find(secondTeam.begin(), secondTeam.end(), sprite);
        if (it_2 != secondTeam.end()) {
            selfTeam = secondTeam;
            anotherTeam = firstTeam;
        }

        if (BattleChooseTeamOfSelf == chooseTeam) {
            return selfTeam;
        } else if (BattleChooseTeamOfAnother == chooseTeam) {
            return anotherTeam;
        } else {
            return allTeam;
        }
    }

    /* ==========实现的协议========== */

    // 选取目标
    CMBaseSprite* CMBattleChoose::ObtainTarget(CMBaseSprite* caster)
    {
        std::vector<CMBaseSprite*> targetTeam = GetTeamWithCaster(caster, BattleChooseTeamOfAnother);
        int result = 0;
        bool action = true;
        do {
            std::cout << "选择目标：";
            for (int i = 0; i < (int)targetTeam.size(); ++i) {
                CMBaseSprite* sp = targetTeam[i];
                std::cout << i+1 << "." << sp->GetName() << " "; 
            }
            std::cout << std::endl;
            
            std::cin >> result;
            result -= 1;
            if (result >= 0 && result < (int)targetTeam.size()) {
                action = false;
            } else {
                std::cout << "输入错误，请重新选择" << std::endl;
            }
        } while(action);
        
        return targetTeam[result];
    }
}
