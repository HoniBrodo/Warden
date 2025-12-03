#include "SkillManager.h"
#include "../player/BaseClass.h"
#include <fstream>
#include "../external/json/json.hpp"

using json = nlohmann::json;

bool SkillManager::loadFromJSON(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) return false;

    json data;
    file >> data;

    for (auto& item : data["skills"]) {
        Skill s;
        s.id = item["id"];
        s.name = item["name"];
        s.description = item["description"];

        // prerequisites
        for (auto& p : item["prereqs"])
            s.prereqs.push_back(p);

        skills[s.id] = s;
    }

    return true;
}

const Skill* SkillManager::getSkill(const std::string& id) const {
    auto it = skills.find(id);
    if (it == skills.end()) return nullptr;
    return &it->second;
}

//bool SkillManager::canUnlock(const BaseClass& player, const std::string& id) const {
//    auto* skill = getSkill(id);
//    if (!skill) return false;
//
//    // To do: Create a list of aquaired skills in BaseClass via a std::unordered_set<std::string>
//    for (auto& p : skill->prereqs) {
//        if (!player.hasSkill(p)) return false;
//    }
//
//    return player.skillPoints >= skill->cost;
//}

//bool SkillManager::unlockSkill(BaseClass& player, const std::string& id) {
//    // to do: figure this out
// 
//    if (!canUnlock(player, id)) return false;
//
//    auto* skill = getSkill(id);
//    player.skillPoints -= skill->cost;
//    player.learnSkill(id);
//
//    for (const auto& effect : skill->effects)
//        applyEffect(player, effect);
//
//    return true;
//}
