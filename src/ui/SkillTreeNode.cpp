#include "SkillTreeNode.h"

SkillTreeNode::SkillTreeNode()
{

}

void SkillTreeNode::Draw(Renderer& render, int centerX, int centerY, Color color) const
{
	render.DrawNodeCircle(centerX, centerY, color);
}
