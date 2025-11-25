#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "../core/Renderer.h"
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

    SkillTreeNode(SkillLevel level);
    SkillTreeNode();
    //void MakeNodesTransparent(std::vector<SkillTreeNode>& allNodes);
    void Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, std::string label);
    bool IsHovered() const;
    void DrawIcon(Renderer& render, std::string image, Vector2 pos, float rotation, float scale, Color tint, Color background);
    void SetNodeAvailability(const std::string& availability);

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