#include "UIButton.h"

UIButton::UIButton() : x(0), y(0), width(100), height(50), align(TextAlign::Center), size(TextSize::Button01) {}

UIButton::UIButton(const std::string& label, int x, int y, int width, int height,
    TextAlign align, TextSize size)
    : label(label), x(x), y(y), width(width), height(height), align(align), size(size)
{
}

UIButton::UIButton(const std::string& label, int x, int y, int width, int height, TextAlign align, TextSize size, int& incrementValue, int& decrementValue)
    : label(label), x(x), y(y), width(width), height(height), align(align), size(size), incrementValue(incrementValue), decrementValue(decrementValue)
{
}

Rectangle UIButton::GetRect() const
{
    Rectangle rec = { x, y, width, height };
    return rec;
}

void UIButton::Draw(Renderer& render, Color color) const
{
    int paddingHeight = render.GetPaddingHeight(label, size, width);
    // Draw the button background rectangle
    render.DrawRectangle(x, y, width, paddingHeight, color);
    // Draw the text on top
    render.DrawTextBlockNoPadding(label, x, y, width, align, size);
}

void UIButton::DrawFreeRec(Renderer& render, Color color) const
{
    render.DrawRectangle(x, y, width, height, color);
    render.DrawTextBlockNoPadding(label, x, y, width, align, size);
}

bool UIButton::IsHovered(Renderer& render, bool isFree) const
{
    Rectangle bounds = GetBounds(render, isFree);
    return CheckCollisionPointRec(GetMousePosition(), bounds);
}



bool UIButton::IsClicked(Renderer& render, bool isFree) const
{
    return IsHovered(render, isFree) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void UIButton::Increment(int incrementValue)
{
    incrementValue++;
}

void UIButton::Decrement(int decrementValue)
{
    decrementValue++;
}

void UIButton::IncrementDecrement(int incrementValue, int decrementValue)
{
    incrementValue++;
    decrementValue++;
}

Rectangle UIButton::GetBounds(Renderer& render, bool isFree) const
{
    if (!isFree)
    {
        int paddingHeight = render.GetPaddingHeight(label, size, width);

        return { static_cast<float>(x), static_cast<float>(y),
                 static_cast<float>(width), static_cast<float>(paddingHeight) };
    }
    else
    {
        return { static_cast<float>(x), static_cast<float>(y),
                 static_cast<float>(width), static_cast<float>(height) };
    }

}