#pragma once

#include "../external/json.hpp"
#include <fstream>

using json = nlohmann::json;

class SkillManager {
public:

	json LoadSkillTree(const std::string& filepath);

private:

};