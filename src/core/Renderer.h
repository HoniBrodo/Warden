#pragma once
#include "raylib.h"
#include <string>
#include <vector>

enum class TextAlign
{
    Left,
    Center
};

enum class TextSize
{
    MainTitle,
    Dialogue
};

class Renderer {
public:
    Renderer();
    Renderer(int cols, int rows, int screenWidth, int screenHeight);
    ~Renderer();

    Font font = GetFontDefault();
    Color textColor = DARKGREEN;

    float GridX(int gx) const;
    float GridY(int gy) const;
    void DrawGrid(bool showCoords = false) const;
    void SetScreenSize(int width, int height);
    void SetGrid(int cols, int rows);
    void DrawTextBlock(const std::string& text, int posX, int posY, int maxWidth, TextAlign alignment, TextSize size);
    int GetFontSize(TextSize size) const;

private:

    int cols = 20;
    int rows = 20;
    float cellWidth{};
    float cellHeight{};
    int screenWidth{};
    int screenHeight{};
    void UpdateCellSize();

    std::vector<std::string> WrapText(const std::string& text, int maxWidth, int fontSize);


};