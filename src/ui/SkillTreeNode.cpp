#include "SkillTreeNode.h"



SkillTreeNode::SkillTreeNode(SkillLevel level)
{
    skillLevel = level;
}

SkillTreeNode::SkillTreeNode()
{
}

void SkillTreeNode::Draw(Renderer& render, int centerX, int centerY, int innerCircleSize, int outerCircleSize, std::string label)
{
	cenX = centerX;
	cenY = centerY;

    bool hovered = IsHovered();
    float scale = hovered ? 1.2f : 1.0f;

	switch (nodeAvailability)
	{
		case NodeAvailability::AVAILABLE:
		{
			nodeColor = DARKGREEN;

			break;
		}

		case NodeAvailability::UNAVAILABLE:
		{
			nodeColor = RED;

			break;
		}

		case NodeAvailability::SELECTED:
		{
			nodeColor = WHITE;

			break;
		}

		case NodeAvailability::MANDATORY:
		{
			nodeColor = BLACK;

			break;
		}

	}

	render.DrawNodeCircle(centerX, centerY - 10, innerCircleSize * scale, outerCircleSize * scale, nodeColor);

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

	if (isTransparent)
	{
		switch (skillLevel)
		{
		case SkillLevel::TRAINED:
			background = { 102, 191, 255, 20 };
			break;
		case SkillLevel::EXPERT:
			background = { 255, 161, 0, 20 };
			break;
		case SkillLevel::MASTER:
			background = { 255, 0, 255, 20 };
			break;
		default:
			background;
			break;
		}

		tint = Fade(WHITE, 0.2f);
	}

	render.DrawSkillTreeIcon(image, pos, rotation, scale, tint, background);
}

void SkillTreeNode::SetNodeAvailability(const std::string& availability)
{
	static const std::unordered_map<std::string, NodeAvailability> lookup = {
		{"available",   NodeAvailability::AVAILABLE},
		{"unavailable", NodeAvailability::UNAVAILABLE},
		{"selected",    NodeAvailability::SELECTED},
		{"mandatory",   NodeAvailability::MANDATORY},
	};

	auto it = lookup.find(availability);
	nodeAvailability = (it != lookup.end())
		? it->second
		: NodeAvailability::AVAILABLE; // default

	/*
	note to future self... I'm struggling to make sense of this. Here is a longer form of the same code,
	for visualisation purposes...

	auto it = lookup.find(availability);

	if (it != lookup.end())
	{
		nodeAvailability = it->second; // use mapped enum
	}
	else
	{
		nodeAvailability = NodeAvailability::AVAILABLE; // default
	}

	*/
}



