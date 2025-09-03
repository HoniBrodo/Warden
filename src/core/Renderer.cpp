#include "Renderer.h"
#include <sstream>

Renderer::Renderer() 
{
	UpdateCellSize();
}

Renderer::Renderer(int cols, int rows, int screenWidth, int screenHeight)
	: cols(cols), rows(rows), screenWidth(screenWidth), screenHeight(screenHeight)
{
	UpdateCellSize();
}

Renderer::~Renderer() {}

float Renderer::GridX(int gx) const
{
	return gx * cellWidth;
}

float Renderer::GridY(int gy) const
{
	return gy * cellHeight;
}

void Renderer::DrawGrid(bool showCoords) const
{
	for (int x = 0; x <= cols; x++)
	{
		DrawLine((int)GridX(x), 0, (int)GridX(x), screenHeight, LIGHTGRAY);
	}
	for (int y = 0; y <= rows; y++)
	{
		DrawLine(0, (int)GridY(y), screenWidth, (int)GridY(y), LIGHTGRAY);
	}
	if (showCoords)
	{
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < cols; x++)
			{
				std::string coord = std::to_string(x) + "," + std::to_string(y);
				DrawText(coord.c_str(), (int)GridX(x) + 2, (int)GridY(y) + 2, 20, LIGHTGRAY);
			}
		}
	}
}

void Renderer::SetScreenSize(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
	UpdateCellSize();
}

void Renderer::SetGrid(int cols, int rows)
{
	this->cols = cols;
	this->rows = rows;
	UpdateCellSize();
}

void Renderer::DrawTextCentred(const std::string& text, int posY, int fontSize, Color color)
{
	int textWidth = MeasureText(text.c_str(), fontSize);
	int posX = (screenWidth - textWidth) / 2;
	DrawText(text.c_str(), posX, posY, fontSize, color);
}

void Renderer::DrawTextAlignLeft(const std::string& text, int posY, int fontSize, Color color)
{
		int posX = indent;
		DrawText(text.c_str(), posX, posY, fontSize, color);
}

void Renderer::DrawTextBlock(const std::string& text, int posX, int posY)
{
	int textWidth = MeasureText(text.c_str(), fontSize);
	Rectangle textPadding{ posX, posY, textWidth + fontSize * 2, fontSize * 2 };
	DrawRectangleRec(textPadding, LIGHTGRAY);
	DrawText(text.c_str(), posX + fontSize, posY + fontSize / 2, fontSize, textColor);
}


void Renderer::UpdateCellSize()
{
	cellWidth = (float)screenWidth / cols;
	cellHeight = (float)screenHeight / rows;
}

std::vector<std::string> Renderer::WrapText(const Font& font, const std::string& text, int fontSize, float maxWidth, float spacing)
{
	std::vector<std::string> lines;
	std::istringstream iss(text);
	std::string word;
	std::string currentLine;

	return std::vector<std::string>();
}
