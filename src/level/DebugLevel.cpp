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
    InitDebugLevelButtons(render);


    render.DrawTextBlock
    (
        "Debug Level",
        render.TextScreenCenterX(300),
        render.GridY(1),
        300,
        TextAlign::Center,
        TextSize::Dialogue
    );

    testButton01.Draw(render, GREEN);

    EndDrawing();
}

void DebugLevel::InitDebugLevelButtons(Renderer& renderRef)
{
    Renderer render = renderRef;

    testButton01 = UIButton(
        "This is a test button in the center of the screeen, testing testing testing",
        render.TextScreenCenterX(1200),
        render.GridY(5),
        1200, 120,                   // width & height
        TextAlign::Center,
        TextSize::Button01
    );
}
