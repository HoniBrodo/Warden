#pragma once
#include <string>
#include "../core/Renderer.h"
#include "raylib.h" 


class UIButton
{
public:
    UIButton();
    UIButton(const std::string& label, int x, int y, int width, int height,
        TextAlign align, TextSize size);

    void Draw(Renderer& render, Color color) const;
    void DrawFreeRec(Renderer& render, Color color) const;
    bool IsHovered(Renderer& render, bool isFree) const;
    bool IsClicked(Renderer& render, bool isFree) const;

private:
    std::string label;
    int x, y;
    int width, height;
    TextAlign align;
    TextSize size;
    bool isFreeRec; // maybe don't need this?
    

    Rectangle GetBounds(Renderer& render, bool isFree) const;
};