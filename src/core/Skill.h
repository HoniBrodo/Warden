#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class Skill
{
public:
    std::string id;
    std::string name;
    std::string description;

    std::vector<std::string> prereqs;
};