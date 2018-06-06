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
    // 选择角色的技能，返回技能下标
    int CMBattleChoose::ChooseSkillIndexFromSprite(CMBaseSprite* sprite)
    {
        std::vector<std::string> vec;
        for (int i = 0; i < (int)sprite->GetSkillList().size(); ++i) {
            BaseSkill sk = CMInstantiateSource::InstantiateSkill(sprite->GetSkillList()[i]);
            vec.push_back(sk->GetName());
        }
        int index = SelectIndexWithVector(vec, "选择技能：");
        
        return sprite->GetSkillList()[index];
    }

    /* ==========私有方法========== */

    // 根据施法者获取指定的队伍
    std::vector<CMBaseSprite*> CMBattleChoose::GetTeamWithCaster(CMBaseSprite* sprite, BattleChooseTeam chooseTeam)
    {
        std::vector<CMBaseSprite*> allTeam;
        allTeam.insert(allTeam.end(), firstTeam.begin(), firstTeam.end());
        allTeam.insert(allTeam.end(), secondTeam.begin(), secondTeam.end());
        if (BattleChooseTeam::BattleChooseTeamOfAll == chooseTeam) {return allTeam;}

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

        if (BattleChooseTeam::BattleChooseTeamOfSelf == chooseTeam) {
            return selfTeam;
        } else if (BattleChooseTeam::BattleChooseTeamOfAnother == chooseTeam) {
            return anotherTeam;
        } else {
            return allTeam;
        }
    }

    // 根据数组选择下标
    int CMBattleChoose::SelectIndexWithVector(std::vector<std::string> vec, std::string tipText)
    {
        int result = 0;
        bool action = true;

        do {
            std::cout << tipText;
            for (int i = 0; i < (int)vec.size(); ++i) {
                std::cout << i+1 << "." << vec[i] << " "; 
            }
            std::cout << std::endl;

            std::cin >> result;

            if (std::cin.fail()) {
                exit(0);
            }

            result -= 1;
            if (result >= 0 && result < (int)vec.size()) {
                action = false;
            } else {
                std::cout << "输入错误，请重新输入" << std::endl;
            }
        } while(action);
        
        return result;
    }

    /* ==========实现的协议========== */

    // 选取目标
    CMBaseSprite* CMBattleChoose::ObtainTarget(CMBaseSprite* caster)
    {
        std::vector<CMBaseSprite*> targetTeam = GetTeamWithCaster(caster, BattleChooseTeam::BattleChooseTeamOfAnother);

        std::vector<std::string> vec;
        for (int i = 0; i < (int)targetTeam.size(); ++i) {
            CMBaseSprite* sp = targetTeam[i];
            vec.push_back(sp->GetName());
        }
        int index = SelectIndexWithVector(vec, "选择目标：");
        
        return targetTeam[index];
    }
}
