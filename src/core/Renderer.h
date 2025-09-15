#pragma once
#include "raylib.h"
#include <string>
#include <vector>


class TextureManager;

enum class TextAlign
{
    Left,
    Center
};

enum class TextSize
{
    MainTitle,
    Button01,
    Dialogue,
    SmallerTitle
};

class Renderer {
public:
    Renderer(TextureManager& tm, int cols, int rows, int screenWidth, int screenHeight);
    ~Renderer();

    Font font = GetFontDefault();
    Color textColor = DARKGREEN;

    float GridX(int gx) const;
    float GridY(int gy) const;
    void DrawLoadedTexture(std::string image, Vector2 pos, float rotation, float scale, Color tint );
    void DrawGrid(bool showCoords = false) const;
    void SetScreenSize(int width, int height);
    void SetGrid(int cols, int rows);
    void DrawRectangle(int x, int y, int width, int height, Color color);
    void DrawTextBlock(const std::string& text, int posX, int posY, int maxWidth, TextAlign alignment, TextSize size);
    void DrawTextBlockNoPadding(const std::string& text, int posX, int posY, int maxWidth, TextAlign alignment, TextSize size);
    int GetFontSize(TextSize size) const;
    int ScreenCenterX() { return screenWidth / 2; }
    int TextScreenCenterX(int paddingWidth) { return (screenWidth / 2) - (paddingWidth / 2); }
    int GetPaddingHeight(const std::string& text, TextSize size, int maxWidth);


private:


    TextureManager& textureManager;
    int cols = 20;
    int rows = 20;
    float cellWidth{};
    float cellHeight{};
    int screenWidth{};
    int screenHeight{};
    void UpdateCellSize();

    std::vector<std::string> WrapText(const std::string& text, int maxWidth, int fontSize);


};