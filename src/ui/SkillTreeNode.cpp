#include "SkillTreeNode.h"

SkillTreeNode::SkillTreeNode()
{

}

void SkillTreeNode::Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, Color color) 
{
	cenX = centerX;
	render.DrawNodeCircle(centerX, centerY, innerCircleSize, outerCircleSize, color);
}

bool SkillTreeNode::IsHovered(Renderer& render) const
{
	return false;
}

Rectangle SkillTreeNode::GetBounds(Renderer& render, bool isFree) const
{
	Rectangle Bounds = {
		cenX - outerRadius,
		cenY - outerRadius,
		outerRadius * 2,
		outerRadius * 2
	};
	return Rectangle();
}
