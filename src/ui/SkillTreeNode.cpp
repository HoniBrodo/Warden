#include "SkillTreeNode.h"

SkillTreeNode::SkillTreeNode()
{

}

void SkillTreeNode::Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, Color color) const
{
	render.DrawNodeCircle(centerX, centerY, innerCircleSize, outerCircleSize, color);
}
