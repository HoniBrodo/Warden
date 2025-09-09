#include "MainMenu.h"

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::Run()
{
    BeginDrawing();
    ClearBackground(BLACK);
    InitMenuButtons();
    if (IsKeyDown(KEY_G))
    {
        render.DrawGrid(true);
    }
    render.DrawTextBlock("WARDEN", render.TextScreenCenterX(700), render.GridY(3), 700, TextAlign::Center, TextSize::MainTitle);
    render.DrawTextBlock("Based on the Sci-fi Horror TTRPG 'Mothership' Written by Sean McCoy and Published by Tuesday Night Games", render.TextScreenCenterX(1000), render.GridY(7), 1000, TextAlign::Center, TextSize::Dialogue);
    startButton.Draw(render);
    exitButton.Draw(render);


    EndDrawing();
}

void MainMenu::InitMenuButtons()
{
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



