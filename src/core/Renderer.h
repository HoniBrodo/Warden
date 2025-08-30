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

    void DrawTextCentred(const std::string& text, int posY, int fontSize, Color color);
    int TextRow(int row);

private: 
    
};