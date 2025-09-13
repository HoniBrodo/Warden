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
    InitButtons(render);


    render.DrawTextBlock
    (
        "Debug Level",
        render.TextScreenCenterX(300),
        render.GridY(1),
        300,
        TextAlign::Center,
        TextSize::Dialogue
    );

    testButton01.Draw(render, testButton01Color);

    if (testButton01.IsHovered(render)) {
        testButton01Color = GRAY;
    }
    else testButton01Color = LIGHTGRAY;
     
    if (testButton01.IsClicked(render))
    {
        stateManager.SetState(StateManager::GameState::MAIN_MENU);
    }

    EndDrawing();
}

void DebugLevel::InitButtons(Renderer& renderRef)
{
    Renderer render = renderRef;

    testButton01 = UIButton(
        "This is a test button in the center of the screeen, testing testing testing",
        render.TextScreenCenterX(1200),
        render.GridY(5),
        1200, 120,                  
        TextAlign::Center,
        TextSize::Button01
    );
}
