#include "SkillTreeNode.h"



SkillTreeNode::SkillTreeNode(SkillLevel level)
{
    skillLevel = level;
}

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

void SkillTreeNode::DrawIcon(Renderer& render, std::string image, Vector2 pos, float rotation, float scale, Color tint, Color background)
{
	render.DrawSkillTreeIcon(image, pos, rotation, scale, tint, background);
}



