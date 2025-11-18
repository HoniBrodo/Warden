#pragma once
#include <vector>
#include <string>
#include "../core/Renderer.h"
#include "raylib.h" 

enum class SkillLevel
{
    TRAINED,
    EXPERT,
    MASTER
};

class SkillTreeNode
{
public:

    SkillTreeNode(SkillLevel level);
    SkillTreeNode();
    //void MakeNodesTransparent(std::vector<SkillTreeNode>& allNodes);
    void Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, Color color, std::string label);
    bool IsHovered() const;
    void DrawIcon(Renderer& render, std::string image, Vector2 pos, float rotation, float scale, Color tint, Color background);

    SkillLevel skillLevel = SkillLevel::TRAINED;
    int outerRadius{ 22 };
    int innerRadius{ 18 };
    int cenX{};
    int cenY{};

    bool isTransparent = false;

    Color iconColor{ SKYBLUE };


private:




};