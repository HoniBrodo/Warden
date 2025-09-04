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

    void Draw(Renderer& render) const;
    bool IsHovered() const;
    bool IsClicked() const;

private:
    std::string label;
    int x, y;
    int width, height;
    TextAlign align;
    TextSize size;
    

    Rectangle GetBounds() const;
};