#include "MainMenu.h"

void MainMenu::Run(Renderer& renderRef)
{
    Renderer render = renderRef;
    BeginDrawing();
    ClearBackground(BLACK);
    InitMenuButtons(render);
    if (IsKeyDown(KEY_G))
    {
        render.DrawGrid(true);
    }

    render.DrawTextBlock("WARDEN", render.TextScreenCenterX(700), render.GridY(3), 700, TextAlign::Center, TextSize::MainTitle);
    render.DrawTextBlock("Based on the Sci-fi Horror TTRPG 'Mothership' Written by Sean McCoy and Published by Tuesday Night Games", render.TextScreenCenterX(1000), render.GridY(7), 1000, TextAlign::Center, TextSize::Dialogue);
    startButton.Draw(render);
    exitButton.Draw(render);

    if (startButton.IsClicked()) {
        stateManager.SetState(StateManager::GameState::DEBUG_WINDOW);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        stateManager.SetState(StateManager::GameState::DEBUG_WINDOW);
    }

    EndDrawing();
}

void MainMenu::InitMenuButtons(Renderer& renderRef)
{
    Renderer render = renderRef;
    startButton = UIButton(
        "Start",
        render.TextScreenCenterX(300) - 250,
        render.GridY(11),
        300, 120,                   // width & height
        TextAlign::Center,
        TextSize::Button01
    );

    exitButton = UIButton(
        "Exit",
        render.TextScreenCenterX(300) + 250,
        render.GridY(11),
        300, 120,                   // width & height
        TextAlign::Center,
        TextSize::Button01
    );
}



