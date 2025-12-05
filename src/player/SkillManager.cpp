#include "SkillManager.h"

json SkillManager::LoadSkillTree(const std::string& filepath)
{
    std::ifstream file(filepath);
    json data;
    file >> data;   // parse JSON
    return data;
}
