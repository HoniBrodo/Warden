#pragma once
#include "raylib.h"
#include <string>
#include <vector>

class Renderer {
public:
    Renderer();
    Renderer(int cols, int rows, int screenWidth, int screenHeight);
    ~Renderer();

    Font font = GetFontDefault();

    int fontSize = 30;
    int rowHeight = fontSize + fontSize / 2;
    int lineStart = fontSize;
    int lineSpacing = fontSize * 1.33;
    int indent = fontSize * 0.66;

    Color textColor = DARKGREEN;

    float GridX(int gx) const;
    float GridY(int gy) const;
    void DrawGrid(bool showCoords = false) const;
    void SetScreenSize(int width, int height);
    void SetGrid(int cols, int rows);
    void DrawTextCentred(const std::string& text, int posY, int fontSize, Color color);
    void DrawTextAlignLeft(const std::string& text, int posY, int fontSize, Color color);
    void DrawTextBlock(const std::string& text, int posX, int posY, int maxWidth);

private:

    int cols = 20;
    int rows = 20;
    float cellWidth{};
    float cellHeight{};
    int screenWidth{};
    int screenHeight{};
    void UpdateCellSize();

    std::vector<std::string> WrapText(const std::string& text, int maxWidth);


};