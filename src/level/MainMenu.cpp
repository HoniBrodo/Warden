#include "MainMenu.h"

void MainMenu::Run(Renderer& renderRef, bool& gameRunning)
{
    Renderer render = renderRef;
    BeginDrawing();
    ClearBackground(BLACK);
    InitButtons(render);

    if (IsKeyDown(KEY_G))
    {
        render.DrawGrid(true);
    }

    render.DrawTextBlock
    (
        "WARDEN", 
        render.TextScreenCenterX(700), 
        render.GridY(3), 
        700, 
        TextAlign::Center, 
        TextSize::MainTitle
    );

    render.DrawTextBlock
    (
        "Based on the Sci-fi Horror TTRPG 'Mothership' Written by Sean McCoy and Published by Tuesday Night Games", 
        render.TextScreenCenterX(1000), 
        render.GridY(7), 
        1000, 
        TextAlign::Center, 
        TextSize::Dialogue
    );

    startButton.Draw(render, startButtonColor);
    exitButton.Draw(render, exitButtonColor);

    // start button logic
    if (startButton.IsClicked(render)) {
        stateManager.SetState(StateManager::GameState::CHARATER_CREATOR);
    }

    if (startButton.IsHovered(render)) {
        startButtonColor = GRAY;
    }
    else startButtonColor = LIGHTGRAY;

    // exit button logic
    if (exitButton.IsClicked(render)) {
        gameRunning = false;
    }

    if (exitButton.IsHovered(render)) {
        exitButtonColor = GRAY;
    }
    else exitButtonColor = LIGHTGRAY;



    EndDrawing();
}

// a future task is to set up a constructor for UIButton objects, so they can be initialized as they are created

void MainMenu::InitButtons(Renderer& renderRef)
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



