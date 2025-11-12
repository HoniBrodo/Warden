#include "SkillTreeNode.h"



SkillTreeNode::SkillTreeNode()
{
}

void SkillTreeNode::Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, Color color, std::string label)
{
	cenX = centerX;
	cenY = centerY;

    bool hovered = IsHovered();
    float scale = hovered ? 1.2f : 1.0f;

	render.DrawNodeCircle(centerX, centerY - 10, innerCircleSize * scale, outerCircleSize * scale, color);

    render.DrawTextBlockNoPadding(label, centerX - 60, centerY + 80, 120, TextAlign::Center, TextSize::SkillTreeNode);
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

