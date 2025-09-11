#include "UIButton.h"

UIButton::UIButton() : x(0), y(0), width(100), height(50), align(TextAlign::Center), size(TextSize::Button01) {}

UIButton::UIButton(const std::string& label, int x, int y, int width, int height,
    TextAlign align, TextSize size)
    : label(label), x(x), y(y), width(width), height(height), align(align), size(size)
{
}

void UIButton::Draw(Renderer& render, Color color) const
{
    int paddingHeight = render.GetPaddingHeight(label, size, width);
    // Draw the button background rectangle
    render.DrawRectangle(x, y, width, paddingHeight, color);
    // Draw the text on top
    render.DrawTextBlockNoPadding(label, x, y, width, align, size);

}

bool UIButton::IsHovered(Renderer& render) const
{
    Rectangle bounds = GetBounds(render);
    return CheckCollisionPointRec(GetMousePosition(), bounds);
}

bool UIButton::IsClicked(Renderer& render) const
{
    return IsHovered(render) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

Rectangle UIButton::GetBounds(Renderer& render) const
{
    int paddingHeight = render.GetPaddingHeight(label, size, width);

    return { static_cast<float>(x), static_cast<float>(y),
             static_cast<float>(width), static_cast<float>(paddingHeight) };
}