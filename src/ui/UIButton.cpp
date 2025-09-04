#include "UIButton.h"

UIButton::UIButton() : x(0), y(0), width(100), height(50), align(TextAlign::Center), size(TextSize::Button01) {}

UIButton::UIButton(const std::string& label, int x, int y, int width, int height,
    TextAlign align, TextSize size)
    : label(label), x(x), y(y), width(width), height(height), align(align), size(size)
{
}

void UIButton::Draw(Renderer& render) const
{
    // Draw the button background rectangle
    render.DrawRectangle(x, y, width, height, BLUE);  // Or any colour you like

    // Draw the text on top
    render.DrawTextBlock(label, x, y, width, align, size); // this is where the problem is
}

bool UIButton::IsHovered() const
{
    Rectangle bounds = GetBounds();
    return CheckCollisionPointRec(GetMousePosition(), bounds);
}

bool UIButton::IsClicked() const
{
    return IsHovered() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

Rectangle UIButton::GetBounds() const
{
    return { static_cast<float>(x), static_cast<float>(y),
             static_cast<float>(width), static_cast<float>(height) };
}