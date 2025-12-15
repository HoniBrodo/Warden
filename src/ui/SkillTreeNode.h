#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include "../core/Renderer.h"
#include "../player/SkillManager.h"
#include "raylib.h" 

enum class SkillLevel
{
    TRAINED,
    EXPERT,
    MASTER
};

enum class NodeAvailability
{
    AVAILABLE,
    UNAVAILABLE, 
    SELECTED,
    MANDATORY
};

class SkillTreeNode
{
public:

    SkillManager skillManager;
    json skillsJson = skillManager.LoadSkillTree("../../src/player/SkillTree.json");
    SkillTreeNode(SkillLevel level);
    SkillTreeNode();
    void Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, std::string label);
    bool IsHovered() const;
    bool IsClicked() const;
    void DrawIcon(Renderer& render, std::string image, Vector2 pos, float rotation, float scale, Color tint, Color background);
    NodeAvailability GetNodeAvailability() { return nodeAvailability; }
    // make the function here
    void NodeUnlocksAvailable(const std::string& skillName, const std::unordered_map<std::string, SkillTreeNode*>& allSkills);





    SkillLevel skillLevel = SkillLevel::TRAINED;
    NodeAvailability nodeAvailability = NodeAvailability::AVAILABLE;
    int outerRadius{ 22 };
    int innerRadius{ 18 };
    int cenX{};
    int cenY{};

    bool isTransparent = false;

    Color nodeColor = DARKGREEN;
    Color iconColor{ SKYBLUE };


private:




};