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

    Rectangle GetRect() const;
    void Draw(Renderer& render, Color color) const;
    void DrawFreeRec(Renderer& render, Color color) const;
    bool IsHovered(Renderer& render, bool isFree) const;
    bool IsClicked(Renderer& render, bool isFree) const;
    void Increment(int incrementValue);
    void Decrement(int decrementValue);
    void IncrementDecrement(int incrementValue, int decrementValue);

private:
    // these variables are being referenced in the constructor but are never being used (I think)
    std::string label;
    int x, y;
    int width, height;
    TextAlign align;
    TextSize size;

    bool isFreeRec = false; // maybe don't need this?
    

    Rectangle GetBounds(Renderer& render, bool isFree) const;
};