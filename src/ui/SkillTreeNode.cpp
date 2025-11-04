#include "SkillTreeNode.h"

SkillTreeNode::SkillTreeNode()
{

}

void SkillTreeNode::Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, Color color) 
{
	cenX = centerX;
	cenY = centerY;
	outerRadius = outerCircleSize;
	innerRadius = innerCircleSize;
	render.DrawNodeCircle(centerX, centerY, innerCircleSize, outerCircleSize, color);
}

bool SkillTreeNode::IsHovered() const
{
	Vector2 mouse = GetMousePosition();
	Vector2 center = { (float)cenX, (float)cenY };

	return CheckCollisionPointCircle(mouse, center, (float)outerRadius);
}

