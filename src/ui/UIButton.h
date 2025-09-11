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
    bool IsHovered(Renderer& render) const;
    bool IsClicked(Renderer& render) const;

private:
    std::string label;
    int x, y;
    int width, height;
    TextAlign align;
    TextSize size;
    

    Rectangle GetBounds(Renderer& render) const;
};