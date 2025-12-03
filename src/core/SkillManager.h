#pragma once
#include "Skill.h"
#include <unordered_map>
#include <string>
#include <vector>	

class BaseClass;

class SkillManager
{
public:
    bool loadFromJSON(const std::string& filePath);

    const Skill* getSkill(const std::string& id) const;

    bool canUnlock(const BaseClass& player, const std::string& id) const;
    bool unlockSkill(BaseClass& player, const std::string& id);

private:
    std::unordered_map<std::string, Skill> skills;

    void applyEffect(BaseClass& player, const BaseClass& effect) const;
};

