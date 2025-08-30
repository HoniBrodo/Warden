#include "Renderer.h"

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::DrawTextCentred(const std::string& text, int posY, int fontSize, Color color)
{
	int screenWidth = GetScreenWidth();
	int textWidth = MeasureText(text.c_str(), fontSize);
	int posX = (screenWidth - textWidth) / 2;
	DrawText(text.c_str(), posX, posY, fontSize, color);
}

int Renderer::TextRow(int row)
{
	return lineStart + row * rowHeight;
}
