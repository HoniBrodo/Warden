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

void Renderer::DrawTextBlock(const std::string& text, int posX, int posY, int maxWidth)
{
	std::vector<std::string> wrappedText = WrapText(text, maxWidth);
	//int textWidth = MeasureText(text.c_str(), fontSize);
	Rectangle textPadding{ posX, posY, maxWidth + fontSize * 2, fontSize * 2 };
	DrawRectangleRec(textPadding, LIGHTGRAY);
	// to do: write a bespoke DrawText function that loops through the 'wrappedText' vector and prints all of the strings
	DrawText(wrappedText[0].c_str(), posX + fontSize, posY + fontSize / 2, fontSize, textColor); 
}


void Renderer::UpdateCellSize()
{
	cellWidth = (float)screenWidth / cols;
	cellHeight = (float)screenHeight / rows;
}

std::vector<std::string> Renderer::WrapText(const std::string& text, int maxWidth)
{
	std::vector<std::string> lines;
	std::istringstream iss(text);
	std::string word;
	std::string currentLine;

	while (iss >> word) // this will loop through each word in the input text. If there is a word, it will return true and 
	//we can use it. If we run out of words (reach the end of the string), it will return false and the while loop will end.
	{
		// if currentLine is empty, start a new line with the current word, if not, append to the end. 
		std::string testLine = currentLine.empty() ? word : currentLine + " " + word;
		// this if/else statement will measure the size of the string so far and compare it to a max width
		int lineWidth = MeasureText(testLine.c_str(), fontSize);
		if (lineWidth > maxWidth)
		{
		// if currentLine has text, push it into the lines vector (its now a completed line). It could be 
		// possible that the first word was already too long, this check avoids adding empty line unnecessarily
			if (!currentLine.empty()) lines.push_back(currentLine);
			// start a new line with the word that didn't fit
			currentLine = word;
		}
		else
			// if it does fit, update currentLine to include it (testLine already has currentLine + " " + word)
		{
			currentLine = testLine;
		}
	}
	// If there’s any leftover text after the loop, save it as the last line. Then return the full list of lines.
	if (!currentLine.empty()) lines.push_back(currentLine);
	return lines;
}
