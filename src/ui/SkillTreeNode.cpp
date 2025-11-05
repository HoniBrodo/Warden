#include "SkillTreeNode.h"

SkillTreeNode::SkillTreeNode()
{

}

void SkillTreeNode::Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, Color color) 
{
	cenX = centerX;
	cenY = centerY;

    bool hovered = IsHovered();
    float scale = hovered ? 1.2f : 1.0f;

	render.DrawNodeCircle(centerX, centerY, innerCircleSize * scale, outerCircleSize * scale, color);
}

bool SkillTreeNode::IsHovered() const
{
	Vector2 mouse = GetMousePosition();
	Vector2 center = { (float)cenX, (float)cenY };

	return CheckCollisionPointCircle(mouse, center, (float)outerRadius);
}

void SkillTreeNode::nodeHoverFunctionality()
{
    if (IsHovered())
    {
        //currentPage = Page::CLASS_SELECT;
        outerRadius = 24;
        innerRadius = 20;
    }
    else
    {
        outerRadius = 22;
        innerRadius = 18;
    }
}

