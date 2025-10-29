#pragma once
#include <string>
#include "../core/Renderer.h"
#include "raylib.h" 

class SkillTreeNode
{
public:
    SkillTreeNode();
    void Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, Color color) const;

private:

};