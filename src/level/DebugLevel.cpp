#include "DebugLevel.h"

void DebugLevel::Run(Renderer& renderRef)
{
    Renderer render = renderRef;

    if (IsKeyDown(KEY_G))
    {
        render.DrawGrid(true);
    }

    BeginDrawing();
    ClearBackground(BLACK);
    render.DrawTextBlock("Debug Level",
        render.GridX(10.2), render.GridY(1),
        300, TextAlign::Center, TextSize::Dialogue);
    EndDrawing();
}
