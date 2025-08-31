#pragma once
#include "raylib.h"
#include <string>

class Renderer {
public:
    Renderer();
    ~Renderer();

    int fontSize = 20;
    int rowHeight = fontSize + fontSize / 2;
    int lineStart = fontSize;
    int leftBorderIndent = 20;

    void DrawTextCentred(const std::string& text, int posY, int fontSize, Color color);
    void DrawTextAlignLeft(const std::string& text, int posY, int fontSize, Color color);
    void DrawTextBlock(const std::string& text);
    int TextRow(int row);

private: 
    
};