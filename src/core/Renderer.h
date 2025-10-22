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
    Button02,
    Button01,
    Dialogue,
    SmallerTitle,
    MenuSmall
};

struct DebugRect {
    Rectangle rect;
    bool visible = false; // only drawn if toggled on
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
    void DrawRectangleWithBorder(int posX, int posY, int width, int height, Color fillColor, Color borderColor, int borderThickness);
    void DrawTextBlock(const std::string& text, int posX, int posY, int maxWidth, TextAlign alignment, TextSize size);
    void DrawTextBlockNoPadding(const std::string& text, int posX, int posY, int maxWidth, TextAlign alignment, TextSize size);
    void DrawTextListInRect(const std::vector<std::string>& items, const Rectangle rect, TextAlign alignment, TextSize size, float yOffset);
    int GetFontSize(TextSize size) const;
    int ScreenCenterX() { return screenWidth / 2; }
    int TextScreenCenterX(int paddingWidth) { return (screenWidth / 2) - (paddingWidth / 2); }
    int GetPaddingHeight(const std::string& text, TextSize size, int maxWidth);

    int AlignCenterXInRect(const DebugRect& container, int contentWidth) const;
    void DrawDebugRect(const DebugRect& container, Color color = RED) const;

    void DrawPipsGrid(int filledCount, int startX, int startY);

private:

    TextureManager& textureManager;
    int cols = 20;
    int rows = 20;
    float cellWidth{};
    float cellHeight{};
    int screenWidth{};
    int screenHeight{};
    void UpdateCellSize();

    static constexpr int GRID_ROWS = 2;
    static constexpr int GRID_COLS = 4;
    static constexpr int MAX_FILLED = 8;
    static constexpr int MIN_FILLED = 0;

    std::vector<std::string> WrapText(const std::string& text, int maxWidth, int fontSize);


};